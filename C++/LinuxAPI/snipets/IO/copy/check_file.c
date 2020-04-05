#include "check_file.h"

void check_source(char *source)
{
  if(access(source, F_OK) == -1)
  {
    printf("file %s does not exist!\n", source);
    _exit(EXIT_FAILURE);
  }
}
