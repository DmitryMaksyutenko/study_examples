#include "Server.h"

std::string Server::GetIp() const
{
    std::string addr;
    addr = inet_ntoa(socAddrIn.sin_addr);
    return addr;
}

void Server::BuildServer()
{
    BOOL opt = TRUE;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        throw std::exception("WSAStartup failed\n");

    for (int i = 0; i < maxClients; i++)
        clients[i] = 0;
    
    listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSock == INVALID_SOCKET)
    {
        std::cout << WSAGetLastError() << std::endl;
        WSACleanup();
        throw std::exception("failed create listen socket\n");
    }

    // SOL_SOCKET = Level number for (get/set)sockopt() to apply to socket itself.
    // SOL_SOCKET = One of option flags per-socket.
    if (setsockopt(listenSock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == SOCKET_ERROR)
    {
        std::cout << WSAGetLastError() << std::endl;
        closesocket(listenSock);
        WSACleanup();
        throw std::exception("failed set socket options\n");
    }

    socAddrIn.sin_family = AF_INET;
    socAddrIn.sin_addr.s_addr = INADDR_ANY;
    socAddrIn.sin_port = htons(port);

    if (bind(listenSock, (const struct sockaddr*) &socAddrIn, sizeof(socAddrIn)) == SOCKET_ERROR)
    {
        closesocket(listenSock);
        WSACleanup();
        throw std::exception("binding failed\n");
    }
}

void Server::Runserver()
{
    if (listen(listenSock, 3) == SOCKET_ERROR)
    {
        closesocket(listenSock);
        WSACleanup();
        throw std::exception("listening failed\n");
    }

    char buffer[1024];
    int max_sd;
    int activity;
    SOCKET sd;
    timeval t;
    t.tv_usec = 50000000;
    while(true)
    {
        //  Clear the socket set
        FD_ZERO(&readFdSet);

        //  Add Listen socket to set
        FD_SET(listenSock, &readFdSet);
        max_sd = listenSock;

        //  Add childe sockets to set
        for (int i = 0; i < maxClients; i++)
        {
            sd = clients[i];
            // If valid socket descriptor add it to set
            if (sd > 0)
                FD_SET(sd, &readFdSet);
            // Highest file descriptor number, need it for the select function  
            if(sd > max_sd)   
                max_sd = sd;
        }

        // The select function determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O
        activity = select(0, &readFdSet, NULL, NULL, &t);
        std::cout << activity << std::endl;

        //If something happened on the master socket ,  
        //then its an incoming connection 
        if (FD_ISSET(listenSock, &readFdSet))
        {
            sendSock = accept(listenSock, (struct sockaddr *) &socAddrIn, (socklen_t *)sizeof(socAddrIn));
            if (sendSock == INVALID_SOCKET)
            {
                std::cout << WSAGetLastError() << std::endl;
                closesocket(listenSock);
                WSACleanup();
                throw std::exception("accept failed\n");
            }
            std::cout << "connection : " << inet_ntoa(socAddrIn.sin_addr) << std::endl;

            // Add new socket to set
            for (int i = 0; i < maxClients; i++)
            {
                if (clients[i] == 0)
                    clients[i] = sendSock;
            }

            // Else its some IO operation on some other socket 
            int res;
            for (int i = 0; i < maxClients; i++)
            {
                sd = clients[i];
                if (FD_ISSET(sd, &readFdSet))
                {
                    ZeroMemory(buffer, 1024);
                    res = recv(sd, buffer, 1024, 0);
                    if (res == 0)
                    {
                        closesocket(sd);
                        clients[i] = 0;
                    }
                    else
                    {
                        send(sd, buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }
}

void Server::CloseServer()
{
    shutdown(sendSock, SD_SEND);
    closesocket(sendSock);
    WSACleanup();
    std::cout << "Server closed\n";
}