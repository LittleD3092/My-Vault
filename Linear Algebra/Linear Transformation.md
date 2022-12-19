 標籤: #linear-algebra 

---

[TOC]

---

# Definition

A mapping $L$ from a vector space $V$ into a vector space $W$ is said to be a **linear transformation** if

$$L(\alpha{\bf v}_1 + \beta {\bf v}_2) = \alpha L({\bf v}_1) + \beta L({\bf v}_2)$$

for all ${\bf v}_1, {\bf v}_2 \in V$ and for all scalars $\alpha$ and $\beta$.

The above definition can be seperated into two parts:

1. $L({\bf v}_1 + {\bf v}_2) = L({\bf v}_1) + L({\bf v}_2) \qquad (\alpha = \beta = 1)$
2. $L(\alpha {\bf v}) = \alpha L({\bf v}) \qquad ({\bf v} = {\bf v}_1, \beta = 0)$

> $L$ is a linear transformation iff $L$ satisfies the above 2 conditions.

# Notation

- A mapping $L$ from a vector space $V$ into a vector space $W$ will be denoeted $$L: V \rightarrow W$$
- If $V$ and $W$ are the same, the following is called a **linear operator**: $$L: V \rightarrow V$$
- A linear transformation $L_A({\bf x})$ can be represented by a matrix $A$: $$L_A({\bf x}) = A{\bf x}$$

## Examples

### Linear Operators on $\rm R^2$

The operator $L$ defined by

$$L({\bf x}) = (-x_2, x_1)^T$$

Since 

$$
\begin{array}{}
	L(\alpha {\bf x} + \beta{\bf y}) & = & 
	\left[
		\begin{array}{}
			-(\alpha x_2 + \beta y_2) \\
			\alpha x_1 + \beta y_1
		\end{array}
	\right] \\
	& = & 
	\alpha\left[
		 \begin{array}{}
		 -x_2 \\
		 x_1
		 \end{array}
	\right] +
	\beta\left[
		\begin{array}{}
			 -y_2 \\
			 y_1
		\end{array}
	\right] \\
	& = & 
	\alpha L({\bf x}) +
	\beta L({\bf y})
\end{array}
$$

It is a linear operator.

### Linear Transformation from ${\rm R}^n$ to ${\rm R}^m$

The mapping from ${\rm R}^2$ to ${\rm R}^3$ is defined by

$$L({\bf x}) = (x_2, x_1, x_1 + x_2)^T$$

Since 

$$L(\alpha {\bf x}) = (\alpha x_2, \alpha x_1, \alpha x_1 + \alpha x_2)^T = \alpha L({\bf x})$$

and

$$
\begin{array}{l}
	L({\bf x} + {\bf y}) & = &
	(x_2 + y_2, x_1 + y_1, x_1 + y_1 + x_2 + y_2)^T \\
	& = & (x_2, x_1, x_1 + x_2)^T + (y_2, y_1, y_1 + y_2)^T \\
	& = & L({\bf x}) + L({\bf y})
\end{array}
$$

It is linear transformation.

### Linear Transformation from $V$ to $W$

Let $L$ be a mapping from $C[a, b]$ to $R^1$ defined by:

$$L(f) = \int_a^b f(x)dx$$

$L$ is linear transformation since

$$
\begin{array}{}
	
\end{array}
$$

---

參考資料:

Linear Algebra with Applications, 10th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.