#include <sys/types.h>

#include "src/fdcompare.h"
#include "src/error_functions.h"

int main(void)
{
    int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("test.txt", O_RDONLY);

    char buff[64];

    if(fd1 == -1 || fd2 == -1)
        errExit("File couldn't open\n");

    // read(fd1, buff, 4);
    // fd2 = lseek(fd2, F_GETFL, O_RDWR);
    // lseek(fd2, F_SETFL, O_RDWR);

    fdcompare(fd1, fd2);

    close(fd1);
    close(fd2);

    return 0;
}