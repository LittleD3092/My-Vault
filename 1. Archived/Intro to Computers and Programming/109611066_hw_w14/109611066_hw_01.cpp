#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// #define DEBUG

typedef struct Pair
{
    int first;
    int second;
} Pair;

void Pair__sortArr(Pair *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j].first < arr[min].first)
                min = j;
        }
        Pair temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void Pair__mergeOverlap(Pair *arr, int n, Pair *result, int *resultSize)
{
    int resultIndex = 0;
    result[resultIndex] = arr[0];
    resultIndex++;
    for(int i = 1; i < n; i++)
    {
        if(result[resultIndex - 1].second < arr[i].first)
        {
            result[resultIndex] = arr[i];
            resultIndex++;
        }
        else // result[resultIndex - 1].second >= arr[i].first (overlap)
        {
            if(result[resultIndex - 1].second < arr[i].second)
                result[resultIndex - 1].second = arr[i].second;
        }
    }
    *resultSize = resultIndex;
}

int main()
{
    int n;
    scanf("%d", &n);
    Pair *arr = (Pair *)malloc(sizeof(Pair) * n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
#ifdef DEBUG
    printf("arr: \n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].first, arr[i].second);
    printf("\n");
#endif

    Pair__sortArr(arr, n);
    Pair *result = (Pair*)malloc(sizeof(Pair) * n);
    int resultSize;
    Pair__mergeOverlap(arr, n, result, &resultSize);

#ifdef DEBUG
    printf("resultSize: %d\n", resultSize);
    printf("result: \n");
    for (int i = 0; i < resultSize; i++)
        printf("%d %d\n", result[i].first, result[i].second);
    printf("\n");
#endif
    printf("%d\n", resultSize * 2);

    return 0;
}