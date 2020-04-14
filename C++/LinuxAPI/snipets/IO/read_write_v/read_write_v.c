#include "read_write_v.h"

ssize_t readV(int fd, struct iovec *iov, int iovcnt)
{
    ssize_t readed = 0;

    for(int i = 0; i < iovcnt; i ++)
    {
        ssize_t tmp = 0;
        tmp = read(fd, iov[i].iov_base, iov[i].iov_len);
        if(tmp == 0) break;
        readed += tmp;
    }

    return readed;
}

ssize_t writeV(int fd, const struct iovec *iov, int iovcnt)
{
    ssize_t writed = 0;

    for(int i = 0; i < iovcnt; i ++)
    {
        ssize_t tmp = 0;
        tmp = write(fd, iov[i].iov_base, iov[i].iov_len);
        if(tmp == 0) break;
        writed += tmp;
    }

    return writed;
}