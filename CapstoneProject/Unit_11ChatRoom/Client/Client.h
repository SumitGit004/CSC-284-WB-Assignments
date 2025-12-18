#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <mutex>
#include <thread>
#include <functional>
#include <queue>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close


class Client{

    private:
    int sock;
    std::thread receivingThread;
    std::atomic <bool> running{false};
    
    //function as a callback to send message back to UI
    std::function<void(const std::string&)> onMessage;

     public:

    Client() = default;
    
    ~Client();

    bool connectToServer(const std::string &ip, int port);

    void sendMessage(const std::string& input);

    void startReceiving(std::function<void (const std::string&)> callback);

    void receiveMessage();

    bool isRunning();

    void disconnect();

};