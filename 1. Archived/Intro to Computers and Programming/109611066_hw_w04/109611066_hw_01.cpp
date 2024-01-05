#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void printArray(char* array)
{
    int index = 0;
    while(array[index] != 0)
        index++;

    index--;
    while(index >= 0)
    {
        printf("%c", array[index]);
        index--;
    }
    printf("\n");
}

int main()
{
    char A[40] = {0};
    char B[40] = {0};

    char input = 0;
    int indexA = 0;

    // input A
    while(true)
    {
        input = getchar();
        if(input == '\n')
            break;
        else
            A[indexA] = input;
        indexA++;
    }

    // input B
    input = 0;
    int indexB = 0;
    while(true)
    {
        input = getchar();
        if(input == '\n' || input == 0)
            break;
        else
            B[indexB] = input;
        indexB++;
    }

    // add A and B
    indexA--;
    indexB--;
    int indexC = 0;
    // note that C is small-left big-right
    char C[40] = {0};
    int carry = 0;
    while(indexA >= 0 && indexB >= 0)
    {
        int result = A[indexA] - '0' + B[indexB] - '0' + carry;
        C[indexC] += result % 10 + '0';
        carry = result / 10;
        indexA--;
        indexB--;
        indexC++;

        // printArray(C);
    }

    // clean A or B
    while(indexA >= 0)
    {
        C[indexC] = A[indexA] + carry;
        carry = 0;
        indexC++;
        indexA--;
    }
    while(indexB >= 0)
    {
        C[indexC] = B[indexB] + carry;
        carry = 0;
        indexC++;
        indexB--;
    }

    // clean carry
    if(carry != 0)
    {
        C[indexC] = carry + '0';
        indexC++;
    }

    // output C
    indexC--;
    while(indexC >= 0)
    {
        printf("%c", C[indexC]);
        indexC--;
    }
    printf("\n");

    return 0;
}