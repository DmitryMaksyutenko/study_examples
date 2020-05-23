#include <locale.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 50

void showLocaleInfo(const char *val)
{
    int len = strlen(val);
    int bufPosition = 0;
    char buff[BUFF_SIZE];
    memset(buff, 0, BUFF_SIZE);

    for (int i = 0; i < len - 1; i++) {
        if (val[i] == ';') {
            buff[bufPosition++] = '\n';
            printf("%s", buff);
            bufPosition = 0;
            memset(buff, 0, BUFF_SIZE);
            continue;
        }
        buff[bufPosition++] = val[i];
    }
}

int main(void)
{
    char *pLoc = setlocale(LC_ALL, "");
    showLocaleInfo(pLoc);
    time_t tm = time(NULL);
    struct tm *pLocalTime = localtime(&tm);
    char localTime[70];
    strftime(localTime, sizeof(localTime), "%A %c", pLocalTime);
    printf("time: %s\n", localTime);

    return 0;
}

