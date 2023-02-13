標籤: #linear-algebra 

---

[TOC]

---

A [[Matrix]] is in row echelon form if:

1. The first nonzero entry in each row is $1$.
2. If row $k$ does not consist entirely of zeroes, the number of leading zero entries in row $k + 1$ is greater than the number of leading zero entries in row $k$.
3. If there are rows whose entries are all zero, they are below the rows having nonzero entries.

An example of row echelon form:

$$
\left[
	\begin{array}{}
		1 & 1 & 1 & 1 & 1 \\
		0 & 0 & 1 & 1 & 2 \\
		0 & 0 & 0 & 0 & 1 \\
		0 & 0 & 0 & 0 & 0 \\
		0 & 0 & 0 & 0 & 0
	\end{array}
\right\vert
\left.
	\begin{array}{}
		1 \\
		0 \\
		3 \\
		4 \\
		3
	\end{array}
\right]
$$

The process of using elementary row operations to transform an augmented matrix to a row echelon form is called [[Gauss Elimination]].

# Reduced Row Echelon Form

Reduced row echelon form is a stricter row echelon form.

![[Reduced Row Echelon Form]]

---

參考資料:

Linear Algebra class

---

link:

