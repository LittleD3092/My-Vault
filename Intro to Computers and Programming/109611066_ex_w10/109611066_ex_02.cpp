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

struct matrix
{
    struct TwoDArray array;
};

void matrix__constructor(struct matrix* mat, int row, int col)
{
    TwoDArray__constructor(&(mat->array), row);
    for(int i = 0; i < row; i++)
    {
        TwoDArray__resizeCol(&(mat->array), i, col, 0);
    }
}

void matrix__set(struct matrix* mat, int row, int col, int value)
{
    TwoDArray__set(&(mat->array), row, col, value);
}

int matrix__get(struct matrix* mat, int row, int col)
{
    return mat->array.ptr[row][col];
}

int** matrix__multiplication(int **mat1, int **mat2, int m, int n, int p)
{
    struct matrix result;
    matrix__constructor(&result, m, p);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            int value = 0;
            for(int k = 0; k < n; k++)
            {
                value += mat1[i][k] * mat2[k][j];
            }
            matrix__set(&result, i, j, value);
        }
    }

    free(result.array.length);
    return result.array.ptr;
}

int main()
{
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    struct matrix A, B;
    matrix__constructor(&A, m, n);
    matrix__constructor(&B, n, p);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int value;
            scanf("%d", &value);
            matrix__set(&A, i, j, value);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            int value;
            scanf("%d", &value);
            matrix__set(&B, i, j, value);
        }
    }

    int** result = matrix__multiplication(A.array.ptr, B.array.ptr, m, n, p);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
            printf("%d ", result[i][j]);
        
        printf("\n");
    }
    return 0;
}