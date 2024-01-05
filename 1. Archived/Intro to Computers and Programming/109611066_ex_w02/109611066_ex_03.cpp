#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("ax^2 + bx + c\n");
    printf("Please input the coefficients: a b c\n");
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    int delta = b * b - 4 * a * c;
    
    if(delta > 0)
        printf("\'%dx^2+%dx+4\' has two distinct roots\n", a, b, c);
    else if(delta == 0)
        printf("\'%dx^2+%dx+4\' has double roots\n", a, b, c);
    else
        printf("\'%dx^2+%dx+4\' has no real root\n", a, b, c);
}