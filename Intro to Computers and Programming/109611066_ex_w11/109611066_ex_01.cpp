#define _CRT_SECURE_NO_WARNINGS
#define IS_FROM_FILE 0
#include <stdio.h>
#include <stdlib.h>

struct String
{
    char* data;
    int length;
    int capacity;
};
void String__constructor(String* str);
void String__constructorCstr(String* str, char* cstr);
void String__destructor(String* str);
void String__resize(String* str, int newCapacity);
void String__append(String* str, char c);
int String__length(String* str);
void String__print(String* str);

void String__constructor(String* str)
{
    str->data = (char*)malloc(sizeof(char));
    str->length = 0;
    str->capacity = 1;
}

void String__constructorCstr(String* str, const char* cstr)
{
    String__constructor(str);
    for (int i = 0; cstr[i] != '\0'; i++)
        String__append(str, cstr[i]);
}

void String__destructor(String* str)
{
    free(str->data);
}

void String__resize(String* str, int newCapacity)
{
    char* newData = (char*)malloc(sizeof(char) * newCapacity);
    for (int i = 0; i < str->length; i++)
        newData[i] = str->data[i];
    free(str->data);
    str->data = newData;
    str->capacity = newCapacity;
}

void String__append(String* str, char c)
{
    if (str->length == str->capacity)
        String__resize(str, str->capacity * 2);
    str->data[str->length] = c;
    str->length++;
}

int String__length(String* str)
{
    return str->length;
}

void String__print(String* str)
{
    for (int i = 0; i < str->length; i++)
        printf("%c", str->data[i]);
    printf("\n");
}

void readFromFile(String* fileName, String* str)
{
    FILE* file = fopen(fileName->data, "r");
    char c;
    while ((c = fgetc(file)) != EOF)
        String__append(str, c);
    fclose(file);
}

void writeToFile(String* fileName, String* str)
{
    FILE* file = fopen(fileName->data, "w");
    for (int i = 0; i < String__length(str); i++)
        fputc(str->data[i], file);
    fclose(file);
}

void readLine(String* str)
{
    char c;
    while ((c = getchar()) != '\n')
        String__append(str, c);
}

void replaceNonAlphabet(String* str, char replaceWith)
{
    for(int i = 0; i < String__length(str); i++)
        if(!((str->data[i] >= 'a' && 
              str->data[i] <= 'z') || 
             (str->data[i] >= 'A' && 
              str->data[i] <= 'Z')))
            str->data[i] = replaceWith;
}

void invertCase(String* str)
{
    for(int i = 0; i < String__length(str); i++)
        if(str->data[i] >= 'a' && str->data[i] <= 'z')
            str->data[i] -= 32;
        else if(str->data[i] >= 'A' && str->data[i] <= 'Z')
            str->data[i] += 32;
}

void clearInputBuffer()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    // input replace character
    char replaceWith;
    scanf("%c", &replaceWith);
    clearInputBuffer();


    // input string from file or stdin
    String input;
    String__constructor(&input);
    String inputFileName;
    String__constructorCstr(&inputFileName, "input.txt");
    if(IS_FROM_FILE)
        readFromFile(&inputFileName, &input);
    else // from stdin
        readLine(&input);

    // replace non-alphabet characters with replaceWith and invert case
    replaceNonAlphabet(&input, replaceWith);
    invertCase(&input);

    // save output to file or stdout
    String outputFileName;
    String__constructorCstr(&outputFileName, "output.txt");
    if(IS_FROM_FILE)
        writeToFile(&outputFileName, &input);
    else // to stdout
        String__print(&input);
}