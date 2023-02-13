標籤: #linear-algebra 

---

[TOC]

---

The [[Matrix]] is in reduced row echelon form if:

1. The matrix is in [[Row Echelon Form]].
2. The first nonzero entry in each row is the only nonzero entry in its column.

Some example of reduced row echelon form:

$$\left[
	\begin{array}{}
		1 & 0 \\
		0 & 1
	\end{array}
\right], \quad \left[
	\begin{array}{}
		1 & 0 & 0 & 3 \\
		0 & 1 & 0 & 2 \\
		0 & 0 & 1 & 1
	\end{array}
\right], \quad \left[
	\begin{array}{}
		1 & 0 & 2 & 0 \\
		0 & 0 & 0 & 1 \\
		0 & 0 & 0 & 0
	\end{array}
\right], \quad \left[
	\begin{array}{}
		1 & 2 & 0 & 1 \\
		0 & 0 & 1 & 3 \\
		0 & 0 & 0 & 0
	\end{array}
\right]$$

The process of using [[Row Reduction|elementary row operation]] to change a matrix to a reduced row echelon form is called ==Gauss-Jordan== reduction.

---

參考資料:

Linear Algebra class

---

link:

