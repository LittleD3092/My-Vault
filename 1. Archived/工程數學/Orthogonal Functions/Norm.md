標籤: #工程數學 

---

# Functions

$$\vert\vert f(x) \vert\vert = \sqrt{ (f(x), f(x)) } = \sqrt{ \int_a^b f(x)f^*(x)dx }$$

## Square Norm

[[Square Norm]]

# Vector

## Normed Linear Space

A vector space $V$ is said to be a **normed linear space** if, to each vector ${\bf v} \in V$, there is associated a real number $\vert\vert{\bf v}\vert\vert$, called the **norm** of ${\bf v}$, satisfying

1. $\vert\vert{\bf v}\vert\vert \geq 0$ with equality if and only if ${\bf v} = {\bf 0}$.
2. $\vert\vert \alpha {\bf v}\vert\vert = \vert\alpha \vert \ \vert\vert {\bf v}\vert\vert$ for any scalar $\alpha$.
3. $\vert\vert{\bf v} + {\bf w}\vert\vert \leq \vert\vert {\bf v}\vert\vert + \vert\vert{\bf w}\vert\vert$ for all ${\bf v}$, ${\bf w} \in V$.

> The third condition is called the *triangle inequality*.

## Inner Product Space Norm

If $V$ is an inner product space, then the equation

$$\vert\vert{\bf v}\vert\vert = \sqrt{<{\bf v}, {\bf v}>} \qquad \text{for all } {\bf v} \in V$$

defines a norm on $V$.

## Uniform Norm

- Also called *infinity norm*.

$$\vert\vert {\bf x}\vert\vert_\infty = \max_{1 \leq i \leq n}\vert x_i \vert$$

## General Norm

More generally, we can define a norm on $R^n$ by

$$\vert\vert {\bf x}\vert\vert_p = 
\left(
	\sum_{i = 1}^n
	\vert x_i \vert^p
\right)^{1/p}$$

- Note that:
	- [[#Uniform Norm]] is general norm with $p = \infty$.
	- [[#Inner Product Space Norm]] is general norm with $p = 2$.

---

參考資料:

微分方程OCW class 24

---

link:

[[Square Norm]]
[[Inner Product]]