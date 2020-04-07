#include "write_file.h"

void write_file(int argc, char *fileName, int bytesCount)
{
    int fd;

    if(argc == 4)
    {
        printf("no append\n");
        fd = noAppendOpen(fileName);
        for(int i = 0; i < bytesCount; i++)
        {
            lseek(fd, 0, SEEK_END);
            write(fd, " ", 1);
        }
    }
    else
    {
        fd = defaultOpen(fileName);
        printf("append\n");
        for(int i = 0; i < bytesCount; i++)
            write(fd, " ", 1);
    }

    close(fd);
}