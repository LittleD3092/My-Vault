Tag: #linear-algebra 
Previous: 
Link: [[Matrix]]

---

[TOC]

---

# Diagonalizable

## Definition

An $n \times n$ matrix $A$ is said to be **diagonalizable** if there exists a nonsingular matrix $X$ and a diagonal matrix $D$ such that

$$X^{-1}AX = D$$

We say that $X$ **diagonalizes** $A$.

- An $n \times n$ matrix $A$ is diagonalizable if and only if $A$ has $n$ linearly independent [[Eigenvector|eigenvectors]].
- Remarks:
	1. If $A$ is diagonalizable, column [[Vector|vectors]] of $X$ are [[Eigenvector|eigenvectors]] of $A$ and diagonal elements of $D$ are [[Eigenvalue|eigenvalues]].
	2. The diagonalizing matrix $X$ is not unique. You can get new $X$ by multiplying a scalar or reorder the columns.

# Exponential of a Matrix

To compute a general $n \times n$ matrix $A$, we have to factorize $A$:

$$A = XDX^{-1}$$

So that

$$e^A = X\left(I + D + \frac{1}{2!}D^2 + \frac{1}{3!}D^3 + \dots\right)X^{-1}$$

$$ = Xe^DX^{-1}$$

> For diagonal matrix, the matrix exponential is easy to compute:
> $$e^D = \lim_{m \rightarrow \infty}\left( I + D + \frac{1}{2!}D^2 + \dots + \frac{1}{m!}D^m \right)$$
> $$ = \lim_{m \rightarrow \infty}\left[ \begin{array}{} \displaystyle \sum_{k = 0}^m \frac{1}{k!}\lambda_1^k \\ & \ddots \\ && \displaystyle \sum_{k = 0}^m \frac{1}{k!}\lambda_n^k \end{array} \right] = \left[ \begin{array}{} e^{\lambda_1} \\ & e^{\lambda_2} \\ && \ddots \\ &&& e^{\lambda_n} \end{array} \right]$$

## Example

Compute $e^A$ for

$$A = \left[
	\begin{array}{}
		-2 & -6 \\
		1 & 3
	\end{array}
\right]$$

---

The [[Eigenvalue|eigenvalues]] are

$$
\left\{
	\begin{array}{}
		\lambda_1 & = & 1 \\
		\lambda_2 & = & 0
	\end{array}
\right.
$$

And the [[Eigenvector|eigenvectors]] are

$$
\left\{
	\begin{array}{}
		{\bf x}_1 & = & (-2, 1)^T \\
		{\bf x}_2 & = & (-3, 1)^T
	\end{array}
\right.
$$

Thus, $A$ can be written as

$$A = XDX^{-1} = \left[
	\begin{array}{}
		-2 & -3 \\
		1 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & 0 \\
		0 & 0
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & 3 \\
		-1 & -2
	\end{array}
\right]$$

and $e^A$ is therefore

$$e^A = Xe^DX^{-1} = \left[
	\begin{array}{}
		-2 & -3 \\
		1 & 1
	\end{array}
\right]
\left[
	\begin{array}{}
		e^1 & 0\\
		0 & e^0
	\end{array}
\right]
\left[
	\begin{array}{}
		1 & 3 \\
		-1 & -2
	\end{array}
\right]$$

$$ = 
\left[
	\begin{array}{}
		3 - 2e & 6 - 6e \\
		e - 1 & 3e - 2
	\end{array}
\right]$$

---

參考資料:

Linear Algebra with Application, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.