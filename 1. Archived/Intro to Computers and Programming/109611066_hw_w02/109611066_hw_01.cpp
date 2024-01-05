#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // sort three edges
    if(a > b)    swap(&a, &b);
    if(b > c)    swap(&b, &c);
    if(a > b)    swap(&a, &b);

    // check if it forms a triangle
    if(a + b <= c)
    {
        printf("%d %d %d cannot form a triangle.\n", a, b, c);
        return 0;
    }
    else // a + b > c
        printf("%d %d %d can form a triangle.\n", a, b, c);

    // check acute, right or obtuse
    if(a * a + b * b > c * c)  
        printf("%d %d %d can form an acute triangle.\n", a, b, c);
    else if(a * a + b * b < c * c)
        printf("%d %d %d can form an obtuse triangle.\n", a, b, c);
    else // a * a + b * b == c * c
        printf("%d %d %d can form a right triangle.\n", a, b, c);

    // check equilateral
    if(a == b && b == c)
        printf("%d %d %d can form an equilateral triangle.\n", a, b, c);

    // check isosceles
    if(a == b || b == c)
        printf("%d %d %d can form an isosceles triangle.\n", a, b, c);
    
    // check scalene
    if(a != b)
        printf("%d %d %d can form a scalene triangle.\n", a, b, c);

    return 0;
}