#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// read std input for a big integer number.
// length is for protection. 
// will only read at most 'length' digits.
// returns the length of array.
int inputNumArray(int* array, int length)
{
    for(int i = 0; i < length; i++)
    {
        char input = getchar();
        
        if(input == '\n' || input == 0)
        {
            array[i] = -1;
            return i;
        }
        else
            array[i] = input - '0';
    }
    return length;
}

void swap(int* num1, int* num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void reverseArray(int* array)
{
    int n = 0;
    while(array[n] != -1) n++;

    for(int i = 0; i < n / 2; i++)
        swap(&array[i], &array[n - i - 1]);
}


int main()
{
    int A[30] = {-1};
    int B[30] = {-1};
    int C[50] = {0};

    int Asize = inputNumArray(A, 30);
    int Bsize = inputNumArray(B, 30);

    reverseArray(A);
    reverseArray(B);

    for(int i = 0; i < Asize; i++)
        for(int j = 0; j < Bsize; j++)
            C[i + j] += A[i] * B[j];

    int Csize = 0;
    for(int i = 0; i < 50; i++)
    {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;

        if(C[i] != 0)
            Csize = i;
    }

    for(int i = Csize; i >= 0; i--)
        printf("%d", C[i]);
    printf("\n");

    return 0;
}