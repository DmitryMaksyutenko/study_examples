#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 200

int main(void) {
    time_t t;
    struct tm *loc;
    char buf[BUFF_SIZE];

    if (setlocale(LC_ALL, "") == NULL) {
        printf("setlocale == NULL");
        exit(EXIT_FAILURE);
    }

    t = time(NULL);
    printf("ctime() of time() value is: %s", ctime(&t));
    loc = localtime(&t);

    if (loc == NULL) {
        printf("localtime = NULL");
        exit(EXIT_FAILURE);
    }

    printf("asctime() of local time is: %s", asctime(loc));

    if (strftime(buf, BUFF_SIZE, "%A, %d %B %Y, %H:%M:%S %Z", loc) == 0) {
        printf("strftime = NULL");
        exit(EXIT_FAILURE);
    }
    printf("strftime() of local time is: %s", buf);

    exit(EXIT_SUCCESS);
}

