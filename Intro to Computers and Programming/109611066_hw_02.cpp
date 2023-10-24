#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int getMaxCandy(int* arr, int start, int finish)
{
    if(start >= finish)
        return 0;
    
    // choose
    int ifChoose = arr[start] + getMaxCandy(arr, start + 2, finish);
    // not choose
    int notChoose = getMaxCandy(arr, start + 1, finish);

    return max(ifChoose, notChoose);
}

int main()
{
    int N;
    scanf("%d", &N);

    int T[45] = {0};
    for(int i = 0; i < N; i++)
        scanf("%d", &T[i]);

    printf("%d\n", getMaxCandy(T, 0, N));

    return 0;
}