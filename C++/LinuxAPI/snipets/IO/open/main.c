#include <fcntl.h>  //  Define arguments for open().
#include <unistd.h> //  Define read().
#include <stdio.h>

int main(int argc, char *argv[])
{
    int file_descriptor = open("test.txt", O_RDONLY);

    if (file_descriptor == -1)
        printf(stderr, " file opening is failed\n");
    else
        printf("file opened successfully\n");

    #define BUFF_SIZE 1024
    int bytes_readed = 0;
    char buff[BUFF_SIZE];

    while(1)
    {
        bytes_readed = read(file_descriptor, buff, BUFF_SIZE);

        if(bytes_readed == 0) break;

        printf("\nbytes readed: %i\n", bytes_readed);
        printf("%s", buff);
    }

    close(file_descriptor);

    return 0;
}