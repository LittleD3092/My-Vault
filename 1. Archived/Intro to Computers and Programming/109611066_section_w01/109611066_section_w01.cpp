#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define INPUT_SIZE 135

void inputLine(char *line)
{
    char buffer;
    int i = 0;
    while(1)
    {
        scanf("%c", &buffer);
        if(buffer == '\n')
            break;
        else
            line[i++] = buffer;
    }
    line[i] = '\0';
}

int main()
{
    // input file path
    char filePath[INPUT_SIZE];
    inputLine(filePath);

    // get stat of file
    struct stat fileStat;
    if(stat(filePath, &fileStat) < 0)
    {
        printf("Error: cannot get stat of file\n");
        exit(1);
    }

    // print path, file type, and file size
    printf("%s\n", filePath);
    printf("Type: ");
    switch(fileStat.st_mode & S_IFMT)
    {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }
    char unit[10] = "bytes";
    long long size = fileStat.st_size;
    if(size > 1024)
    {
        size /= 1024;
        strcpy(unit, "KB");
    }
    if(size > 1024)
    {
        size /= 1024;
        strcpy(unit, "MB");
    }
    if(size > 1024)
    {
        size /= 1024;
        strcpy(unit, "GB");
    }
    printf("Size: %lld %s\n", size, unit);

    return 0;
}