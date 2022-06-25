標籤: #工程數學 

---

嘗試將矩陣變為以下的樣子，有一個三角形的 $0$

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

---

參考資料:

工程數學上課 2022-02-21
工程數學上課 2022-02-23
工程數學刷題 2022-03-03 (7.4-1)

---

link:

