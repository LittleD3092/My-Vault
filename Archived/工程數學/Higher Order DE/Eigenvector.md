標籤: #工程數學 

---

$$Ax = \lambda x$$
$A$: $n \times n$ matrix
$\lambda$: scalar
$x$: any vector

在上面式子的 $\lambda$ 就是 $A$ 的 [[Eigenvalue]]，$x$ 就是 Eigenvector

# 求解 eigenvector

將定義移向

$$Ax = \lambda x \implies (A - \lambda I)x = 0$$

以矩陣表示

$$
\left[
\begin{array}{}
a_{ 11 } - \lambda & a_{ 12 } \\
a_{ 21 }           & a_{ 22 } - \lambda
\end{array}
\right]
\left[
\begin{array}{}
x_1 \\
x_2
\end{array}
\right]
=
\left[
\begin{array}{}
0 \\
0
\end{array}
\right]
$$

先求出 [[Eigenvalue]]，帶入上式並使用 [[Augmented Matrix Method]] 就可以解出 eigenvector

# Transformation as a linear combination of eigenvector

$$
A = 
\left[
	\begin{array}{}
		2 & 0 \\
		0 & 1
	\end{array}
\right]
$$

$$
A\vec{ P } = 
\left[
	\begin{array}{}
		2 & 0 \\
		0 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		3 \\
		4
	\end{array}
\right] = 
\left[
	\begin{array}{}
		6 \\
		4
	\end{array}
\right]
$$

$$
\begin{array}{}
	\text{ A 的 } & \text{ eigenvalue: } & \lambda_1 = 2, \lambda_2 = 1 \\
	& \text{ eigenvector: } & \vec{ x }^{ (1) } = \left[ \begin{array}{} 1 \\ 0 \end{array} \right] \\
	& & \vec{ x }^{ (2) } = \left[ \begin{array}{} 0 \\ 1 \end{array} \right]
\end{array}
$$

$$
\vec{ P } = 
\left[
	\begin{array}{}
		3 \\
		4
	\end{array}
\right] = 3
\left[
	\begin{array}{}
		1 \\
		0
	\end{array}
\right] + 4
\left[
	\begin{array}{}
		0 \\
		1
	\end{array}
\right]
$$

$$
A \vec{ P } = 3 \lambda_1
\left[
	\begin{array}{}
		1 \\
		0
	\end{array}
\right] + 4\lambda_2
\left[
	\begin{array}{}
		0 \\
		1
	\end{array}
\right]
$$

可以用 [[Eigenvalue]] 把 eigenvector 的線性組合轉換

---

虛數的算法

$$
R = 
\left[
	\begin{array}{}
		\cos\theta & -\sin\theta \\
		\sin\theta & \cos\theta
	\end{array}
\right] \quad ; \quad \theta = 90\degree
$$

$$
= \left[
	\begin{array}{}
		0 & -1 \\
		1 & 0
	\end{array}
\right] \quad , \quad \text{ skew symmetric }
$$

$$
\begin{array}{}
	\lambda_1 = i & \vec{ v }_{ eig }^{ (1) } = \left[ \begin{array}{} i \\ 1 \end{array} \right] \\
	\lambda_2 = -i & \vec{ v }_{ eig }^{ (2) } = \left[ \begin{array}{} -i \\ 1 \end{array} \right]
\end{array}
$$

$$
\vec{ P } = 
\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
\right] = \frac{ 1 }{ 2 } \left( \left[ \begin{array}{} i \\ 1 \end{array} \right] + \left[ \begin{array}{} -i \\ 1 \end{array} \right] \right) + \frac{ 1 }{ 2 }\left( -i 
\left[
	\begin{array}{}
		i \\
		1
	\end{array}
\right] + i
\left[
	\begin{array}{}
		-i \\
		1
	\end{array}
\right]\right)
$$

$$
= \frac{ 1 }{ 2 }(1 - i) \vec{ v }_{ eig }^{ (1) } + \frac{ 1 }{ 2 } (1 + i)\vec{ v }_{ eig }^{ (2) }
$$

$$R\vec{ P } = \frac{ 1 }{ 2 }(1 - i)\lambda_1 \vec{ v }_{ eig }^{ (1) } + \frac{ 1 }{ 2 }(1 + i)\lambda_2\vec{ v }_{ eig }^{ (2) }$$

---

參考資料:

工數課本P129

---

link:

[[Eigenvalue]]