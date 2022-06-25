標籤: #工程數學 

---

e.g.

$$
\begin{array}{}
-3x_1 & + & 4x_2 & - & x_3  & = & 0 \\
2x_1  & + & 3x_2 & - & 2x_3 & = & 3 \\
x_1   & - & 2x_2 & + & 3x_3 & = & 2
\end{array}
$$

Step 1.

$$\implies A \vec{ x } = 
\left[
\begin{array}{}
-3 & 4 & -1 \\
2 & 3 & -2 \\
1 & -2 & 3
\end{array}
\right]
\left[
\begin{array}{}
x_1 \\
x_2 \\
x_3
\end{array}
\right] = 
\left[
\begin{array}{}
0 \\
3 \\
2
\end{array}
\right]
$$

Step 2. [[#Augmented Matrix]]

$$
\widetilde{ A } = 
\left[
\begin{array}{}
-3 & 4 & -1 \\
2 & 3 & -2 \\
1 & -2 & 3
\end{array}
\right\vert
\left.
\begin{array}{}
0 \\
3 \\
2
\end{array}
\right]
$$

Step 3. Row Operation
[[Row Reduction]]

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

工程數學上課

---

link:

[[Cramer's Rule]]