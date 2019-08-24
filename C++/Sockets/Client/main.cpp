#define WIN32_LEAN_AND_MEAN // For increase building process.

#include <windows.h>
#include <winsock2.h>  // This header is used by Quality of Service (QOS).
#include <ws2tcpip.h> // This header is used by Windows Sockets.
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512 
#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char **argv) 
{
    // The WSADATA structure contains information about the Windows Sockets implementation.
    WSADATA wsaData;
    // Create a SOCKET object as unused.
    SOCKET ConnectSocket = INVALID_SOCKET;

    // The addrinfo structure is used by the getaddrinfo function to hold host address information.
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    
    char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    
    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) ); // Fill struct with zeros
    hints.ai_family = AF_UNSPEC;     // The address family is unspecified.
    hints.ai_socktype = SOCK_STREAM; // Provides sequenced, reliable, two-way, connection-based byte streams.
    hints.ai_protocol = IPPROTO_TCP; // The Transmission Control Protocol.

    // Resolve the server address and port
    // The getaddrinfo function provides protocol-independent translation from an ANSI host name to an address.
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
                                ptr->ai_protocol);

        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();// Function terminates use of the Winsock 2 DLL (Ws2_32.dll).
            return 1;
        }

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket); // Function closes an existing socket.
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    /* The freeaddrinfo function frees address information 
    that the getaddrinfo function dynamically allocates in addrinfo structures. */
    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    // Send an initial buffer
    // The send function sends data on a connected socket.
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    // The shutdown function disables sends or receives on a socket.
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {
        // The recv function receives data from a connected socket or a bound connectionless socket.
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            printf("Bytes received: %d\n", iResult);
        else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while( iResult > 0 );

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}