#include <iostream>
#include <string>
#include <cstring>
#include "Server.h"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close

int main(int args, char* argv[]){
    
    std::string ip = "127.0.0.1";
    int port = 54000;
     
    if(args == 2)
    ip = argv[1];
     
    else if(args == 3){
    ip = argv[1];
    port = std::stoi(argv[2]);
    }

    Server server(ip, port);
    server.run();

    return 0;
}

