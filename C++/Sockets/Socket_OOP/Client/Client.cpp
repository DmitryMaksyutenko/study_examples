#include "Client.h"

Client::Client() : port("27015"), send_buf("message"), clientSocket(INVALID_SOCKET), 
                    iResult(NULL), result(NULL), ptr(NULL)
{
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
}

bool Client::WinsockInit()
{
    iResult = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if(iResult !=0)
    {
        std::cout << "WSAStartup failed " << iResult << std::endl;
        return false;
    }
    std::cout << "WSAStartup success " <<  iResult << std::endl;
    return true;
}
        
bool Client::ResolveAddrPort(char **argv)
{
    iResult = getaddrinfo(argv[1], port, &hints, &result);
    if (iResult != 0)
    {
        std::cout << "geraddrinfo failed " << iResult << std::endl;
        WSACleanup();
        return false;
    }
    return true;
}

bool Client::Connect()
{
    for (ptr = result; ptr != NULL; ptr->ai_next)
    {
        clientSocket = socket(ptr->ai_family, ptr->ai_socktype, (int)ptr->ai_protocol);
        if (clientSocket == INVALID_SOCKET)
        {
           std::cout << "socket failed " << clientSocket << std::endl;
           WSACleanup();
           return false;
        }

        iResult = connect(clientSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR)
        {
            std::cout << "connection error " << iResult << std::endl;
            closesocket(clientSocket);
            clientSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);
    return true;
}

bool Client::MessSend()
{
    if (clientSocket == INVALID_SOCKET)
    {
        std::cout << "unable to connect" << std::endl;
        WSACleanup();
        return false;
    }

    iResult = send(clientSocket, send_buf, (int)strlen(send_buf), 0);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "send error " << iResult << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return false;
    }

    return true;
}

bool Client::ShotDown()
{
    iResult = shutdown(clientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "shutdown failed " << iResult << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return false;
    }
    return true;
}

void Client::Receive()
{
    do
    {
        iResult = recv(clientSocket, receive_buf, DEFAULT_BUFLEN, 0);
        if (iResult > 0)
            std::cout << "received = " << iResult << std::endl;
        else if (iResult == 0)
            std::cout << "close connection " << std::endl;
        else
            std::cout << "recv failed" << std::endl;
    }
    while(iResult > 0);

    closesocket(clientSocket);
    WSACleanup();
}