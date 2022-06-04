標籤: #工程數學 

---

$$
\left[
\begin{array}{}
a_{ 11 } & a_{ 12 } & \dots & a_{ 1n } \\
a_{ 21 } & a_{ 22 } & \dots & a_{ 2n } \\
\vdots & \vdots & \ddots & \vdots \\
a_{ m1 } & a_{ m2 } & \dots & a_{ mn }
\end{array}
\right]
\left[
\begin{array}{}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{array}
\right] = 
\left[
\begin{array}{}
b_1 \\
b_2 \\
\vdots \\
b_m
\end{array}
\right]
$$

# [[Augmented Matrix]]

$$\widetilde{ A } = 
\left[
\begin{array}{}
a_{ 11 } & a_{ 12 } & \dots & a_{ 1n } \\
a_{ 21 } & a_{ 22 } & \dots & a_{ 2n } \\
\vdots & \vdots & \ddots & \vdots \\
a_{ m1 } & a_{ m2 } & \dots & a_{ mn }
\end{array}
\right\vert
\left.
\begin{array}{}
b_1 \\
b_2 \\
\vdots \\
b_m
\end{array}
\right]$$

# How to Solve

## [[Gauss Elimination]]

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

# [[Rank]]

$$
A = 
\left[
\begin{array}{}
r_{ 11 } & r_{ 12 } & r_{ 13 } & \dots & r_{ 1n } \\
0 & r_{ 22 } & r_{ 23 } & \dots & r_{ 2n } \\
0 & 0 & r_{ 33 } & \dots & r_{ 3n } \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
0 & 0 & 0 & \dots & r_{ rn } \\
0 & 0 & 0 & 0 & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots \\
0 & 0 & 0 & 0 & 0
\end{array}
\right\vert
\left.
\begin{array}{}
f_1 \\
f_2 \\
f_3 \\
\vdots \\
f_r \\
f_{ r + 1 } \\
\vdots \\
f_m
\end{array}
\right]
$$

$$\text{ rank }(A) = r$$

- $n$-variable, $m$-equation:
	- No solution: if $r < m$, and at least one of $f_{ r + 1 },\ f_{ r + 2 },\ \dots ,\ f_m \neq 0$
	- Unique Solution: consistent and $r = n$
	- Infinite Solution: consistent and $r \neq n (r < n)$

# Theorem

## Theorem 1

- row-equivalent matrices $=$ "same system" $=$ same rank
- To find rank, use row operation

## Theorem 2

P-vectors with n-component

If the matrix formed by P-vectors as rows $\rightarrow$ rank $=$ P

The P-vectors are linearly independent

## Theorem 3

$$rank(A) = rank(A^T)$$

$$rank_{ row }(A) = rank_{ col }(A)$$

- $row$: row-operation
- $col$: column-operation

A matrix contains the same amount of unique info in row and column

### Proof

Let $A$ be an $m \times n$ matrix

Let $A$ have rank $r$

$$r = 3, \qquad n = 5$$

$$r = 3 \quad \text{ means } \quad A \quad \text{ can be made from: }$$
$$
\left.
\begin{array}{}
\vec{ v }_{ (1) } & = & [ & v_{ 11 } & v_{ 12 } & v_{ 13 } & v_{ 14 } & v_{ 15 } & ] \\
\vec{ v }_{ (2) } & = & [ & v_{ 21 } & v_{ 22 } & v_{ 23 } & v_{ 24 } & v_{ 25 } & ] \\
\vec{ v }_{ (2) } & = & [ & v_{ 31 } & v_{ 32 } & v_{ 33 } & v_{ 34 } & v_{ 35 } & ]
\end{array}
\right\}
\text{ linearly independent } \rightarrow \text{ 
basis for } A
$$

$$
\begin{array}{}
\text{ To proof } rank(A) & = & rank(A^T) \\
& = & rank(B)
\end{array}
$$

Let $B$ be a matrix formed using the basis $\vec{ v }_{ (1) },\ \vec{ v }_{ (2) }, \ \vec{ v }_{ (3) }$, but let's try to make $B$ with as many linearly-independent column as possible.

$$\implies B = 
\left[
\begin{array}{}
\vec{ b }_{ (1) } \\
\vec{ b }_{ (2) } \\
\vdots \\
\vec{ b }_{ (m) }
\end{array}
\right] = 
\left[
\begin{array}{}
c_{ 11 }\vec{ v }_{ (1) } & + & c_{ 12 }\vec{ v }_{ (2) } & + & c_{ 13 }\vec{ v }_{ (3) } \\
c_{ 21 }\vec{ v }_{ (1) } & + & c_{ 22 }\vec{ v }_{ (2) } & + & c_{ 23 }\vec{ v }_{ (3) } \\
&& \vdots\\
c_{ m1 }\vec{ v }_{ (1) } & + & c_{ m2 }\vec{ v }_{ (2) } & + & c_{ m3 }\vec{ v }_{ (3) } 
\end{array}
\right]
$$

we get $k^{ th }$ column from $B$

