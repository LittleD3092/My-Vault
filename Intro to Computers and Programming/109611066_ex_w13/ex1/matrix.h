#ifndef __matrix__
#define __matrix__

#include "vector.h"

typedef struct _matrix2D {
	int row, column;
	vector* mat;

}matrix2D;

// to construct the matrix by given row and column
matrix2D* matrix2D_construct(int m, int n);

// fill the matrix with specific number
void matrix2D_fillwith(matrix2D* A, int num);

// check 2 matrix with the right shape,
// if they can multiple together, return the result, or print "Shape Error"
matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B);

// print function
void print_matrix(matrix2D* A);

#endif



