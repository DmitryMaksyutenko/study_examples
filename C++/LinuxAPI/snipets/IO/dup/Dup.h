#ifndef __DUP_H_
#define __DUP_H_

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int Dup(int oldfd);
int Dup2(int oldfd, int newfd);

#endif