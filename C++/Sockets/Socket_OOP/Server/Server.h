#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

#define buf_len 512

class Server
{
    private:
        int iResult;
        int iSendResult;
        const char port[6];
        char receive_buf[buf_len];
        WSADATA wsa_data;
        SOCKET listenSocket;
        SOCKET clientSocket;
        struct addrinfo *result, hints;

    public:
        Server();
        bool WsaInit();
        bool ResolveAddrPort();
        bool CreateListenSocket();
        bool SetupTCPListenSocket();
        bool SetMaxBacklog();
        bool AcceptClientSocket();
        bool ReceiveMessages();      
        bool ShatdownConnection();
};