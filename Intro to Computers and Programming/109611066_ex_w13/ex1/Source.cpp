#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"

int main()
{
    matrix2D* A, * B;
    int A_row, A_column, B_row, B_column, A_number, B_number;
    scanf("%d %d %d %d %d %d", &A_row, &A_column, &B_row, &B_column, &A_number, &B_number);
    A = matrix2D_construct(A_row, A_column);
    B = matrix2D_construct(B_row, B_column);
    matrix2D_fillwith(A, A_number);
    matrix2D_fillwith(B, B_number);
    matrix2D* C = matrix2D_multiple(A, B);
    if (C) {
        print_matrix(C);
    }
    return 0;
}
