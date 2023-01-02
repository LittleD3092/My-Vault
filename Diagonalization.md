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

---

參考資料:

Linear Algebra with Application, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.