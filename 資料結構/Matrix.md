標籤: #DataStructure 

---

[TOC]

---

# Sparse

When we look at the matrix below, 

$$
\left[
	\begin{array}{}
		& \text{\bf col 0} & \text{\bf col 1} & 
		\text{\bf col 2} & \text{\bf col 3} & 
		\text{\bf col 4} & \text{\bf col 5} \\
		\text{\bf row 0} & 15 & 0 & 0 & 22 & 0 & -15 \\
		\text{\bf row 1} & 0 & 11 & 3 & 0 & 0 & 0 \\
		\text{\bf row 2} & 0 & 0 & 0 & -6 & 0 & 0 \\
		\text{\bf row 3} & 0 & 0 & 0 & 0 & 0 & 0 \\
		\text{\bf row 4} & 91 & 0 & 0 & 0 & 0 & 0 \\
		\text{\bf row 5}& 0 & 0 & 28 & 0 & 0 & 0
	\end{array}
\right]
$$

we see that it has many zero entries. Such a matrix is called *sparse*. There is no precise definition of when a matrix is sparse and when it is not, but it is a concept.

A sparse matrix requires us to think of an alternative form of representation. For example, we have $5000 \times 5000$ matrix but only $5000$ out of $25$ million spaces are nonzero. If we use 2-dimentional array to store it, we would request much more spaces than we needed.

# Abstract Data Type

```cpp
class SparseMatrix
// A set of triples, <row, column, value>, 
// where row and column are non-negative 
// integers and form a unique combination;
// value is also an integer.
{
public:
	SparseMatrix(int r, int c, int t);
	// The constructor function creates a SparseMatrix with
	// r rows, c columns, and a capacity of t nonzero terms.

	SparseMatrix Transpose();
	// Returns the SparseMatrix obtained by interchanging 
	// the row and column value of every triple in *this.

	SparseMatrix Add(SparseMatrix b);
	// If the dimensions of *this and b are the same,
	// then the matrix produced by adding corresponding items,
	// namely those with identical row and column values is returned;
	// otherwise, an exception is thrown.

	SparseMatrix Multiply(SparseMatrix b);
	// If the number of columns in *this equals the number of rows 
	// in b then the matrix d produced by multiplying *this and b 
	// according to the formula d[i][j] = \sum(a[i][k]*b[k][j]),
	// where d[i][j] is the (i, j)th element, is returned.
	// k ranges from 0 to one less than the number of columns in 
	// *this; otherwise, an exception is thrown.
};
```

# Representation

We may use the triple `<row, col, value>` to characterize any element in the matrix. This means that we may use an array of triples to represent a sparse matrix.

Also, we require that these triples be stored by rows with the triples for the first row first, followed by those of the second row, and so on. We also require that all the triples for any row be stored so that the column indices are in ascending order.

In addition, to ensure that the operations terminate, we must know the numbers of rows and columns and the number of nonzero elements in the matrix.

Putting all this information together suggests that we define:

```cpp
class SparseMatrix; // forward declaration

class MatrixTerm
{
friend SparseMatrix;
private:
	int row, col, value;
};
```

and in class `SparseMatrix`:

```cpp
private:
	int rows, cols, terms, capacity;
	MatrixTerm *smArray;
```

Therefore we may represent the matrix mentioned above

> The matrix mentioned above:
> $$
> \left[
> 	\begin{array}{}
> 		& \text{\bf col 0} & \text{\bf col 1} & 
> 		\text{\bf col 2} & \text{\bf col 3} & 
> 		\text{\bf col 4} & \text{\bf col 5} \\
> 		\text{\bf row 0} & 15 & 0 & 0 & 22 & 0 & -15 \\
> 		\text{\bf row 1} & 0 & 11 & 3 & 0 & 0 & 0 \\
> 		\text{\bf row 2} & 0 & 0 & 0 & -6 & 0 & 0 \\
> 		\text{\bf row 3} & 0 & 0 & 0 & 0 & 0 & 0 \\
> 		\text{\bf row 4} & 91 & 0 & 0 & 0 & 0 & 0 \\
> 		\text{\bf row 5}& 0 & 0 & 28 & 0 & 0 & 0
> 	\end{array}
> \right]
> $$

to the representation below:

| `smArray` | row | col | value |
| --------- | --- | --- | ----- |
| `[0]`     | 0   | 0   | 15    |
| `[1]`     | 0   | 3   | 22    |
| `[2]`     | 0   | 5   | -15   |
| `[3]`     | 1   | 1   | 11    |
| `[4]`     | 1   | 2   | 3     |
| `[5]`     | 2   | 3   | -6    |
| `[6]`     | 4   | 0   | 91    |
| `[7]`     | 5   | 2   | 28    |


# Transposing

```cpp
SparseMatrix SparseMatrix::Transpose()
// Return the transpose of *this.
{
	SparseMatrix b(cols, rows, terms); // capacity of b.smArray is 
									   // terms
	if(terms > 0)
	// nonzero matrix
	{
		int currentB = 0;
		for(int c = 0; c < cols; c++) // transpose by columns
			for(int i = 0; i < terms; i++)
			// find and move terms in column c
				if(smArray[i].col == c)
				{
					b.smArray[currentB].row = c;
					b.smArray[currentB].col = smArray[i].row;
					b.smArray[currentB++].value = smArray[i].value;
				}
	} // end of if(terms > 0)
	return b;
}
```

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Archived/工程數學/Linear Algebra/Matrix]]