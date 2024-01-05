#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print(int n)
{
    if(n == 0)
        return;
    else
    {
        print(n - 1);
        printf("%c", 'a' + n - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print(n);
    printf("\n");
    return 0;
}