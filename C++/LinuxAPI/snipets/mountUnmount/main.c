#include <time.h>

#include "cmd.h"
#include "files.h"

void printResult(const struct tm *timeCreation, const struct tm *timeDeletion)
{
    if (timeCreation->tm_min == NULL) {
        printf("files creation time: %i sec.\nfiles deletion time: %i sec.\n",
               timeCreation->tm_sec,
               timeDeletion->tm_sec);
    } else {
        printf("files creation time: %i min, %i sec.\nfiles deletion time: %i min, %i sec.\n",
               timeCreation->tm_min,
               timeCreation->tm_sec,
               timeDeletion->tm_min,
               timeDeletion->tm_sec);
    }
}

int main(int argc, char **argv)
{
    srand(time(0));
    struct DirInfo *dirInfo = getCmdParams(argc, argv);

    time_t filesCreationStart = time(0);
    createFiles(dirInfo->filecount, dirInfo->dirName);
    time_t filesCreationEnd = time(0);
    time_t subResult = filesCreationEnd - filesCreationStart;
    struct tm *filesCreationTime = gmtime(&subResult);

    time_t filesDeletionStart = time(0);
    deleteFiles(dirInfo->dirName);
    time_t filesDeletionEnd = time(0);
    subResult = filesDeletionEnd - filesDeletionStart;
    struct tm *filesDeletionTime = gmtime(&subResult);

    printResult(filesCreationTime, filesDeletionTime);

    free(dirInfo->dirName);
    free(dirInfo);
    return 0;
}

