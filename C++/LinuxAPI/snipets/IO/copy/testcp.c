#include <stdio.h>

#include "src/parse_cmd.h"
#include "src/check_file.h"
#include "src/copy_file.h"

int main(int argc, char **argv)
{
  get_arguments(argc, argv);

  check_source(argv[1]);

  copy_file(argv[1], argv[2]);

  return 0;
}
