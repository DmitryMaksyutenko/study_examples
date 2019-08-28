#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>

#define DEFAULT_BUFLEN 512 

class Client
{
    private:
        int iResult;
        char receive_buf[DEFAULT_BUFLEN];
        char *send_buf;
        char *port;
        WSADATA wsa_data;
        SOCKET clientSocket;
        struct addrinfo *result, *ptr, hints;


    public:
        Client();
        bool WinsockInit();
        bool ResolveAddrPort(char **argv);
        bool Connect();
        bool MessSend();
        bool ShotDown();
        void Receive();
};