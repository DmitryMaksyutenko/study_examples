#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

void showInfo(int fd)
{
    if(fd == -1)
    {
        printf("File opening error.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("File opened successfully.\n");
        printf("File descriptor   = %i\n", fd);
        printf("Process ID        = %i\n", getpid());
        printf("Process parent ID = %i\n", getppid());
    }
}

int main()
{
    const char *appenText = "text to append.";
    int fd = open("test.txt", O_WRONLY | O_APPEND);

    showInfo(fd);

    lseek(fd, 5, SEEK_SET); // Read about O_APPEND.

    write(fd, appenText, strlen(appenText));

    close(fd);

    return 0;
}
