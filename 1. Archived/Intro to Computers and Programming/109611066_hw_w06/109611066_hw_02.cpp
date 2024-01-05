#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int ANS[80] = {0};

void swap(int* a, int* b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

void permutation(int* array, int left, int right)
{
    if(left == right)
    {
        int A = 0;
        int B = 0;
        for(int i = 0; i < 5; i++)
            A = A * 10 + array[i];
        for(int i = 5; i < 10; i++)
            B = B * 10 + array[i];
        if(A % B == 0)
            ANS[A / B]++;
    }
    else // left != right
    {
        for(int i = left; i < right; i++)
        {
            swap(&array[left], &array[i]);
            permutation(array, left + 1, right);
            swap(&array[left], &array[i]);
        }
    }
}

int main()
{
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
    permutation(digits, 0, 10);

    int input;
    scanf("%d", &input);
    printf("%d\n", ANS[input]);
}