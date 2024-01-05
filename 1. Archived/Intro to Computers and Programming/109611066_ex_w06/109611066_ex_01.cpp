#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int ans = min(x, y);

    printf("The min of %d and %d is %d.\n", x, y, ans);

#ifdef _WIN32
    system("pause");
#endif

    return 0;
}