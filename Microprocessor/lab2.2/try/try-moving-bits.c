#include <stdio.h>

int main()
{
    int a = 0b000011;
    a = (a >> 1);
    printf("%d", a);
}