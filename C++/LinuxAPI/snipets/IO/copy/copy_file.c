#include "copy_file.h"


void copy_from_to(int fdFrom, int fdTo, char buff[], int size)
{
  if(fdFrom != -1 && fdTo != -1)
  {
    off_t fPos = 0;
    do
    {
      fPos = read(fdFrom, buff, size);
      write(fdTo, buff, fPos);
    }
    while(fPos);
  }
  else
  {
    printf("Error file oprning \n");
    _exit(EXIT_FAILURE);
  }
}


void copy_file(char *source, char *dest)
{
  #define BUFFER 1024
  char buff[BUFFER];
  int fdSource;
  int fdDest;

  fdSource = open(source, O_RDONLY);
  fdDest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
  printf("%i\n", fdDest);
  printf("%i\n", fdSource);

  copy_from_to(fdSource, fdDest, buff, BUFFER);

  close(fdSource);

}