$$\implies 
\left[
\begin{array}{}
b_{ 1k } \\
b_{ 2k } \\
\vdots \\
b_{ mk }
\end{array}
\right] = 
v_{ 1k }
\underbrace{
\left[
\begin{array}{}
c_{ 11 } \\
c_{ 21 } \\
\vdots \\
c_{ m1 }
\end{array}
\right] }_{ \vec{ c }_1 }
+
v_{ 2k }
\underbrace{
\left[
\begin{array}{}
c_{ 12 } \\
c_{ 22 } \\
\vdots \\
c_{ m2 }
\end{array}
\right] }_{ \vec{ c }_2 }
+
v_{ 3k }
\underbrace{
\left[
\begin{array}{}
c_{ 13 } \\
c_{ 23 } \\
\vdots \\
c_{ m3 }
\end{array}
\right] }_{ \vec{ c }_3 }
$$

$$
\begin{array}{l}
\implies \text{ above vector has } & \text{ 3-column basis from } & \vec{ c }_1, & \vec{ c }_2, & \vec{ c }_3 \\
& \text{ 3-row basis from } & v_{ 1k }, & v_{ 2k }, & v_{ 3k }
\end{array}
$$

$$
\begin{array}{}
\implies & rank(A) & = & rank_{ col }(A) \\
&& = & rank(A^T)
\end{array}
$$

## Theorem 4

- Given $P$-vectors with $n$-component each
- If $n < P$, then there are linearly dependent vectors in the system

## Theorem 5

Vector space $R^n$ consisteing of all vectors with $n$-component has $n$ dimension

## Theorem 6

Let say I have matrix $A_{ m\times n }$ 

$rank(A) = r$, $r \leq m$
$\rightarrow$ there are $r$ independent vectors that I can get from $A$

$rank(A^T) = r$
$\rightarrow$ there are $r$ independent vectors that I can get from $A^T$

$$\implies \text{ vectors from the row of } A \text{ and column of } A \text{ have same vector space }$$

# Existence

Rouché-Capelli Theorem:

$$A \vec{ x } = \vec{ b }$$

Solution(s) exist if and only if ("iff")

$$rank(A) = rank(\underbrace{ \widetilde{ A } }_{ [A\vert \vec{ b }] })$$
[[Augmented Matrix]]

==Proof==:

Let there be a system:

$$
\begin{array}{}
a_{ 11 }x_1 & + & a_{ 12 }x_2 & + & \dots & + & a_{ 1n }x_n & = & b_1 \\
a_{ 21 }x_1 & + & a_{ 22 }x_2 & + & \dots & + & a_{ 2n }x_n & = & b_2 \\
&&&& \vdots \\
a_{ m1 }x_1 & + & a_{ m2 }x_2 & + & \dots & + & a_{ mn }x_n & = & b_m \\
\end{array}
$$

$$\implies A \vec{ x } = \vec{ b }$$

$$\implies \vec{ c }_{ (1) }x_1 + \vec{ c }_{ (2) }x_2 + \dots + \vec{ c }_{ (n) }x_n = \vec{ b }$$

$$\because 
\left\{
\begin{array}{}
\widetilde{ A } = [A \vert \vec{ b } ] \\
rank_{ row }(A) = rank_{ col }(A)
\end{array}
\right.
$$

$$\therefore rank(\widetilde{ A }) = rank(A) \quad \text{ or } \quad rank(A) + 1$$

- $rank(A)$: if the system above is consistent ($b$ is derived from $A$)
- $rank(A) + 1$: if the system above is inconsistent ($b$ is new)

# Uniqueness

To have a unique solution: $rank(A) = rank(\widetilde{ A }) = n$

$n$: number of variable

==Proof==:

$$\vec{ c }_{ (1) }x_1 + \vec{ c }_{ (2) }x_2 + \dots + \vec{ c }_{ (n) }x_n = \vec{ b } \quad , \quad rank(A) = n$$

If solution is not unique, we have multiple solution

$$
\left\{
\begin{array}{}
\vec{ c }_{ (1) }x_1 + \dots + \vec{ c }_{ (n) }x_n = \vec{ b } \\
\vec{ c }_{ (1) }\hat{ x }_{ 1 } + \dots + \vec{ c }_{ (n) }\hat{ x }_{ (n) } = \vec{ b }
\end{array}
\right.
$$

$$\implies \vec{ c }_{ (1) }x_1 + \dots + \vec{ c }_{ (n) }x_n = \vec{ c }_{ (1) }\hat{ x }_{ 1 } + \dots + \vec{ c }_{ (n) }\hat{ x }_{ (n) }$$

$$\implies \vec{ c }_{ (1) }(x_1 - \hat{ x }_{ 1 }) + \dots + \vec{ c }_{ (n) }(x_n - \hat{ x }_{ (n) }) = 0$$

$$\because rank(A) = n \quad , \quad \vec{ c }_{ (1) }, \ \vec{ c }_{ (2) },\ \vec{ c }_{ (3) } \text{ is linearly independent }$$

$$
\implies
\left\{
\begin{array}{}
x_1 - \hat{ x }_1 = 0 \\
x_2 - \hat{ x }_2 = 0 \\
\vdots \\
x_n - \hat{ x }_n = 0 
\end{array}
\right.
$$

$$
\implies
\left\{
\begin{array}{}
x_1 = \hat{ x }_1 \\
x_2 = \hat{ x }_2 \\
\vdots \\
x_n = \hat{ x }_n
\end{array}
\right.
$$

# Infinite Number of Solution

$$rank(A) < n$$

$$rank(A) = rank(\widetilde{ A })$$

---

參考資料:

工程數學上課

---

link:

[[Vector Space]]
[[Subspace]]
[[Augmented Matrix]]
[[Row Reduction]]