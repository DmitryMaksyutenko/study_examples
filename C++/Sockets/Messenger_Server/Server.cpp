#include "Server.h"

Server::Server()  
{
    iResult = 0;
    server_socket = INVALID_SOCKET;
    result = NULL;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
}

void Server::BuildSocket()
{
    iResult = WSAStartup(MAKEWORD(2, 2),&wsa_data);
    if (iResult != 0)
    {
        throw std::exception("WSAStartup failed\n");
    }

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0)
    {
        WSACleanup();
        throw std::exception("failed geraddrinfo\n");
    }

    server_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (server_socket == INVALID_SOCKET)
    {
        freeaddrinfo(result);
        WSACleanup();
        throw std::exception("socket failed\n");
    }
  
    iResult = bind(server_socket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult != 0)
    {
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        throw std::exception("binding failed\n");
    }

   freeaddrinfo(result);
}

void Server::ListenLoop()
{

}

void Server::GetMessasge()
{

}

void Server::ResendMessage()
{

}


void Server::RunServer()
{
    BuildSocket();
}

void Server::StopServer()
{

}

int Server::GetClientsCount()
{
    return 0;
}

std::string Server::GetServerIP()
{
    return "";
}