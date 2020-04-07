#include "show_process_info.h"

void showProcessInfo()
{
    printf("Process ID        = %i\n", getpid());
    printf("Process parent ID = %i\n", getppid());
}