#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* compare(const char *S, const char *T, int N)
{
    int* result = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        result[i] = S[i] == T[i] ? 1 : 0;
    return result;
}

int main()
{
    while(true)
    {
        int size;
        scanf("%d", &size);

        if(size == 0)
            break;

        char _;
        scanf("%c", &_);
        char S[size + 5];
        char T[size + 5];
        for(int i = 0; i < size; i++)
            scanf("%c", &S[i]);
        scanf("%c", &_);
        for(int i = 0; i < size; i++)
            scanf("%c", &T[i]);
        scanf("%c", &_);

        int* ans = compare(S, T, size);
        for(int i = 0; i < size; i++)
            printf("%d", ans[i]);
        printf("\n");
    }

    return 0;
}