#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void createGeometric(int* a, int n, int r)
{
    for(int i = 1; i < 5; i++)
        a[i] = a[i - 1] * r;
}

int main()
{
    int geometric_arr[10] = {-1};
    int n, r;
    scanf("%d %d %d", &n, &r, &geometric_arr[0]);

    createGeometric(geometric_arr, n, r);

    for(int i = 0; i < n; i++)
        printf("%d ", geometric_arr[i]);
    printf("\n");

    return 0;
}