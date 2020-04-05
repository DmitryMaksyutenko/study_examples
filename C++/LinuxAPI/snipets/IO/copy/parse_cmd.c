#include "parse_cmd.h"

void get_arguments(int argc, char **argv)
{
  if(argc < 3 || argc > 3)
  {
    printf("%s\n", "Wrong arguments count.");

    for(int i = 0; i <  argc; i++)
      printf("%s\n", argv[i]);

    _exit(EXIT_FAILURE);
  }

  printf("copy from file: %s\n", argv[1]);
  printf("copy to file: %s\n", argv[2]);
}
