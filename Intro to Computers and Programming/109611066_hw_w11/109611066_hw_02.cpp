#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

char* decrypt(char* ciphertext, char* plaintext)
{
    char* keyword = (char*)malloc(sizeof(char) * 100);
    for(int keywordLen = 2; keywordLen <= 15; keywordLen++)
    {
        // generate keyword
        for(int i = 0; i < keywordLen; i++)
        {
            int 
        }
    }
}

int main()
{
    char* plaintext = readFile("p2_input_plaintext.txt");
    char* ciphertext = readFile("p2_input_ciphertext.txt");
    return 0;
}