Tag: #linear-algebra 
Previous: [[Elementary Matrix]]
Link: 

---

[TOC]

---

Use a lower and an upper strict triangular matrix $L, U$ to represent $A$.

$$A = LU$$

# Restriction

The $n \times n$ matrix $A$ can be reduced to strict upper triangular form using only [[Elementary Row Operation]] 3.

# Process

$$A = \left[
	\begin{array}{}
		2 & 4 & 2 \\
		1 & 5 & 2 \\
		4 & -1 & 9
	\end{array}
\right]$$

- Subtract second row by $1/2$ times the first row.
- Subtract third row by twice the first row.
- Set $l_{21} = 1/2$ and $l_{31} = 2$.

$$A' = \left[
	\begin{array}{}
		2 & 4 & 2 \\
		0 & 3 & 1 \\
		0 & -9 & 5
	\end{array}
\right]$$

$$L = 
\left[
	\begin{array}{}
		1 & 0 & 0 \\
		1/2 & 1 & 0 \\
		2 & l_{32} & 1
	\end{array}
\right]$$

- Subtract third row by $-3$ times the second row.
- Set $l_{32} = -3$.
- The result $A'' = U$

$$U = \left[
	\begin{array}{}
		2 & 4 & 2 \\
		0 & 3 & 1 \\
		0 & 0 & 8
	\end{array}
\right]$$

$$L = 
\left[
	\begin{array}{}
		1 & 0 & 0 \\
		1/2 & 1 & 0 \\
		2 & -3 & 1
	\end{array}
\right]$$

$$\implies \underline{
	A = LU = 
	\left[
		\begin{array}{}
			1 & 0 & 0 \\
			1/2 & 1 & 0 \\
			2 & -3 & 1
		\end{array}
	\right]
	\left[
		\begin{array}{}
			2 & 4 & 2 \\
			0 & 3 & 1 \\
			0 & 0 & 8
		\end{array}
	\right]
}_{\#}$$

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.