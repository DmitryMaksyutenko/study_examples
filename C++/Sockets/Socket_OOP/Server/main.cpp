#include "Server.h"

int __cdecl main()
{
    Server srv;

    if (!srv.WsaInit())
        return 1;
    if (!srv.ResolveAddrPort())
        return 1;
    if (!srv.CreateListenSocket())
        return 1;
    if (!srv.SetupTCPListenSocket())
        return 1;
    if (!srv.SetMaxBacklog())
        return 1;
    if (!srv.AcceptClientSocket())
        return 1;
    if (!srv.ReceiveMessages())
        return 1;
    if (!srv.ShatdownConnection())
        return 1;


    return 0;
}