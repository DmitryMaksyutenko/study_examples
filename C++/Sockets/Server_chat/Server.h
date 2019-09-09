#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <string>
#include <iostream>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

class Server
{
    private:
        WSADATA wsaData;
        SOCKET listenSock;
        SOCKET clients[3];
        SOCKET sendSock;
        fd_set readFdSet; // Set of socket descriptors
        sockaddr_in socAddrIn;
        unsigned short port;
        int maxClients;

    public:
        Server() :
            wsaData{NULL}, 
            listenSock{INVALID_SOCKET},
            sendSock{INVALID_SOCKET},
            readFdSet{},
            port{27001},
            maxClients{3} {}
        Server(unsigned int size) :
            wsaData{NULL}, 
            listenSock{INVALID_SOCKET},
            sendSock{INVALID_SOCKET},
            readFdSet{},
            port{27001},
            maxClients{3} {}

        std::string GetIp() const;
        void BuildServer();
        void Runserver();
        void CloseServer();
};