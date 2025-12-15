#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <set>
#include <mutex>
#include <vector>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close

class Server{
    private:
    std::vector<std::thread> threads;
    std::set<int> activeConnections;
    std::mutex clientMutex;
    std::string ip ;
    int port = 54000;


    public:
    Server() = default;

    Server(const std::string& ip, int port);

    void run();

    void handleClient(int clientSocket);

};