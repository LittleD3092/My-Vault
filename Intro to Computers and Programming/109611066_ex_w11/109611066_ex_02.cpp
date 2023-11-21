#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("ex2_input.txt", "r");
    int S, C;
    fscanf(file, "%d", &S);
    fscanf(file, "%d", &C);

    if(S == 1)
    {
        for(int i = C; i >= 1; i--)
        {
            for(int j = 0; j < i; j++)
                printf("* ");
            printf("\n");
        }
    }
    else if(S == 2)
    {
        for(int i = 1; i <= C; i++)
        {
            int spacePad = C - i;
            for(int j = 0; j < spacePad; j++)
                printf(" ");
            for(int j = 0; j < i; j++)
                printf("* ");
            printf("\n");
        }
    }
    else if(S == 3)
    {
        for(int i = 1; i <= C; i++)
        {
            int spacePad = 2 * (C - i);
            for(int j = 0; j < spacePad; j++)
                printf(" ");
            for(int j = 0; j < i; j++)
                printf("* ");
            printf("\n");
        }
    }

    return 0;
}