Tag: #fluid-mechanics 
Previous: 
Link: [[Dimension]]

---

[TOC]

---

This theorem helps us to determine the dimensionless groups for a problem. It let us to use smaller scales for testing and still acheive the same physical properties.

# Theorem

Buckingham Pi theorem states that we can transform a relationship between $n$ parameters of the form

$$g(q_1, q_2, \dots, q_n) = 0$$

to

$$G(\Pi_1, \Pi_2, \dots, \Pi_{n - m})$$

- $m$ is *usually* the minimum number of independent dimensions.

## Steps

1. *List all the dimensional parameters involved.*
	- Let $n$ be the number of parameters.
2. *Select a set of fundamental (primary) dimensions*.
	- For example, $MLt$ or $FLt$.
	- For heat transfer problems, you may need temperature $T$.
	- For electrical systems, you may need charge $q$.
3. *List the dimensions of all parameters in terms of primary dimensions*.
	- Let $r$ be the number of primary dimensions.
4. *Select a set of $r$ dimensional parameters that includes all the primary dimensions.*
	- No repeating parameter should have dimensions that are a power of the dimensions of another repeating parameter.
	- We usually select simpler parameters like $\rho$, $V$, $D$ instead of $\mu$.
5. *Set up dimensional equations, combining the parameters in step 4 with each of the other parameters in turn, to form dimensionless groups*.
	- There will be $n - m$ equations.
6. *Check to see that each group obtained is dimensionless*.

## Example

Suppose we are finding the properties that [[Drag]] $F$ on a sphere depends on. We can say that $F$ is:

$$F = f(D, \rho, \mu, V)$$

More formally, we write:

$$g(F, D, \rho, \mu, V) = 0$$

1. *List all the dimensional parameters involved.*

$$F, V, D, \rho, \mu$$

- $n = 5$ dimensional parameters.

2. *Select a set of fundamental (primary) dimensions.*

$$M, L, t$$

3. *List the dimensions of all parameters in terms of primary dimensions*.

| $F$                            | $V$                       | $D$ | $\rho$                        | $\mu$          |
| ------------------------------ | ------------------------- | --- | ----------------------------- | -------------- |
| $\displaystyle \frac{ML}{t^2}$ | $\displaystyle \frac L t$ | $L$ | $\displaystyle \frac{M}{L^3}$ | $\displaystyle \frac{M}{Lt}$ | 

- $r= 3$ primary dimensions.

4. *Select a set of $r$ dimensional parameters that includes all the primary dimensions.* 

$$\rho, V, D$$

- $m = r = 3$ repeating parameters.

5. *Set up dimensional equations, combining the parameters selected in Step 4 with each of the other parameters in turn, to form dimensionless groups*.

- $n - m = 2$, there will be two groups.

For $\Pi_1$:

$$
\left\{
	\begin{array}{rml}
		\Pi_1 &=& p^aV^bD^cF \\
		\displaystyle
		\left(
			\frac{M}{L^3}
		\right)^a
		\left(
			\frac{L}{t}
		\right)^b
		(L)^c
		\left(
			\frac{ML}{t^2}
		\right) &=&
		M^0L^0t^0
	\end{array}
\right.
$$

$$\implies 
\left\{
	\begin{array}{l}
		M: & a & + &&&&& 1 & = & 0 \\
		L: & -3a & + & b & + & c & + & 1 & = & 0 \\
		t: &&& -b &&& - & 2 & = & 0
	\end{array}
\right.$$

$$\implies \left\{
	\begin{array}{}
		a = -1 \\
		b = -2 \\
		c = -2
	\end{array}
\right.$$

$$\implies \Pi_1 = \frac{F}{\rho V^2 D^2}$$

For $\Pi_2$:

$$
\left\{
	\begin{array}{rml}
		\Pi_2 & = & \rho^dV^eD^f\mu \\
		\displaystyle
		\left(
			\frac{M}{L^3}
		\right)^d
		\left(
			\frac{L}{t}
		\right)^e
		(L)^f
		\left(
			\frac{M}{Lt}
		\right) & = & 
		M^0L^0t^0
	\end{array}
\right.
$$

$$
\implies
\left\{
	\begin{array}{l}
		d &&&&&+& 1 &=& 0 \\
		-3d &+& e &+& f &-& 1 &=& 0 \\
		&& -e &&& - & 1 & = & 0
	\end{array}
\right.
$$

$$
\implies 
\left\{
	\begin{array}{}
		d & = & -1 \\
		f & = & -1 \\
		e & = & -1
	\end{array}
\right.
$$

$$\implies \Pi_2 = \frac{\mu}{\rho VD}$$

6. *Check to see that each group obtained is dimensionless.*

$$
\left\{
	\begin{array}{}
		[\Pi_1] & = & 
		\displaystyle
		\left[
			\frac{F}{\rho V^2D^2}
		\right] & = &
		\displaystyle
		F\frac{L^4}{Ft^2}
		\left(
			\frac t L
		\right)^2 \frac{1}{L^2} & = & 1 \\
		[\Pi_2] & = & 
		\displaystyle
		\left[
			\frac{\mu}{\rho VD}
		\right] & = & 
		\displaystyle
		\frac{Ft}{L^2}\frac{L^4}{Ft^2}\frac t L \frac 1 L & = & 1
	\end{array}
\right.
$$

The functional relationship is $\Pi_1 = f(\Pi_2)$:

$$\frac{F}{\rho V^2 D^2} = f\left(\frac{\mu}{\rho VD}\right)$$

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.