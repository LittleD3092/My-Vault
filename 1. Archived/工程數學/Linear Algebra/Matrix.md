標籤: #工程數學 #DataStructure 

---

[TOC]

---

# Engineering Mathematics

## Operation

### Addition

$$\left[ 
\begin{array}{}
a_{ 11 } & a_{ 12 } \\
a_{ 21 } & a_{ 22 }
\end{array}
\right] + 
\left[
\begin{array}{}
b_{ 11 } & b_{ 12 } \\
b_{ 21 } & b_{ 22 }
\end{array}
\right] = 
\left[
\begin{array}{}
a_{ 11 } + b_{ 11 } & a_{ 12 } + b_{ 12 } \\
a_{ 21 } + b_{ 21 } & a_{ 22 } + b_{ 22 }
\end{array}
\right]$$

### [[Matrix Multiplication|Multiplications]]

#### Scalar Multiply

$$
b
\left[
\begin{array}{}
a_{ 11 } & a_{ 12 } \\
a_{ 21 } & a_{ 22 }
\end{array}
\right] = 
\left[
\begin{array}{}
ba_{ 11 } & ba_{ 12 } \\
ba_{ 21 } & ba_{ 22 }
\end{array}
\right]
$$

#### Matrix Multiply

$$
\left[
\begin{array}{}
a_{ 11 } & a_{ 12 } \\
a_{ 21 } & a_{ 22 } \\
a_{ 31 } & a_{ 32 }
\end{array}
\right] *
\left[
\begin{array}{}
b_{ 11 } & b_{ 12 } & b_{ 13 } \\
b_{ 21 } & b_{ 22 } & b_{ 23 }
\end{array}
\right]
$$

上面的矩陣是 $3\times 2$ 和 $2\times 3$ 的，如果要可以乘起來 $a\times b \text{ and } c \times d$ 兩個陣列的 $b$ 和 $c$ 必須相等(在這個情況是 $2$ )，並且最後的結果會是 $a\times d$ (在這個情況是 $3\times 3$ )

法則: 橫的乘上直的加起來

##### Rules

- $AB \neq BA$
- $(kA)B = k(AB)$
- $(AB)C = A(BC)$
- $(A + B)C = AC + BC$
- $C(A + B) = CA + CB$

#### Array Multiplication (Element-wise Multiplication)

$$A \ _.* B = 
\left[
\begin{array}{}
a_{ 11 } & a_{ 12 } \\
a_{ 21 } & a_{ 22 }
\end{array}
\right] \ _.*
\left[
\begin{array}{}
b_{ 11 } & b_{ 12 } \\
b_{ 21 } & b_{ 22 }
\end{array}
\right] = 
\left[
\begin{array}{}
a_{ 11 }b_{ 11 } & a_{ 12 }b_{ 12 } \\
a_{ 21 }b_{ 21 } & a_{ 22 }b_{ 22 }
\end{array}
\right]$$

### [[Matrix Transposition|Transpose]]

$$A = [a_{ ji }] \ \rightarrow \ A^T = [a_{ ij }]$$

- $(A^T)^T = A$
- $(A + B)^T = A^T + B^T$
- $(cA)^T = cA^T$
- $(AB)^T = B^T A^T$

### [[Inverse of Matrix]]

Use Gauss-Jordan Elimination

$$[ A \vert I ] \overset{ \text{ row operation } }{ \implies } [ I \vert A^{ -1 } ]$$

### e.g.

$$
A = 
\left[ 
\begin{array}{}
-1 & 1 & 2 \\
2 & -1 & 1 \\
-1 & 1 & 3
\end{array}
\right]
$$

$$
[A\vert I] = 
\left[
	\begin{array}{}
		-1 & 1 & 2 \\
		2 & -1 & 1 \\
		-1 & 1 & 3
	\end{array}
\right.
\left\vert
	\begin{array}{}
		1 & 0 & 0 \\
		0 & 1 & 0 \\
		0 & 0 & 1
	\end{array}
\right]
$$

$$
=
\left[
	\begin{array}{}
		-1 & 1 & 2 \\
		0 & 1 & 5 \\
		0 & 0 & 1
	\end{array}
\right.
\left\vert
	\begin{array}{}
		1 & 0 & 0 \\
		2 & 1 & 0 \\
		-1 & 0 & 1
	\end{array}
\right]
$$

$$
=
\left[
	\begin{array}{}
		-1 & 1 & 0 \\
		0 & 1 & 0 \\
		0 & 0 & 1
	\end{array}
\right.
\left\vert
	\begin{array}{}
		3 & 0 & -2 \\
		7 & 1 & -5 \\
		-1 & 0 & 1
	\end{array}
\right]
$$

$$
=
\left[
	\begin{array}{}
		-1 & 0 & 0 \\
		0 & 1 & 0 \\
		0 & 0 & 1
	\end{array}
\right.
\left\vert
	\begin{array}{}
		-4 & -1 & 3 \\
		7 & 1 & -5 \\
		-1 & 0 & 1
	\end{array}
\right]
$$

$$
=
\left[
	\begin{array}{}
		1 & 0 & 0 \\
		0 & 1 & 0 \\
		0 & 0 & 1
	\end{array}
\right.
\left\vert
	\begin{array}{}
		4 & 1 & -3 \\
		7 & 1 & -5 \\
		-1 & 0 & 1
	\end{array}
\right]
$$

$$
\implies
A^{ -1 } = 
\left[
	\begin{array}{}
		4 & 1 & -3 \\
		7 & 1 & -5 \\
		-1 & 0 & 1
	\end{array}
\right]
$$

#### Rules

1. $A$ must be square
2. Even $A$ is square, $A^{ -1 }$ might not exist ($A$ is singular)
If $A$ exist, $A$ is non-singular
3. Product properties
	1. $(AC)^{ -1 } = C^{ -1 }A^{ -1 }$
	2. $AB = 0$ does not mean $A = 0$ or $B = 0$
	3. $AC = AD$ does not mean $C = D$ (even if $A \neq 0$)
4. $\det(AB) = \det(A) \times \det(B)$

## Others

- Symmetric

$$A^T = A$$

- Skew Symmetric 

$$A^T = -A$$

- Diagnol Matrix

$$\left[
\begin{array}{}
a & 0 & 0 \\
0 & b & 0 \\
0 & 0 & c
\end{array}
\right]$$

- Identity Matrix

$$
I = 
\left[
\begin{array}{}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{array}
\right]
$$

- [[Orthogonal Matrix]]

$$A^T = A^{ -1 }$$

> 也可以用這個條件判斷是否為 Orthogonal Matrix
> $$\det(A) = 1 \text{ or } -1$$

## Transform Vectors

$$\vec{ v }_{ \text{ out } } = A \vec{ v }_{ \text{ in } }$$

- Vectors whose direction is not changed by the transformation $A$ are called [[Eigenvector]] of $A$
- [[Eigenvalue]] are the multiples by which $A$ changes the eigenvector

### Scaling-Matrix

$$
A = 
\left[
	\begin{array}{}
		s_x & 0 \\
		0 & s_y
	\end{array}
\right]
$$



### Rotation-Matrix

$$
A = 
\left[
	\begin{array}{}
		\cos \theta & -\sin \theta \\
		\sin \theta & \cos \theta
	\end{array}
\right]
$$

$$\text{ rotate counter clockwise } \theta \degree$$

# Data Structure

## Sparse

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

## Abstract Data Type

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

## Representation

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


## Transposing

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

工程數學上課
Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Eigenvalue]]
[[Eigenvector]]
[[Augmented Matrix]]