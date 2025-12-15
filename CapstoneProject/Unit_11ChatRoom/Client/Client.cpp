#include "Client.h"

 Client::~Client() {
        disconnect();
    }

    bool Client::connectToServer(const std::string &ip, int port){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serverHint{};
        serverHint.sin_family = AF_INET;
        serverHint.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serverHint.sin_addr);

        int conn = connect(sock, (sockaddr *)&serverHint, sizeof(serverHint));
        if (conn < 0)
        {
        close(sock);
        return false;
        }
      
       running = true;

       return true;
    }

    void Client::sendMessage(const std::string& input){
        if(running)
        send(sock, input.c_str(), input.size(), 0);
    }

    void Client::startReceiving(std::function<void (const std::string&)> callback){
        onMessage = callback;//store the callback
        receivingThread = std::thread(&Client::receiveMessage, this);
    }

    void Client::receiveMessage(){
        
        char buffer[4096];
        
        while (running){
        memset(buffer, 0, 4096);
        int bytesReceived = recv(sock, buffer, 4096, 0);

        if (bytesReceived > 0){
             if(onMessage)
             onMessage(std::string(buffer, bytesReceived));
        }
        else{
            running = false;
        break;
        }
    }
        

    }

    void Client::disconnect() {
            
        running = false;
        shutdown(sock, SHUT_RDWR);//stop sending / receving 
        close(sock);

           if (receivingThread.joinable())
            receivingThread.join();
    }

