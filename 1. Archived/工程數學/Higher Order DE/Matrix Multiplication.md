標籤: #工程數學 #algorithm 

---

[TOC]

---

# Engineering Mathematics

給定三個矩陣
$$A = [a_{ jk }], \; B = [b_{ jk }], \; C = [c_{ jk }]$$
$$C = AB$$
.
$C$ 會等於橫的乘上直的
$$C_{ jk } = \sum_{ m = 1 }^{ n } a_{ jm }b_{ mk }$$

## 例子

$$
\left[ 
\begin{array}{}
9 & 3 \\
-2 & 0
\end{array}
\right]
\left[
\begin{array}{}
1 & -4 \\
2 & 5
\end{array}
\right]
 = 
\left[
\begin{array}{}
9 \cdot 1 + 3 \cdot 2 & 9 \cdot (-4) + 3 \cdot 5 \\
-2 \cdot 1 + 0 \cdot 2 & (-2) \cdot (-4) + 0 \cdot 5
\end{array}
\right]
 = 
\left[
\begin{array}{}
15 & -21 \\
-2 & 8
\end{array}
\right]
$$

> 注意:
> $$AB \neq BA$$
> 矩陣乘法不能前後交換

# Algorithm

If $A = (a_{ij})$ and $B = (b_{ij})$ are square $n\times n$ matrices, then in the product $C = A\cdot B$, we define the entry $c_{ij}$ by:

$$c_{ij} = \sum_{k = 1}^n a_{ik} \cdot b_{kj}$$

By the above definition, we can have the algorithm below:

$$
\begin{array}{rl}
	& \text{SQUARE-MATRIX-MULTIPLY } (A, B) \\
	1 & n = A.rows \\
	2 & \text{let }C \text{ be a new } n\times n \text{ matrix} \\
	3 & \text{\bf for }i = 1 \text{ \bf to } n \\
	4 & \qquad \text{\bf for }j = 1 \text{ \bf to } n \\
	5 & \qquad \qquad c_{ij} = 0 \\
	6 & \qquad \qquad \text{\bf for } k = 1 \text{ \bf to }n \\
	7 & \qquad \qquad \qquad c_{ij} = c_{ij} + a_{ik} \cdot b_{kj} \\
	8 & \text{\bf return }C
\end{array}
$$

Because each of the tripply-nested for loops run exactly $n$ iterations, the $\text{SQUARE-MATRIX-MULTIPLY}$ procedure runs $\Theta(n^3)$ time.

## Simple Divide-and Conquer

We can divide the matrices $A, B, C$ each into four matrices:

$$A = \left(
	\begin{array}{}
		A_{11} & A_{12} \\
		A_{21} & A_{22}
	\end{array}
\right)$$

$$B = \left(
	\begin{array}{}
		B_{11} & B_{12} \\
		B_{21} & B_{22}
	\end{array}
\right)$$

$$
C = \left(
	\begin{array}{}
		C_{11} & C_{12} \\
		C_{21} & C_{22}
	\end{array}
\right)
$$

So that $C = A\cdot B$ becomes:

$$
\left(
	\begin{array}{}
		C_{11} & C_{12} \\
		C_{21} & C_{22}
	\end{array}
\right) = 
\left(
	\begin{array}{}
		A_{11} & A_{12} \\
		A_{21} & A_{22}
	\end{array}
\right)
\cdot
\left(
	\begin{array}{}
		B_{11} & B_{12} \\
		B_{21} & B_{22}
	\end{array}
\right)

$$

The above equation corresponds to the four equations:

$$
\left\{
	\begin{array}{l}
		C_{11} & = & A_{11} \cdot B_{11} & + & A_{12} \cdot B_{21}, \\
		C_{12} & = & A_{11} \cdot B_{12} & + & A_{12} \cdot B_{22}, \\
		C_{21} & = & A_{21} \cdot B_{11} & + & A_{22} \cdot B_{21}, \\
		C_{22} & = & A_{21} \cdot B_{12} & + & A_{22} \cdot B_{22}.
	\end{array}
\right.
$$

We can use these equations to create a straightforward and recursive algorithm:

$$
\begin{array}{rl}
	& \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE } (A, B) \\
	1 & n = A.rows \\
	2 & \text{let } C \text{ be a new } n\times n \text{ matrix} \\
	3 & \textbf{if } n==1 \\
	4 & \qquad c_{11} = a_{11} \cdot b_{11} \\
	5 & \textbf{else } \text{partition }A, B, \text{and } C \text{ as in above equation} \\
	6 & \qquad C_{11} = \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{11}, B_{11}) \\
	& \qquad\qquad + \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{12}, B_{21}) \\
	
	7 & \qquad C_{12} = \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{11}, B_{12}) \\
	& \qquad\qquad + \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{12}, B_{22}) \\
	8 & \qquad C_{21} = \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{21}, B_{11}) \\
	& \qquad\qquad + \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{22}, B_{21}) \\
	9 & \qquad C_{22} = \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{21}, B_{12}) \\
	& \qquad\qquad + \text{SQUARE-MATRIX-MULTIPLY-RECURSIVE }(A_{22}, B_{22}) \\
	10 & \textbf{return }C
