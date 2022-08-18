標籤: #工程數學 

---

# Operation

## Addition

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

## [[Matrix Multiplication|Multiplications]]

### Scalar Multiply

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

### Matrix Multiply

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

#### Rules

- $AB \neq BA$
- $(kA)B = k(AB)$
- $(AB)C = A(BC)$
- $(A + B)C = AC + BC$
- $C(A + B) = CA + CB$

### Array Multiplication (Element-wise Multiplication)

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

## [[Matrix Transposition|Transpose]]

$$A = [a_{ ji }] \ \rightarrow \ A^T = [a_{ ij }]$$

- $(A^T)^T = A$
- $(A + B)^T = A^T + B^T$
- $(cA)^T = cA^T$
- $(AB)^T = B^T A^T$

## [[Inverse of Matrix]]

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

### Rules

1. $A$ must be square
2. Even $A$ is square, $A^{ -1 }$ might not exist ($A$ is singular)
If $A$ exist, $A$ is non-singular
3. Product properties
	1. $(AC)^{ -1 } = C^{ -1 }A^{ -1 }$
	2. $AB = 0$ does not mean $A = 0$ or $B = 0$
	3. $AC = AD$ does not mean $C = D$ (even if $A \neq 0$)
4. $\det(AB) = \det(A) \times \det(B)$

# Others

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

# Transform Vectors

$$\vec{ v }_{ \text{ out } } = A \vec{ v }_{ \text{ in } }$$

- Vectors whose direction is not changed by the transformation $A$ are called [[Eigenvector]] of $A$
- [[Eigenvalue]] are the multiples by which $A$ changes the eigenvector

## Scaling-Matrix

$$
A = 
\left[
	\begin{array}{}
		s_x & 0 \\
		0 & s_y
	\end{array}
\right]
$$



## Rotation-Matrix

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

---

參考資料:

工程數學上課

---

link:

[[Eigenvalue]]
[[Eigenvector]]
[[Augmented Matrix]]