標籤: #工程數學 #linear-algebra 

---

- Directional quantity defined by a start / end point
- Difference between the start / end points give you: direction and magnitude
- $1D$, $2D$, $3D \dots$ any higher dimension

# Unit Vector

A vector with a magnitude of $1$

# Equality

$\vec{ a } = \vec{ b }$ means direction and magnitude are same, but it doesn't mean they have the same location

# Operations

## Addition

Same as [[Archived/工程數學/Linear Algebra/Matrix#Addition|Matrix]]

## Multiply

### Inner Product

$$\vec{ a } \cdot \vec{ b } = 
\left[
	\begin{array}{}
		a_1b_1 \\
		a_2b_2 \\
		a_3b_3
	\end{array}
\right]$$

#### Definition

$$\vec{ a }\cdot\vec{ b } = \vert \vec{ a } \vert\vert \vec{ b } \vert\cos\theta$$

$$0 \leq \theta \leq \pi$$

$$
\begin{array}{}
	\vec{ a } \cdot \vec{ b } = 0 & \text{ if: } & \vec{ a } = 0 & \text{ or } \\
	&&\vec{ b } = 0 & \text{ or } \\
	&&\theta = 90 \degree & \implies & \vec{ a } \text{ and } \vec{ b } \text{ are orthogonal }
\end{array}
$$

#### Consequences

1. $\theta = 90\degree \implies \vec{ a } \text{ and } \vec{ b } \text{ are orthogonal }$
2. $\vert \vec{ a } \vert = \sqrt{ \vec{ a } \cdot \vec{ a } }$
3. $\cos\theta = \frac{ \vec{ a }\cdot \vec{ b } }{ \vert \vec{ a } \vert \vert \vec{ b } \vert } = \frac{ \vec{ a } \cdot \vec{ b } }{ \sqrt{ \vec{ a } \cdot \vec{ a } } \sqrt{ \vec{ b } \cdot \vec{ b } } }$
(if $\vec{ a } \neq 0$ and $\vec{ b } \neq 0$)

#### Properties

- $(q_1\vec{ a } + q_2\vec{ b }) \cdot \vec{ c }$
$= q_1\vec{ a } \cdot \vec{ c } + q_2\vec{ b } \cdot \vec{ c }$
- $\vec{ a } \cdot \vec{ b } = \vec{ b } \cdot \vec{ a }$
- $\vec{ a }\cdot \vec{ a }\geq 0$
- $\vert \vec{ a } \cdot \vec{ b } \vert \leq \vert\vec{ a }\vert\vert\vec{ b }\vert$

### Scalar Multiply

$$c\vec{ a } = 
\left[
	\begin{array}{}
		ca_1 \\
		ca_2 \\
		ca_3
	\end{array}
\right]$$

### [[Cross Product]]

掐頭去尾插三下

$$\vec{ a } \times \vec{ b } = \vec{ c }$$

$$
\implies
\bcancel{ \cancel{ \begin{array}{}
	a_1 \\
	b_1
\end{array} } }
\begin{array}{}
	a_2 & a_3 & a_1 & a_2 \\
	b_2 & b_3 & b_1 & b_2
\end{array}
\bcancel{ \cancel{ 
\begin{array}{}
	a_3 \\
	b_3
\end{array}
} }
$$

$$
\implies
\begin{array}{}
	a_2 && a_3 && a_1 && a_2 \\
	& \times && \times && \times \\
	b_2 && b_3 && b_1 && b_2
\end{array}
$$

$$
\implies
c_1 = 
\left\vert
	\begin{array}{}
		a_2 & a_3 \\
		b_2 & b_3
	\end{array}
\right\vert
\quad 
c_2 = 
\left\vert
	\begin{array}{}
		a_3 & a_1 \\
		b_3 & b_1
	\end{array}
\right\vert
\quad 
c_3 = 
\left\vert
	\begin{array}{}
		a_1 & a_2 \\
		b_1 & b_2
	\end{array}
\right\vert
$$

# Triple Product

$$V = (\vec{ a }\vec{ b }\vec{ c }) = \vec{ a } \cdot (\vec{ b } \times \vec{ c })$$

$$ = (\vec{ a } \times \vec{ b })\cdot \vec{ c }$$

$$ = \text{ scalar }$$

可以求出三個向量張出的體積

---

參考資料:

工程數學上課

---

link:

[[Orthogonal]]