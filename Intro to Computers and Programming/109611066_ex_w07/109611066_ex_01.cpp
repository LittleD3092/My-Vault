#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fib(int index)
{
    if(index == 0)
        return 0;
    else if(index == 1)
        return 1;
    else
        return fib(index - 1) + fib(index - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}