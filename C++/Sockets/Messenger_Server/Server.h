#ifndef __SERVER_H__
#define __SERVER_H__

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27001"
#define DEFAULT_BUF 1024

class Server { 
    
    private: 
        int iResult; 
        WSADATA wsa_data;
        SOCKET server_socket;
        struct addrinfo *result; 
        struct addrinfo hints;
        char message_buf[DEFAULT_BUF];

        void BuildSocket();
        void ListenLoop();
        void GetMessasge();
        void ResendMessage();

    public:
        Server();
        void RunServer();
        void StopServer();
        int GetClientsCount();
        std::string GetServerIP();
};

#endif 