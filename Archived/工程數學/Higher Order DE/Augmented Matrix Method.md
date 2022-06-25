標籤: #工程數學 

---

# examples

以下是求解 [[Eigenvector]] 的例子，給定一個矩陣 $A - \lambda I$

## example 1

$$
\left(
\begin{array}{}
	-2k & k & k \\
	k & -2k & k \\
	k & k & -2k
\end{array}
\right\vert
\left.
\begin{array}{}
	0 \\
	0 \\
	0 
\end{array}
\right)
$$

$$
\implies
\left(
	\begin{array}{}
		-2 & 1 & 1 \\
		1 & -2 & 1 \\
		1 & 1 & -2
	\end{array}
\right\vert
\left.
	\begin{array}{}
		0 \\
		0 \\
		0
	\end{array}
\right)
$$

用第一列去削掉下面二、三列的第一行

$$
\implies
\left(
\begin{array}{}
	-2 & 1 & 1 \\
	0 & -1.5 & 1.5 \\
	0 & 1.5 & -1.5
\end{array}
\right\vert
\left.
\begin{array}{}
	0 \\
	0 \\
	0
\end{array}
\right)
$$

消去第三列並整理第二列

$$
\implies
\left(
\begin{array}{}
	-2 & 1 & 1 \\
	0 & -1 & 1 \\
	0 & 0 & 0
\end{array}
\right\vert
\left.
\begin{array}{}
	0 \\
	0 \\
	0
\end{array}
\right)
$$

用第二列整理第一列

$$
\implies
\left(
\begin{array}{}
	-2 & 0 & 2 \\
	0 & -1 & 1 \\
	0 & 0 & 0
\end{array}
\right\vert
\left.
\begin{array}{}
	0 \\
	0 \\
	0
\end{array}
\right)
$$

乘上一個數做整理

$$
\implies
\left(
\begin{array}{}
	1 & 0 & -1 \\
	0 & 1 & -1 \\
	0 & 0 & 0
\end{array}
\right\vert
\left.
\begin{array}{}
	0 \\
	0 \\
	0
\end{array}
\right)
$$

把結果乘上 $\vec{x}$

$$
\left\{
	\begin{array}{}
		x_1 & &     & - & x_3 & = & 0 \\
		    & & x_2 & - & x_3 & = & 0 
	\end{array}
\right.
$$

$$
\implies x_1 = x_2 = x_3
$$

$$
\implies \vec{x} = 
\left[
	\begin{array}{}
		1 \\
		1 \\
		1
	\end{array}
\right]
$$

## example 2

$$
\left(
	\begin{array}{}
		k & k & k \\
		k & k & k \\
		k & k & k
	\end{array}
\right\vert
\left.
	\begin{array}{}
		0 \\
		0 \\
		0
	\end{array}
\right)
$$

$$
\implies
\left(
	\begin{array}{}
		1 & 1 & 1 \\
		0 & 0 & 0 \\
		0 & 0 & 0
	\end{array}
\right\vert
\left.
	\begin{array}{}
		0 \\
		0 \\
		0
	\end{array}
\right)
$$

$$
\implies
x_1 + x_2 + x_3 = 0
$$

$$
\implies
\vec{x} = 
\left[
	\begin{array}{}
		-x_2 - x_3 \\
		x_2 \\
		x_3
	\end{array}
\right]
$$

$$
\vec{x} = 
c_2
\left[
	\begin{array}{}
		-1 \\
		1 \\
		0
	\end{array}
\right]
+
c_3
\left[
	\begin{array}{}
		-1 \\
		0 \\
		1
	\end{array}
\right]
$$

---

參考資料:

工程數學PPT topic 4.0 & 4.1

---

link:

[[Augmented Matrix]]