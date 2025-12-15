#include "Server.h"

Server::Server(const std::string &ip, int port) : ip(ip), port(port)
{
}

void Server::run()
{
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening < 0)
    {
        throw std::runtime_error("cannot create socket");
    }

    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    // convert string represntation of ip into bytes
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

    bind(listening, (sockaddr *)&hint, sizeof(hint));
    listen(listening, SOMAXCONN);

    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);

    while (true)
    {

        int clientSocket = accept(listening, (sockaddr *)&client, &clientSize);

        {
            std::lock_guard<std::mutex> lock(clientMutex);
            activeConnections.insert(clientSocket);
        }

        threads.push_back(std::thread(&Server::handleClient, this, clientSocket));
        threads.back().detach();
    }
    closesocket(listening);
}

void Server::handleClient(int clientSocket)
{
    char buffer[4096];
    while (true)
    {
        memset(buffer, 0, 4096);
        int bytesReceived = recv(clientSocket, buffer, 4096, 0);
        if (bytesReceived <= 0) // when client disconnects, server stops listening
            break;

        std::string msg(buffer, bytesReceived);
        std::cout << "Client: " << msg << std::endl;

        {
            std::lock_guard<std::mutex> lock(clientMutex);
            for (int socket : activeConnections)
            {
                if (socket != clientSocket) // send to all others
                    send(socket, buffer, bytesReceived, 0);
            }
        }
    }

    std::lock_guard<std::mutex> lock(clientMutex);
    activeConnections.erase(clientSocket);

    closesocket(clientSocket);
}
