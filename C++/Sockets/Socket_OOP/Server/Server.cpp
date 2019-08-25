#include "Server.h"

Server::Server() : port("27015")
{
    iResult = NULL;
    iSendResult = NULL;
    listenSocket = INVALID_SOCKET;
    clientSocket = INVALID_SOCKET;
    result = NULL;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
}
        
bool Server::WsaInit()
{
    iResult = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if(iResult != 0)
    {
        std::cout << "WSAStartup failed " << iResult << std::endl;
        return false;
    }
    std::cout << "WSAStartaup Success " << iResult << std::endl;
    return true;
}
        
bool Server::ResolveAddrPort()
{
    iResult = getaddrinfo(NULL, port, &hints, &result);
    if (iResult != 0)
    {
        std::cout << "getaddrinfo failed!" << iResult << std::endl;
        return false;
    }
    std::cout << "geraddrinfo Success " << iResult << std::endl;
    return true;
}

bool Server::CreateListenSocket()
{
    listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listenSocket == INVALID_SOCKET)
    {
        std::cout << "listenSocket create failed " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(listenSocket);
        WSACleanup();
        return false;
    }
    std::cout << "listenSocket create success " << listenSocket << std::endl;
    return true;
}

bool Server::SetupTCPListenSocket()
{
    iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "bind failed " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(listenSocket);
        WSACleanup();
        return false;
    }
    std::cout << "bind success " << iResult << std::endl;
    freeaddrinfo(result);
    return true;
}

bool Server::SetMaxBacklog()
{
    iResult = listen(listenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "listen failed " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return false;
    }
    std::cout << "listen success " << iResult << std::endl;
    return true;
}

bool Server::AcceptClientSocket()
{
    clientSocket = accept(listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cout << "accept failed " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return false;
    }
    std::cout << "accept succes " << clientSocket << std::endl;
    closesocket(listenSocket);
    return true;
}

bool Server::ReceiveMessages()
{
    do
    {
        std::cout << ".";
        iResult = recv(clientSocket, receive_buf, buf_len, 0);
        if (iResult > 0)
        {
            std::cout << "received : " << iResult;
            iSendResult = send(clientSocket, receive_buf, buf_len, 0);
            if (iSendResult == SOCKET_ERROR)
            {
                std::cout << "sending failed " << WSAGetLastError() << std::endl;
                closesocket(clientSocket);
                WSACleanup();
                return false;
            }
            std::cout << "send : " << iSendResult << std::endl;
        }
        else if (iResult == 0)
            std::cout << "connection clising" << std::endl;
        else 
        {
            std::cout << "receive failed " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            return false;
        }
    }
    while(iResult > 0);

    return true;   
}

bool Server::ShatdownConnection()
{
    iResult = shutdown(clientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "shatdown failed " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return false;
    }

    closesocket(clientSocket);
    WSACleanup();
    return true;
}