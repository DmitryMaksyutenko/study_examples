#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 1024

class Client
{
    private:
        int iResult;
        WSADATA wsa_data;
        SOCKET client_socket;
        addrinfo *result, *ptr, hints;

    public:
        Client();
        void BuildClient();
        void SendMessage();

};