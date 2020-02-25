#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFF_LEN
#define BUFF_LEN 128
#endif

int main()
{
  char buffer[BUFF_LEN + 1];
  ssize_t readedBytes = 0;

  int fd = open("text.txt", O_RDONLY);

  do
  {
    readedBytes = read(fd, buffer, BUFF_LEN);

    if(readedBytes == -1)
    {
      printf("An error occurred while read from file\n!");
      break;
    }

    buffer[readedBytes] = '\0';
    printf("%s", buffer);
  }
  while(readedBytes);

  close(fd);

  return 0;
}
