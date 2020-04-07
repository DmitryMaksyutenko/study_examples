#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "src/error_functions.h"

int defaultOpen(char *fileName);
int noAppendOpen(char *fileName);