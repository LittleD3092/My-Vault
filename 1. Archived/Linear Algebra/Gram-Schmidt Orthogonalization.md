Tag: #linear-algebra 
Previous: [[Orthogonal]]
Link: [[Orthonormal Set]]

---

[TOC]

---

# Gram-Schmidt Process

Let $\{{\bf x}_1, {\bf x}_2, \dots, {\bf x}_n\}$ be a basis for the inner product space $V$. Let

$${\bf u}_1 = \left(
	\frac{1}{\vert\vert {\bf x}_1\vert\vert}
\right){\bf x}_1$$

and define ${\bf u}_2, {\bf u}_3, \dots, {\bf u}_n$ recursively by

$${\bf u}_{k + 1} = 
\frac{1}{\vert\vert {\bf x}_{k + 1} - {\bf p}_k \vert\vert} ({\bf x}_{k + 1} - {\bf p}_k) \qquad \text{for } k = 1, 2, \dots, n - 1$$

where

$${\bf p}_k = <{\bf x}_{k + 1}, {\bf u}_1>{\bf u}_1 + <{\bf x}_{k + 1}, {\bf u}_2>{\bf u}_2 + \dots + <{\bf x}_{k + 1}, {\bf u}_k>{\bf u}_k$$

is the projection of ${\bf x}_{k + 1}$ onto $\text{Span}({\bf u}_1, {\bf u}_2, \dots, {\bf u}_k)$. Then the set

$$\{{\bf u}_1, {\bf u}_2, \dots, {\bf u}_n\}$$

is an [[Orthonormal Set|orthonormal basis]] for $V$.

# Gram-Schmidt QR Factorization

> Note:
> [[LU Factorization]]

If $A$ is an $m \times n$ matrix of rank $n$, then $A$ can be factored into a product $QR$:

- $Q$: An $m \times n$ matrix with orthonormal column vectors.
- $R$: An upper triangular $n \times n$ matrix whose diagonal entries are all positive.

## Process

- The matrix $Q$ can be derived from [[#Gram-Schmidt Process]].
- Let ${\bf p}_1, {\bf p}_2, \dots, {\bf p}_{n - 1}$ be the projection vectors defined in [[#Gram-Schmidt Process]].
- Let $\{{\bf q}_1, {\bf q}_2, \dots, {\bf q}_n\}$ be the set of column vectors in $Q$.

What's left is the matrix $R$. The elements $r_{ij}$ is defined as:

$$
\begin{array}{l}
	r_{11} & = & \vert\vert {\bf a}_1 \vert\vert \\
	r_{kk} & = & \vert\vert {\bf a}_k - {\bf p}_{k - 1} \vert\vert & \text{for} & k = 2, \dots, n \\
	r_{ik} & = & {\bf q}_i^T {\bf a}_k & \text{for} & i = 1, \dots, k - 1 \\
	&&& \text{and} & k = 2, \dots, n
\end{array}
$$

## Example

Compute the Gram-Schmidt QR factorization of the matrix

$$A = 
\left[
	\begin{array}{}
		1 & -2 & -1 \\
		2 & 0 & 1 \\
		2 & -4 & 2 \\
		4 & 0 & 0
	\end{array}
\right]$$

---

> You should try the process on your own, the process is complicated.
> I recommend that you calculate one column and check whether you are right.

![[Pasted image 20230102171055.png]]

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.