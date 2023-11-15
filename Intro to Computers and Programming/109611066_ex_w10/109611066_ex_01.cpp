#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct TwoDArray
{
    int** ptr;
    int* length;
    int row;
};

int min(int num1, int num2)
{
    return num1 > num2 ? num2 : num1;
}

void TwoDArray__constructor(struct TwoDArray* array, int row)
{
    array->ptr = (int**)calloc(row, sizeof(int*));
    array->length = (int*)calloc(row, sizeof(int));
    for (int i = 0; i < row; i++)
    {
        (array->ptr)[i] = (int*)calloc(1, sizeof(int));
    }
    array->row = row;
}

void TwoDArray__resizeCol(struct TwoDArray* array, int row, int size, int initValue)
{
    int* tmp = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < min(size, array->length[row]); i++)
    {
        tmp[i] = array->ptr[row][i];
    }
    if (size > array->length[row])
    {
        for (int i = array->length[row]; i < size; i++)
            tmp[i] = initValue;
    }
    free(array->ptr[row]);
    array->ptr[row] = tmp;
    array->length[row] = size;
}

void TwoDArray__printArray(struct TwoDArray* array)
{
    for (int i = 0; i < array->row; i++)
    {
        for (int j = 0; j < array->length[i]; j++)
        {
            printf("%d ", array->ptr[i][j]);
        }
        printf("\n");
    }
}

void TwoDArray__set(struct TwoDArray* array, int row, int col, int value)
{
    array->ptr[row][col] = value;
}

void TwoDArray__resizeRow(struct TwoDArray* array, int row, int initLen, int initValue)
{
    struct TwoDArray tmp;
    TwoDArray__constructor(&tmp, row);
    for (int i = 0; i < row; i++)
    {
        if (i < array->row)
        {
            TwoDArray__resizeCol(&tmp, i, array->length[i], 0);
            for(int j = 0; j < array->length[i]; j++)
                tmp.ptr[i][j] = array->ptr[i][j];
        }
        else
        {
            TwoDArray__set(&tmp, i, 0, initValue);
            TwoDArray__resizeCol(&tmp, i, initLen, initValue);
        }
    }

    for (int i = 0; i < array->row; i++)
        free(array->ptr[i]);
    free(array->ptr);
    free(array->length);
    array->ptr = tmp.ptr;
    array->length = tmp.length;
    array->row = tmp.row;
}

void TwoDArray__deleteRow(struct TwoDArray* array, int row)
{
    free(array->ptr[row]);
    for (int i = row; i < array->row - 1; i++)
    {
        array->ptr[i] = array->ptr[i + 1];
    }
    for (int i = row; i < array->row - 1; i++)
    {
        array->length[i] = array->length[i + 1];
    }
    array->row -= 1;
}

int main()
{
    int N;
    printf("input N: ");
    scanf("%d", &N);

    struct TwoDArray A;
    TwoDArray__constructor(&A, N);
    printf("step 1:\n");
    printf("input N numbers: ");
    for (int i = 0; i < N; i++)
    {
        int length;
        scanf("%d", &length);
        TwoDArray__resizeCol(&A, i, length, 0);
    }
    TwoDArray__printArray(&A);

    int R, S;
    printf("step 2:\n");
    printf("input R and S: ");
    scanf("%d %d", &R, &S);
    TwoDArray__resizeCol(&A, R - 1, S, 1);
    TwoDArray__printArray(&A);

    int N2;
    printf("step 3:\n");
    printf("input N2: ");
    scanf("%d", &N2);
    TwoDArray__resizeRow(&A, N2, 2, 2);
    TwoDArray__printArray(&A);

    int D;
    printf("step 4:\n");
    printf("input D: ");
    scanf("%d", &D);
    TwoDArray__deleteRow(&A, D - 1);
    TwoDArray__printArray(&A);

    return 0;
}