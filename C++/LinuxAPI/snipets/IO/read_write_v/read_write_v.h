#ifndef __READ_WRITE_V_H
#define __READ_WRITE_V_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t readV(int fd, struct iovec *iov, int iovcnt);
ssize_t writeV(int fd, const struct iovec *iov, int iovcnt);

#endif