#include <stdio.h>
#include <memory.h>

#include "src/Dup.h"

void showContent(int fd)
{
    char buff[1024] = {};
    off_t size;
    do
    {
        size = read(fd, buff, 1024);
        if(size)
        {
            printf("%s\n", buff);
            memset(buff, 0, 1024);
        }
    }
    while (size);
}

int main(int argc, char *argv[])
{
    int fd = open("test", O_RDONLY);
    int newfd = Dup(fd);
    printf("fd1 = %d; newfd1 = %d\n", fd, newfd);
    showContent(fd);
    showContent(newfd);
    close(fd);
    close(newfd);

    fd = open("test", O_RDONLY);
    newfd = Dup2(fd, 555);
    printf("fd1 = %d; newfd1 = %d\n", fd, newfd);

    if(newfd == -1)
        printf("newfd is %i\n", newfd);

    showContent(fd);
    showContent(newfd);
    close(fd);
    close(newfd);

    return 0;
}