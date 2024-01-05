#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    // add
    printf("%d\n", num1 + num2);

    // subtract
    printf("%d\n", num1 - num2);

    // multiply
    printf("%d\n", num1 * num2);

    // divide
    printf("%.2f\n", (float)num1 / (float)num2);

    // remainder
    printf("%d\n", num1 % num2);

    return 0;
}