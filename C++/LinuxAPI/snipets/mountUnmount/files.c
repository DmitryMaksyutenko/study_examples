#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "files.h"

void createFiles(int number, const char *dirName)
{
    DIR *dir = isDirOpened(dirName);
    const char *tmpFileName;
    bool fileExist = false;

    for (int i = 0; i < number; i++) {
        fileExist = false;
        while (!fileExist) {
            tmpFileName = randomFileName();
            if ((fileExist = isFileExists(dir, tmpFileName))) {
                fileExist = false;
                continue;
            }
            const char *newFile = buildFilePath(dirName, tmpFileName);
            int res = open(newFile, O_RDWR | O_CREAT, S_IRWXU);
            writeOneByte(res);
            fileExist = true;
            free(newFile);
            free(tmpFileName);
        }
    }
    closedir(dir);
}

void deleteFiles(const char *dirName)
{
    DIR *dir = opendir(dirName);
    struct dirent *inDir;

    while((inDir = readdir(dir)) != NULL) {
        if ((strcmp(inDir->d_name, ".") == NULL) ||
            (strcmp(inDir->d_name, "..") == NULL))
            continue;
        const char *p = buildFilePath(dirName, inDir->d_name);
        int a = remove(p);
    }
}

const char* randomFileName()
{
    char *fileName;
    char numStr[7] = {};
    int randomNum = 1 + rand() % 999999;
    sprintf(numStr, "%d", randomNum);
    fileName = malloc(strlen(numStr) + 2);
    strcat(fileName, "x");
    strcat(fileName, &numStr);
    return fileName;
}

DIR* isDirOpened(const char *dirName)
{
    DIR *newDir = opendir(dirName);
    if (!newDir) {
        mkdir(dirName, S_IRWXU);
        newDir = opendir(dirName);
    }
    return newDir;
}

bool isFileExists(DIR *dir, const char *fileName)
{
    struct dirent *inDir;
    while((inDir = readdir(dir)) != NULL) {
        if (inDir->d_name == fileName) {
            printf("file name already exists\n");
            return true;
        }
    }
    return false;
}

const char* buildFilePath(const char *dirName, const char *fileName)
{
    char *newFile = malloc(PATH_MAX);

    getcwd(newFile, PATH_MAX);
    strcat(newFile, "/");
    strcat(newFile, dirName);
    strcat(newFile, "/");
    strcat(newFile, fileName);

    return newFile;
}

void writeOneByte(int fd)
{
   write(fd, " ", 1);
   close(fd);
}
