#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// #define VERBOSE
// #define VVERBOSE

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

int isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char* decrypt(char* ciphertext, char* plaintext)
{
    char* keyword = (char*)malloc(sizeof(char) * 100);
    for(int keywordLen = 2; keywordLen <= 15; keywordLen++)
    {
#ifdef VVERBOSE
        printf("trying keyword length %d...\n", keywordLen);
#endif
        // generate keyword
        for(int i = 0, offset = 0; i < keywordLen; i++)
        {
            while(!isAlpha(ciphertext[i + offset]))
                offset++;
            int diff = ciphertext[i + offset] - plaintext[i + offset];
            if(diff < 0)
                diff += 26;
            keyword[i] = diff + 'a';
        }
        keyword[keywordLen] = '\0';

#ifdef VVERBOSE
        printf("keyword: %s\n", keyword);
#endif

        // verify keyword
        bool failed = false;
        for(int i = 0, j = 0; ciphertext[i] != '\0'; i++, j++)
        {
            if(!isAlpha(ciphertext[i]))
            {
                j--;
                continue;
            }
            if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z' && 
               ciphertext[i] != (plaintext[i] - 'A' + keyword[j % keywordLen] - 'a') % 26 + 'A')
            {
#ifdef VVERBOSE
                printf("failed at %d\n", i);
                printf("ciphertext: %c\n", ciphertext[i]);
                printf("plaintext: %c\n", plaintext[i]);
                printf("keyword: %c\n", keyword[j % keywordLen]);
#endif
                failed = true;
                break;
            }
            else if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z' && 
                    ciphertext[i] != (plaintext[i] - 'a' + keyword[j % keywordLen] - 'a') % 26 + 'a')
            {
#ifdef VVERBOSE
                printf("failed at %d\n", i);
                printf("ciphertext: %c\n", ciphertext[i]);
                printf("plaintext: %c\n", plaintext[i]);
                printf("keyword: %c\n", keyword[j % keywordLen]);
#endif
                failed = true;
                break;
            }
        }
        if(!failed)
            return keyword;
    }
    return NULL;
}

int main()
{
#ifdef VERBOSE
    printf("reading files...\n");
#endif
    char* plaintext = readFile("p2_input_plaintext.txt");
    char* ciphertext = readFile("p2_input_ciphertext.txt");
#ifdef VERBOSE
    printf("decrypting...\n");
#endif
    char* keyword = decrypt(ciphertext, plaintext);
    if(keyword == NULL)
    {
        printf("failed to decrypt\n");
        return 0;
    }
    printf("%s\n", keyword);
    return 0;
}