\end{array}
$$

> When implementing the above algorithm, we can use index calculations to speed up.

The time of the case $n \text{ != } 1$:

$$T(n) = \underbrace{
	\Theta(1)
}_{
	\begin{array}{}
		\text{partition}\\
		\text{matrix} \\
		\text{(using idex }\\
		\text{calculation)}
	\end{array}
} + \underbrace{8T(n / 2)}_{
	\begin{array}{}
		8 \text{ recursive} \\
		\text{functions}
	\end{array}
} + \underbrace{\Theta(n^2)}_{
	\begin{array}{}
		\text{matrix} \\ 
		\text{addition} \\
		\text{(line 6 to 9)}
	\end{array}
}$$

$$
T(n) = 
\left\{
	\begin{array}{l}
		\Theta(1) & \text{if } n = 1, \\
		8T(n / 2) + \Theta(n^2) & \text{if } n > 1.
	\end{array}
\right.
$$

## Strassen's Method

The strassen's method uses 7 multiplications for two $2\times 2$ matrix multiplication, instead of eight. However, it uses more addition (still only a constant number).

It has four steps:

1. Divide each of the matrices into four submatrices:

$$
\left(
	\begin{array}{}
		C_{11} & C_{12} \\
		C_{21} & C_{22}
	\end{array}
\right) = 
\left(
	\begin{array}{}
		A_{11} & A_{12} \\
		A_{21} & A_{22}
	\end{array}
\right)
\cdot
\left(
	\begin{array}{}
		B_{11} & B_{12} \\
		B_{21} & B_{22}
	\end{array}
\right)
$$

2. Create 10 matrices $S_1, S_2, \dots, S_{10}$, each of which is the sum or difference of two matrices created in step 1.

$$
\begin{array}{}
	S_1 & = & B_{12} - B_{22} \\
	S_2 & = & A_{11} + A_{12} \\
	S_3 & = & A_{21} + A_{22} \\
	S_4 & = & B_{21} - B_{11} \\
	S_5 & = & A_{11} + A_{22} \\
	S_6 & = & B_{11} + B_{22} \\
	S_7 & = & A_{12} - A_{22} \\
	S_8 & = & B_{21} + B_{22} \\
	S_9 & = & A_{11} - A_{21} \\
	S_{10} & = & B_{11} + B_{12}
\end{array}
$$

3. Using the submatrices created in step 1 and 10 matrices created in step 2, compute 7 matrix products $P_1, P_2, \dots, P_7$:

$$
\begin{array}{l}
	P_1 & = & 
	A_{11} \cdot S_1 & = & 
	A_{11} \cdot B_{12} - A_{11} \cdot B_{22} \\
	
	P_2 & = & 
	S_2 \cdot B_{22} & = & 
	A_{11} \cdot B_{22} + A_{12} \cdot B_{22} \\
	
	P_3 & = & 
	S_3 \cdot B_{11} & = &
	A_{21} \cdot B_{11} + A_{22} \cdot B_{11} \\

	P_4 & = & 
	A_{22} \cdot S_4 & = &
	A_{22} \cdot B_{21} - A_{22} \cdot B_{11} \\

	P_5 & = & 
	S_5 \cdot S_6 & = &
	A_{11} \cdot B_{11} + A_{11} \cdot B_{22} + A_{22} \cdot B_{11} + A_{22} \cdot B_{22} \\

	P_6 & = & 
	S_7 \cdot S_8 & = &
	A_{12} \cdot B_{21} + A_{12} \cdot B_{22} - A_{22} \cdot B_{21} - A_{22} \cdot B_{22} \\

	P_7 & = &
	S_9 \cdot S_{10} & = &
	A_{11} \cdot B_{11} + A_{11} \cdot B_{12} - A_{21} \cdot B_{11} - A_{21} \cdot B_{12}
\end{array}
$$

4. Compute the desired submatrices $C_1, C_2, C_3, C_4$.

$$
\begin{array}{l}
	C_{11} & = & P_5 + P_4 - P_2 + P_6 \\
	C_{12} & = & P_1 + P_2 \\
	C_{21} & = & P_3 + P_4 \\
	C_{22} & = & P_5 + P_1 - P_3 - P_7
\end{array}
$$

This algorithm has time complexity:

| Steps  | Time Complexity     |
| ------ | ------------------- |
| Step 1 | $\Theta(1)$         |
| Step 2 | $\Theta(n^2)$       |
| Step 3 | $\Theta(n^{\lg 7})$ |
| Step 4 | $\Theta(n^2)$       | 

> For step 3:
> We have the recurrence for the running time $T(n)$ of Strassen's algorithm:
> $$T(n) = \left\{ \begin{array}{l} \Theta(1) & \text{if } n = 1 \\ 7T(n/2) + \Theta(n^2) & \text{if } n > 1 \end{array} \right.$$
> By master's theorem, the time complexity is:
> $$T(n) = \Theta(n^{\lg 7})$$

---

參考資料:

工程數學課本
Introduction to Algorithm, third edition

---

link:

[[Divide-and-Conquer Approach]]