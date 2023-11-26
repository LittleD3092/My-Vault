#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* readLine()
{
    char* input = (char*)malloc(sizeof(char) * 100);
    int i = 0;
    while(true)
    {
        char c = getchar();
        if(c == '\n')
        {
            break;
        }
        input[i++] = c;
    }
    input[i] = '\0';
    return input;
}

int getFileSize(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    int size = 0;
    while(true)
    {
        char c = fgetc(fp);
        if(c == EOF)
        {
            break;
        }
        size++;
    }
    fclose(fp);
    return size;
}

char* readFile(const char* filename)
{
    int fileSize = getFileSize(filename) + 5;
    FILE* fp = fopen(filename, "r");
    char* input = (char*)malloc(sizeof(char) * fileSize);
    int i = 0;
    while(true)
    {
        char c = fgetc(fp);
        if(c == EOF)
        {
            break;
        }
        input[i++] = c;
    }
    input[i] = '\0';
    fclose(fp);
    return input;
}

void writeFile(const char* filename, const char* input)
{
    FILE* fp = fopen(filename, "w");
    int i = 0;
    while(true)
    {
        if(input[i] == '\0')
            break;
        fputc(input[i++], fp);
    }
    fclose(fp);
}

int getStringSize(const char* input)
{
    int i = 0;
    while(true)
    {
        if(input[i] == '\0')
            break;
        i++;
    }
    return i;
}

char* encrypt(const char* input, const char* keyword)
{
    int i = 0;
    int j = 0;

    char* result = (char*)malloc(sizeof(char) * getStringSize(input) + 5);

    while(true)
    {
        if(input[i] == '\0')
            break;
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            result[i] = (input[i] - 'a' + keyword[j] - 'a') % 26 + 'a';
            j++;
            if(keyword[j] == '\0')
                j = 0;
        }
        else if(input[i] >= 'A' && input[i] <= 'Z')
        {
            result[i] = (input[i] - 'A' + keyword[j] - 'a') % 26 + 'A';
            j++;
            if(keyword[j] == '\0')
                j = 0;
        }
        i++;
    }
    result[i] = '\0';
    return result;
}

int main()
{
    char* keyword = readLine();
    char* input = readFile("p1_input.txt");
    char* result = encrypt(input, keyword);
    writeFile("p1_output.txt", result);
    return 0;
}