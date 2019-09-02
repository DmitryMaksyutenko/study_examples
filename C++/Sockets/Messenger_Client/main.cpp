#include "Client.h"

int __cdecl main()
{
    Client clnt;

    try
    {
       clnt.BuildClient(); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}