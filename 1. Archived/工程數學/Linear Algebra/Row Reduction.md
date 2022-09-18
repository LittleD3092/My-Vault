標籤: #工程數學 #linear-algebra 

---

嘗試將矩陣變為以下的樣子，有一個三角形的 $0$ 。Also known as back substitution.

$$\text{ 目標: } \widetilde{ A } = 
\left[
\begin{array}{}
a_{ 11 } & a_{ 12 } & a_{ 13 } \\
0 & a_{ 22 } & a_{ 23 } \\
0 & 0 & a_{ 33 }
\end{array}
\right\vert
\left.
\begin{array}{}
b_1 \\
b_2 \\
b_3
\end{array}
\right]$$

$$\implies \widetilde{ A } = 
\left[
\begin{array}{}
1 & -2 & 3 \\
2 & 3 & -2 \\
-3 & 4 & -1
\end{array}
\right\vert
\left.
\begin{array}{}
2 \\
3 \\
0
\end{array}
\right]
$$

$$ = 
\left[
\begin{array}{}
1 & -2 & 3 \\
0 & 7 & -8 \\
0 & -2 & 8
\end{array}
\right\vert
\left.
\begin{array}{}
2 \\
-1 \\
6
\end{array}
\right]
$$

$$
=
\left[
\begin{array}{}
1 & -2 & 3 \\
0 & 7 & -8 \\
0 & 0 & \frac{ 40 }{ 7 }
\end{array}
\right\vert
\left.
\begin{array}{}
2 \\
-1 \\
\frac{ 40 }{ 7 }
\end{array}
\right]
$$

$$\implies 
\left\{
\begin{array}{}
x_1 = 1 \\
x_2 = 1 \\
x_3 = 1
\end{array}
\right.$$

---

What is allowed:

1. Interchange two rows
2. Add multiples of one row to another row
3. Multiplying a row by a constant ($\neq 0$)

- 2 matrices are "row-equivalent" if they can be made same by row-operation
- row-equivalent system $\rightarrow$ same solution
- A system is:
	- Overdetermined: $m > n$
	- Determined: $m = n$
	- Undetermined: $m < n$
	$m$: number of equations
	$n$: number of variables

# Strict Triangular Form

![[Gauss Elimination#Strict Triangular Form]]

# Pivot and Pivotal Row

Suppose that we have a [[Augmented Matrix]]:

$$
\left[
	\begin{array}{}
		1 & 2 & 1 \\
		3 & -1 & -3 \\
		2 & 3 & 1
	\end{array}
\right\vert
\left.
	\begin{array}{}
		3 \\
		-1 \\
		4
	\end{array}
\right]
$$

We try to do row reduction based on the first row:

$$
\left[
	\begin{array}{}
		1 & 2 & 1 \\
		0 & -7 & -6 \\
		0 & -1 & -1
	\end{array}
\right\vert
\left.
	\begin{array}{}
		3 \\
		-10 \\
		-2
	\end{array}
\right]
$$

In this row reduction, the first row $1 \quad 2 \quad 1 \ \vert\ 3$ is called ==pivotal row==, and the first element that is not $0$ is called ==pivot==.

---

參考資料:

工程數學上課 2022-02-21
工程數學上課 2022-02-23
工程數學刷題 2022-03-03 (7.4-1)
Linear Algebra class

---

link:

