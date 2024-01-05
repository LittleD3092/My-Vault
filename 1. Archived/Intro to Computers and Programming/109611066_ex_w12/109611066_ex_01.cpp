#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define USE_FILE
// #define FORMATTED_INPUT
// #define FORMATTED_OUTPUT

#define LABEL_LEN 30
char NAME_HDR[][LABEL_LEN] = {"NAME"};
const int NAME_HDR_SIZE = 1;
char ID_HDR[][LABEL_LEN] = {"StudentID"};
const int ID_HDR_SIZE = 1;
char C[][LABEL_LEN] = {"Chinese"};
const int C_SIZE = 1;
char M[][LABEL_LEN] = {"Math"};
const int M_SIZE = 1;
char E[][LABEL_LEN] = {"English"};
const int E_SIZE = 1;
char CS[][LABEL_LEN] = {"ComputerScience"};
const int CS_SIZE = 1;

typedef struct _grade {
    int Chinese, Math, English, computer_science;
} grade;

struct student {
    char name[10];
    int student_id;
    grade student_grade;
};

int matchStr(const char* str1, const char strArr[][LABEL_LEN], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(str1, strArr[i]) == 0)
            return 1;
    }
    return 0;
}

void clearStdinLine()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    // open file
#ifdef USE_FILE
    FILE* fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) 
    {
        printf("File open error!\n");
        exit(0);
    }

    // read file
    int numEntries, numCols, numQueries;
    fscanf(fp, "%d", &numEntries);
    fscanf(fp, "%d", &numCols);
    fscanf(fp, "%d", &numQueries);
    if(numCols > 6) 
    {
        printf("Invalid number of columns!\n");
        exit(0);
    }

    // create array
    struct student* students = (struct student*)malloc(sizeof(struct student) * numEntries);
    if (students == NULL) 
    {
        printf("Memory allocation error!\n");
        exit(0);
    }

    // read header
    char header[6][30];
    for (int i = 0; i < numCols; i++) 
        fscanf(fp, "%s", header[i]);

    // read data
    for (int i = 0; i < numEntries; i++) 
    {
        for(int j = 0; j < numCols; j++)
        {
            if(matchStr(header[j], NAME_HDR, NAME_HDR_SIZE) == 1)
                fscanf(fp, "%s", students[i].name);
            else if(matchStr(header[j], ID_HDR, ID_HDR_SIZE) == 1)
                fscanf(fp, "%d", &students[i].student_id);
            else if(matchStr(header[j], C, C_SIZE) == 1)
                fscanf(fp, "%d", &students[i].student_grade.Chinese);
            else if(matchStr(header[j], M, M_SIZE) == 1)
                fscanf(fp, "%d", &students[i].student_grade.Math);
            else if(matchStr(header[j], E, E_SIZE) == 1)
                fscanf(fp, "%d", &students[i].student_grade.English);
            else if(matchStr(header[j], CS, CS_SIZE) == 1)
                fscanf(fp, "%d", &students[i].student_grade.computer_science);
        }
    }
#endif
#ifndef USE_FILE
    const int numEntries = 5;
    const int numCols = 6;
    const int numQueries = 4;
    struct student students[] = {
        {"Bob", 309553045, 0, 10, 20, 30},
        {"Kevin", 309551116, 100, 100, 50, 100},
        {"Dave", 309551110, 59, 80, 43, 70},
        {"Steve", 309552003, 95, 33, 10, 99},
        {"Stuart", 309552052, 80, 40, 70, 80}
    };
#endif

    // read queries
#ifdef FORMATTED_OUTPUT
    printf("Input queries score:\n");
#endif
    char** queryType = (char**)malloc(sizeof(char*) * numQueries);
    int* queryScore = (int*)malloc(sizeof(int) * numQueries);
    for(int i = 0; i < numQueries; i++)
    {
        queryType[i] = (char*)malloc(sizeof(char) * 5);
        int j = 0;
        while(1)
        {
            char c = getchar();
#ifdef FORMATTED_INPUT
            if(c == ':')
                break;
            else if(c == ' ')
                continue;
            else
                queryType[i][j++] = c;
#endif
#ifndef FORMATTED_INPUT
            if(c == ' ')
                break;
            else
                queryType[i][j++] = c;
#endif
        }
        queryType[i][j] = '\0';
        scanf("%d", &queryScore[i]);
        clearStdinLine();
    }

    // print result
    int padding[4] = {0};
    int maxLen = 0;
    maxLen = strlen(C[0]);
    maxLen = maxLen > strlen(M[0]) ? maxLen : strlen(M[0]);
    maxLen = maxLen > strlen(E[0]) ? maxLen : strlen(E[0]);
    maxLen = maxLen > strlen(CS[0]) ? maxLen : strlen(CS[0]);
    padding[0] = maxLen - strlen(C[0]);
    padding[1] = maxLen - strlen(M[0]);
    padding[2] = maxLen - strlen(E[0]);
    padding[3] = maxLen - strlen(CS[0]);
#ifdef FORMATTED_OUTPUT
    printf("\n");
#endif
    printf("Result:\n");
    for(int i = 0; i < numQueries; i++)
    {
        if(strcmp(queryType[i], "C") == 0)
        {
            printf("%s", C[0]);
#ifdef FORMATTED_OUTPUT
            for(int j = 0; j < padding[0]; j++)
                printf(" ");
#endif
            printf(":");
            for(int j = 0; j < numEntries; j++)
                if(students[j].student_grade.Chinese < queryScore[i])
                    printf("%d ", students[j].student_id);
        }
        else if(strcmp(queryType[i], "M") == 0)
        {
            printf("%s", M[0]);
#ifdef FORMATTED_OUTPUT
            for(int j = 0; j < padding[1]; j++)
                printf(" ");
#endif
            printf(":");
            for(int j = 0; j < numEntries; j++)
                if(students[j].student_grade.Math < queryScore[i])
                    printf("%d ", students[j].student_id);
        }
        else if(strcmp(queryType[i], "E") == 0)
        {
            printf("%s", E[0]);
#ifdef FORMATTED_OUTPUT
            for(int j = 0; j < padding[2]; j++)
                printf(" ");
#endif
            printf(":");
            for(int j = 0; j < numEntries; j++)
                if(students[j].student_grade.English < queryScore[i])
                    printf("%d ", students[j].student_id);
        }
        else if(strcmp(queryType[i], "CS") == 0)
        {
            printf("%s", CS[0]);
#ifdef FORMATTED_OUTPUT
            for(int j = 0; j < padding[3]; j++)
                printf(" ");
#endif
            printf(":");
            for(int j = 0; j < numEntries; j++)
                if(students[j].student_grade.computer_science < queryScore[i])
                    printf("%d ", students[j].student_id);
        }
        printf("\n");
    }

    // close file
#ifdef USE_FILE
    fclose(fp);
#endif

    return 0;
}
