#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int BUFFER[10];
int BUFFER_SIZE = 0;

void pCombination(int choose, int* arr, int start, int finish)
{
    // end case
    if(choose < 0)
        return;
    if(start == finish)
    {
        
        for(int i = 0; i < BUFFER_SIZE; i++)
            printf("%d", BUFFER[i]);
        printf("\n");
        return;
    }

    // choose start
    BUFFER[BUFFER_SIZE] = arr[start];
    BUFFER_SIZE++;
    pCombination(choose - 1, arr, start + 1, finish);
    BUFFER_SIZE--;

    // don't choose
    pCombination(choose, arr, start + 1, finish);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[10];
    for(int i = 1; i < 10; i++)
        arr[i] = i;
    pCombination(k, arr, 1, 1 + n);

    return 0;
}