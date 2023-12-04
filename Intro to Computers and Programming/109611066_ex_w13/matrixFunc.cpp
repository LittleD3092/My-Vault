#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// construct the matrix by given row and column
matrix2D* matrix2D_construct(int m, int n) {
    matrix2D* A = (matrix2D*)malloc(sizeof(matrix2D));
    A->row = m;
    A->column = n;
    A->mat = (vector*)malloc(sizeof(vector) * m);
    for (int i = 0; i < m; i++) {
        vector* v = vector_construct(n);
        A->mat[i] = *v;
        free(v);
    }
    return A;
}

// fill the matrix with specific number
void matrix2D_fillwith(matrix2D* A, int num) {
    for(int i = 0; i < A->row; i++) {
        for(int j = 0; j < A->column; j++) {
            A->mat[i].vec[j] = num;
        }
    }
}

// multiply 2 matrix
// if they can't multiple together, print "Shape Error"
matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B) {
    if (A->column != B->row) {
        printf("Shape Error\n");
        return NULL;
    }
    matrix2D* C = matrix2D_construct(A->row, B->column);
    for (int i = 0; i < A->row; i++) {
        for (int j = 0; j < B->column; j++) {
            for (int k = 0; k < A->column; k++) {
                C->mat[i].vec[j] += A->mat[i].vec[k] * B->mat[k].vec[j];
            }
        }
    }
    return C;
}

// print function
void print_matrix(matrix2D* A) {
    for (int i = 0; i < A->row; i++) {
        for (int j = 0; j < A->column; j++) {
            printf("%d ", A->mat[i].vec[j]);
        }
        printf("\n");
    }
}