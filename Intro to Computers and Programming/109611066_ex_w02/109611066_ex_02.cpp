#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ADyear = 0;
    while(1)
    {
        printf("Please input an AD year: ");
        scanf("%d", &ADyear);

        if(ADyear > 2023)
            printf("The year %d is after 2023.\n", ADyear);
        else
            break;
    }

    if(ADyear % 400 == 0)
        printf("%d is a leap year\n", ADyear);
    else if(ADyear % 4 == 0 && ADyear % 100 != 0)
        printf("%d is a leap year\n", ADyear);
    else
        printf("%d is not a leap year\n", ADyear);
}