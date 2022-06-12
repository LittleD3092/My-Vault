標籤: #工程數學 

---

- [[Wave Equation]]
	- Original Equation:
	$$\underline{
		c^2 \frac{\partial^2 u}{\partial x^2} = 
		\frac{\partial^2 u}{\partial t^2}
	}_\#$$
	$$c^2 = \frac T \rho$$
	- Solution:
	$f(x)$: initial shape
	$g(x)$: initial velocity
	$$\underline{
		u(x, t) = \sum_{n = 1}^\infty \sin
		\left(
			\frac{n\pi}{L}x
		\right)
		\left[
			\alpha_n\cos\left(
				\frac{cn\pi}{L}t
			\right) +
			\beta_n\sin\left(
				\frac{cn\pi}{L}t
			\right)
		\right]
	}_\#$$
	$$\underline{
		\alpha_n = 
		\frac 2 L
		\int_0^L f(x)\sin\left(
			\frac{n\pi}{L}x
		\right)dx
	}_\#$$
	$$\underline{
		\beta_n = \frac 2 {cn\pi}
		\int_0^L g(x)\sin\left(
			\frac{n\pi}{L}x
		\right)dx
	}_\#$$
	- Special case when string has zero initial velocity $g(x) = 0$
	$$
	\underline{
		u(x, t) = \sum_{n = 1}^\infty
		\sin\left(
			\frac{n\pi}{L}x
		\right)
		\left[
			\alpha_n\cos\left(
				\frac{cn\pi}{L}t
			\right)
		\right]
	}_\#
	$$
	$$\underline{
		\alpha_n = \frac 2 L
		\int_0^L f(x)\sin
		\left(
			\frac{n\pi}{L}x
		\right)dx
	}_\#$$
	- [[D'Alembert's Solution]]
	$$
	\underline{
	u(x, t) = \frac 1 2\left[
		f(x + ct) + f(x - ct)
	\right] + \frac{1}{2c}
	\int_{x - ct}^{x + ct} g(s)ds
	}_\#
	$$
	If the initial velocity $\dot u(x, 0) = g(x) = 0$
	$$
	\underline{
		u(x, t) = \frac 1 2
		\left[
			f(x + ct) + f(x - ct)
		\right]
	}_\#
	$$
	- Method of Characteristics
	[[6.4b - Method of Characteristics.pdf]]
- [[Heat Equation]]

# Motivation

When your problem is zero-dimensional, it is easy to solve.

For example, a point-mass suspended on spring:

![[a point mass suspended on a string.png]]

The result can only depend on one variable such as time.

But many real-life problems have higher dimensions.

- A string / rope's motion
![[a string's motion in x, y and t.png]]
Here, the answer (the rope's height $y$) is a function of space $x$, and time $t$
- Heat diffusion
![[heat diffusion example.png]]
Here, the temperate of the metal plate can change according to 2 spatial directions and time: $T(x, y, t)$

## What is PDE

Partial Differential Equation is a DE where the variable of interest depends on $\geq 2$ variables.

We take the derivative of unknown function $u(x, y, t)$ in terms of each independent variable separately:

![[what is pde.png]]

The "$\partial$" notation lets you know it's a partial derivative.

---

- Like ODE, 2nd-order PDE is the most useful for engineering
- It is ==linear== if we don't have multiplication of $u$ or its derivative to each other.
- ==Homogeneous== if any terms without $u$ or its derivative $= 0$

Examples of important 2nd-order PDE:
- 1D wave equation
$$\frac{\partial^2 u}{\partial t^2} = 
c^2 \frac{\partial^2 u}{\partial x^2}$$
- 1D heat equation
$$\frac{\partial u}{\partial t} = 
c^2 \frac{\partial^2 u}{\partial x^2}$$
- 2D Laplace equation
$$\frac{\partial^2 u}{\partial x^2} + 
\frac{\partial^2 u}{\partial y^2} = 0$$
- 2D wave equation
$$\frac{\partial^2 u}{\partial t^2} = 
c^2\left(
	\frac{\partial^2 u}{\partial x^2} +
	\frac{\partial^2 u}{\partial y^2}
\right)$$
- 3D Laplace equation
$$\frac{\partial^2 u}{\partial x^2} +
\frac{\partial^2 u}{\partial y^2} +
\frac{\partial^2 u}{\partial z^2} = 0$$

# Solution

## Concept

- Fundamentally, any $u$ that satisfies the PDE is a solution
- For homogeneous, linear PDE, if $u_1$, $u_2$ are solutions in region $R$, then $u_3 = c_1u_1 + c_2u_2$ is also a solution
- Bounding conditions are different from ODE
	- In ODE, we have IVP that uses initial conditions $(y(t = 0) = \dots)$ to find constants $c_1, c_2, \dots \text{ etc. }$
	- In PDE, since $u(t, x, y, \dots)$ is (or can be) function of time and space, we need ==initial condition== $(u(t = 0))$ and ==boundary conditions== $(u(x_0, y_0))$ to find / bound the problem

## How to Solve

1. Some PDE can be solve like ODE ... if you're lucky:

> $$\frac{\partial^2 u(x, y)}{\partial x^2} - u(x, y) \equiv u_{xx} - u = 0$$

Although $u = u(x, y)$, the PDE only involves $\frac{\partial^2}{\partial x^2}$:

- Solve like $u'' - u = 0 \rightarrow u = Ae^x + Be^{-x}$
- Don't forget $A, B$ can be function of $y$:
$$u(x, y) = A(y)e^x + B(y)e^{-x}$$

---

> $$u_{xy} = -u_x$$

Here the key is that we can play substitution of variable $u_x \equiv p$:

$$P_y = -P$$

$$\implies \frac{P_y}{P} = -1$$

$$\overset{\text{Integrate in }y}{\implies} 
\ln\vert P \vert = -y + C(x)$$

$$\therefore P = C(x)e^{-y}$$

since $P = \frac{\partial u}{\partial x}$, integrate $P$ to get $u$:

$$\implies u(x, y) = f(x)e^{-y} + g(y) \qquad ; f(x) = \int C(x)dx$$

2. In general, it is not so easy to solve PDE. In fact, mathematicians / scientists devote careeres to solving specific important PDE (e.g. [[Wave Equation]], heat equation, Navier-Stokes)

---

參考資料:

工程數學筆記 [[6.1 - Basic Concepts of PDE.pdf]]

---

link:

[[Differential Equation]]
[[Higher Order DE解法]]