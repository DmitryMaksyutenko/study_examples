#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("SYSTEM CONFIGS:\n");
    printf("name: %s -> value: %lu\n", "ARG_MAX", sysconf(_SC_ARG_MAX));
    printf("name: %s -> value: %lu\n", "HOST_NAME_MAX", sysconf(_SC_HOST_NAME_MAX));
    printf("name: %s -> value: %lu\n", "CLOCK_TICKS", sysconf(_SC_CLK_TCK));
    printf("name: %s -> value: %lu\n", "NGROUPS_MAX", sysconf(_SC_NGROUPS_MAX));
    printf("name: %s -> value: %lu\n", "PAGE_NUM", sysconf(_SC_PHYS_PAGES));


    printf("\nPATH CONFIGS:\n");
    printf("name: %s -> value: %lu\n", "LINK_MAX", pathconf("/src", _PC_LINK_MAX));
    printf("name: %s -> value: %lu\n", "NAME_MAX", pathconf("/src", _PC_NAME_MAX));
    printf("name: %s -> value: %lu\n", "INPUT_MAX", pathconf("/src", _PC_MAX_INPUT));
    printf("name: %s -> value: %lu\n", "PIPE_BUF", pathconf("/src", _PC_PIPE_BUF));
    printf("name: %s -> value: %lu\n", "CHOWN_RESTRICTED", pathconf("/src", _PC_CHOWN_RESTRICTED));

    return 0;
}

