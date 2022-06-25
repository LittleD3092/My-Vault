標籤: #工程數學 

---

# Application

- ODE [[Wronskian]]
- [[Cross Product]]
- [[Eigenvalue]]
- ==solve system of equation== [[Cramer's Rule]]

# Calculate

Order $n = 3$

$$
\det\left(\left[
\begin{array}{}
a & b & c \\
d & e & f \\
g & h & i
\end{array}
\right]\right) = 
a\det\left(\left[
\begin{array}{}
e & f \\
h & i
\end{array}
\right]\right) - 
b\det\left(\left[
\begin{array}{}
d & f \\
g & i
\end{array}
\right]\right) + 
c\det\left(\left[
\begin{array}{}
d & e \\
g & h
\end{array}
\right]\right)$$

$$
= -b\det\left(\left[
\begin{array}{}
d & f \\
g & i
\end{array}
\right]\right) +
e\det\left(\left[
\begin{array}{}
a & c \\
g & i
\end{array}
\right]\right) - 
h\det\left(\left[
\begin{array}{}
a & c \\
d & f
\end{array}
\right]\right)
$$

> Pattern of signs:
> $$\left(\begin{array}{} + & - & + \\ - & + & - \\ + & - & + \end{array}\right) \qquad \left(\begin{array}{} + & - & + & - \\ - & + & - & + \\ + & - & + & - \\ - & + & - & + \end{array}\right)$$

## General Mathematical Formulation

$$\det(A) = a_{ j1 }c_{ j1 } + a_{ j2 }c_{ j2 } + \dots + a_{ jn }c_{ jn } \qquad (j = 1,\ 2,\ \dots,\ n)$$

$$c_{ ji } \equiv (-1)^{ j + 1 }M_{ ji }$$

$M_{ ji } \equiv$ a determinant of the matrix of order $n - 1$ , formed for $A$ by taking at the column and row of entry $a_{ ji }$

## Simplifying

### Rules

> $$A \overset{ \text{ operation } }{ \implies } B$$

1. If operation is switching rows/columns
$$\implies \det(B) = -\det(A)$$
2. If operation is row/column operation 
$$\det(B) = \det(A)$$
3. If $B = (c \text{ multiplied to one row/column in } A)$ : 
$$\det(B) = c\det(A)$$

> 外積
> we have 
> $$\vec{ v }_1 = [v_{ 11 }, v_{ 12 }, v_{ 13 }]$$
> $$\vec{ v }_2 = [v_{ 21 }, v_{ 22 }, v_{ 23 }]$$
> $$\det\left[ \begin{array}{} \hat{ i } & \hat{ j } & \hat{ k } \\ [ & \vec{ v }_1 & ] \\ [ & \vec{ v }_2 & ] \end{array} \right] = \vec{ v }_1 \times \vec{ v }_2 = \vec{ v }_3$$
> $$\vert\vert \vec{ v }_3 \vert\vert = \vec{ v }_1 , \ \vec{ v }_2 \text{ 張出的平面 }$$

4. $\det(A^T) = \det(A)$
5. If one row/col is a multiple of another row/col, 
$$\det(A) = 0$$

---

參考資料:

工程數學上課

---

link:

[[Matrix]]