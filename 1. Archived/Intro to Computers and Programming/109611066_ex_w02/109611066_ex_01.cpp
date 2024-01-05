#include<cstdio>
#include<cstdlib>

int main()
{
    int day = 4;

    switch(day)
    {
    case 6:
        printf("Today is Saturday!");
        break;

    case 7:
        printf("Today is Sunday!");
        break;
    
    default:
        printf("Looking forward to the Weekend~");
        break;
    }

    return 0;
}