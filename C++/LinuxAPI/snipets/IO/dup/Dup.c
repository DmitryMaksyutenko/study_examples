#include "Dup.h"

int Dup(int oldfd)
{
    int newfd = fcntl(oldfd, F_DUPFD);
    return newfd;
}

int Dup2(int oldfd, int newfd)
{
    if(oldfd == newfd)
    {
        errno = EBADF;
        return -1;
    }
    else if(fcntl(oldfd, F_GETFL) == -1)
    {
        errno = EBADF;
        return -1;
    }
    else
    {
        close(newfd);
        newfd = fcntl(oldfd, F_DUPFD, newfd);
    }

    return newfd;
}