#ifndef __TLPI_HDR_H__
#define __TLPI_HDR_H__

#include <sys/types.h>  // types defining.

#include <stdio.h>  // io functions.
#include <stdlib.h> // precompiled header.

#include <unistd.h> // system calls prototypes.
#include <errno.h>  // errno and constants.
#include <string.h> // string handling functions.

#include "get_num.h"
#include "error_functions.h"

typedef enum { FALSE, TRUE } Boolean;

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif
