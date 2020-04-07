#include "open_file_modes.h"

int defaultOpen(char *fileName)
{
    int fd = open(fileName, O_CREAT | O_WRONLY | O_APPEND, S_IWUSR);

    if(fd == -1)
        errExit("File opening faild.\n");

    return fd;
}

int noAppendOpen(char *fileName)
{
    int fd = open(fileName, O_CREAT | O_WRONLY, S_IWUSR);

    if(fd == -1)
        errExit("File opening faild.\n");

    return fd;
}