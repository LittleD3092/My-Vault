標籤: #automatic-control 

---

[TOC]

---

The modern engineering systems have greater complexity. To analyze system like this, a new way has been developed since around 1960. This new approach is based on the concept of state.

# Terms

- ==State==: The smallest set of variables that completely determines the behavior of the system for any time $t \geq t_0$.
- ==State Variables==: The variables of a state.
- ==State Vector==: For $n$ state variables that form a state, these state variables can be considered the $n$ components of a vector $\textbf x$.
- ==State Space==: The $n$-dimensional space whose coordinate axes are state variables. Any state can be represented by a point in the state space.
- ==State-Space Equations==: Assume there are input $u_1(t), u_2(t), \dots, u_r(t)$, and outputs $y_1(t), y_2(t), \dots, y_m(t)$, and outputs of the integrators $x_1(t), x_2(t), \dots, x_n(t)$, the state-space equations can be written like this:
$$
\begin{array}{}
	\dot x_1 & = & f_1(x_1, & x_2, & \dots, & x_n, & u_1, & u_2, & \dots, & u_r, & t) \\
	\dot x_2 & = & f_2(x_1, & x_2, & \dots, & x_n, & u_1, & u_2, & \dots, & u_r, & t) \\
	\vdots \\
	\dot x_n & = & f_n(x_1, & x_2, & \dots, & x_n, & u_1, & u_2, & \dots, & u_r, & t) \\
	y_1(t) & = & g_1(x_1, & x_2, & \dots, & x_n, & u_1, & u_2, & \dots, & u_r, & t) \\
	y_2(t) & = & g_2(x_1, & x_2, & \dots, & x_n, & u_1, & u_2, & \dots, & u_r, & t) \\
	\vdots \\
	y_m(t) & = & g_m(x_1, & x_2, & \dots, & x_n, & u_1, & u_2, & \dots, & u_r, & t)
\end{array}
$$
We can also use vector form:
$$\implies 
\begin{array}{}
	\left[
		\begin{array}{}
			\dot x_1 \\
			\dot x_2 \\
			\vdots \\
			\dot x_n
		\end{array}
	\right] = 
	{\bf A}(t) \cdot \left[
		\begin{array}{}
			x_1 \\
			x_2 \\
			\vdots \\
			x_n
		\end{array}
	\right] +
	{\bf B}(t) \cdot
	\left[
		\begin{array}{}
			u_1 \\
			u_2 \\
			\vdots \\
			u_r
		\end{array}
	\right] \\ \\
	\left[
		\begin{array}{}
			y_1 \\
			y_2 \\
			\vdots \\
			y_m
		\end{array}
	\right] = 
	{\bf C}(t) \cdot
	\left[
		\begin{array}{}
			x_1 \\
			x_2 \\
			\vdots \\
			x_n
		\end{array}
	\right] + {\bf D}(t) \cdot
	\left[
		\begin{array}{}
			u_1 \\
			u_2 \\
			\vdots \\
			u_r
		\end{array}
	\right]
\end{array}$$
After simplification:
$$\begin{array}{}
	\dot{\textbf{x}}(t) = {\bf A}(t) \textbf x(t) + {\bf B}(t) \textbf u(t) \\
	\textbf y(t) = {\bf C}(t)\textbf x(t) + {\bf D}(t)\textbf u(t)
\end{array}$$
![[Pasted image 20221020152741.png]]

# Transfer Function of State Space

Recall that [[Transfer Function]] is given by:

$$\frac{Y(s)}{U(s)} = G(s)$$

Now we wish to obtain the transfer function of state space

$$\begin{array}{}
	\dot{\textbf{x}}(t) = {\bf A}(t) \textbf x(t) + {\bf B}(t) \textbf u(t) \\
	\textbf y(t) = {\bf C}(t)\textbf x(t) + {\bf D}(t)\textbf u(t)
\end{array}$$

First, we can do laplace transform

$$\begin{array}{r}
	s\textbf X(s) - \textbf x(0) & = & 
	\textbf{AX}(s) + \textbf B U(s) \\
	Y(s) & = &
	\textbf{CX}(s) + DU(s)
\end{array}$$

Since the transfer fuction is defined as the laplace transform of input and output when initial conditinos are zero, $\textbf x(0) = 0$.

$$\begin{array}{r}
	s\textbf X(s)& = & 
	\textbf{AX}(s) + \textbf B U(s) \\
	Y(s) & = &
	\textbf{CX}(s) + DU(s)
\end{array}$$

From the first equation, we can get $\textbf X(s)$:

$$\textbf X(s) = \frac{\textbf BU(s)}{s\textbf I - \textbf A}$$

Substituting this to the second equation, we get:

$$Y(s) = 
\left[
	\frac{\textbf{BC}}{s\textbf I - \textbf A} +
	D
\right]
U(s)$$

$$\implies \underline{G(s) = \frac{\textbf{BC}}{s\textbf I - \textbf A} + D}_\#$$

# State Space of Linear Differential Equation

Consider the following $n$-th order system

$$y^{(n)} + 
a_1y^{(n - 1)} + 
\dots + 
a_{n - 1}\dot y + 
a_ny = u$$

Let us define the state variables:

$$
\left\{
	\begin{array}{}
		x_1 & = & y \\
		x_2 & = & \dot y \\
		\vdots \\
		x_n & = & y^{(n - 1)}
	\end{array}
\right.
$$

Then the $n$-th order system can be written as:

$$
\left\{
	\begin{array}{l}
		\dot x_1 & = & x_2 \\
		\dot x_2 & = & x_3 \\
		& \vdots \\
		\dot x_{n - 1} & = & x_n \\
		\dot x_n & = & -a_nx_1 - \dots - a_1x_n + u
	\end{array}
\right.
$$

or

$$
\begin{array}{}
	\dot{\textbf x} = \textbf{Ax} + \textbf B u \\ \\
	\begin{array}{}
		\textbf x = 
		\left[
			\begin{array}{}
				x_1 \\
				x_2 \\
				\vdots \\
				x_n
			\end{array}
		\right], & 
		\textbf A = \left[
			\begin{array}{}
				0 & 1 & 0 & \dots & 0 \\
				0 & 0 & 1 & \dots & 0 \\
				\vdots & \vdots & \vdots & \ddots & \vdots \\
				0 & 0 & 0 & \dots & 1 \\
				-a_n & -a_{n - 1} & -a_{n - 2} & \dots & -a_1
			\end{array}
		\right], &
		\textbf B = \left[
			\begin{array}{}
				0 \\
				0 \\
				\vdots \\
				0 \\
				1
			\end{array}
		\right]
	\end{array} \\ \\
	y = \textbf{Cx} \\ \\
	\textbf C = [
		\begin{array}{}
			1  & 0 & \dots & 0
		\end{array}
	]
\end{array}
$$

The state-space representation for the transfer function system

$$\frac{Y(s)}{U(s)} = 
\frac{1}{s^n + 
a_1s^{n - 1} +
\dots +
a_{n - 1}s +
a_n}$$

## Forcing Involves Derivative

Consider the differential equation system that involves derivatives of the forcing function, such as:

$$y^{(n)} +
a_1y^{(n - 1)} +
\dots +
a_{n - 1} \dot y +
a_n y = 
b_0u^{(n)} +
b_1u^{(n - 1)} +
\dots +
b_{n - 1}\dot u + 
b_n u$$

The main problem of this modelling is in the defining of the state variables. In fact, there are a lot of ways of defining the state variables. This section will show one way.

One way to obtain a state equation and output equation for this case is to define the following $n$ variables as a set of $n$ state variables:

$$
\begin{array}{l}
	x_1 & = & y - \beta_0u \\
	x_2 & = & \dot y - \beta_0\dot u - \beta_1u & = & \dot x_1 - \beta_1u \\
	x_3 & = & \ddot y - \beta_0 \ddot u - \beta_1\dot u - \beta_2u & = & \dot x_2 - \beta_2u \\
	& \vdots \\
	x_n & = & y^{(n - 1)} - \beta_0u^{(n - 1)} - \beta_1 u^{(n - 2)} - \dots - \beta_{n - 2}\dot u - \beta_{n - 1}u & = & \dot x_{n - 1} - \beta_{n - 1}u \\ \\
	\beta_0 & = & b_0 \\
	\beta_1 & = & b_1 - a_1\beta_0 \\
	\beta_2 & = & b_2 - a_1\beta_1 - a_2\beta_0 \\
	\beta_3 & = & b_3 - a_1\beta_2 - a_2\beta_1 - a_3\beta_0 \\
	 & \vdots \\
	 \beta_{n - 1} & = & b_{n - 1} - a_1\beta_{n - 2} - \dots - a_{n - 2}\beta_1 - a_{n - 1} \beta_0
\end{array}
$$

With the present choice of state variables, we obtain

#TODO

# Example

Consider the mechanical system shown in figure below.

![[Pasted image 20221020154649.png|175]]

From the diagram, the system equation is

$$m\ddot y + b\dot y + ky = u$$

We define state variables $x_1(t)$ and $x_2(t)$ as

$$\left\{
	\begin{array}{}
		x_1(t) = y(t) \\
		x_2(t) = \dot y(t)
	\end{array}
\right.$$

Then we obtain

$$
\left\{
	\begin{array}{l}
		\dot x_1 = x_2 \\
		\dot x_2 = 
		-\frac k m x_1 
		- \frac b m x_2
		+ \frac 1 m u
	\end{array}
\right.
$$

According to the equations, we can draw the following block diagram.

![[Pasted image 20221020155654.png]]

The equations can be written in vector-matrix form:

$$
\left[
	\begin{array}{}
		\dot x_1 \\
		\dot x_2
	\end{array}
\right] = 
\left[
	\begin{array}{}
		0 & 1 \\
		-\frac k m & -\frac b m
	\end{array}
\right]
\left[
	\begin{array}{}
		x_1 \\
		x_2
	\end{array}
\right] +
\left[
	\begin{array}{}
		0 \\
		\frac 1 m
	\end{array}
\right]u
$$

$$y = \left[
	\begin{array}{}
		1 & 0
	\end{array}
\right]
\left[
	\begin{array}{}
		x_1 \\
		x_2
	\end{array}
\right]
$$

Note that the standard form of state space is:

$$
\begin{array}{}
	\dot{\textbf x} = \textbf A \textbf x + \textbf B u \\
	y = \textbf {Cx} + Du
\end{array}
$$

The matrices are

$$\textbf A = 
\left[
	\begin{array}{}
		0 & 1 \\
		-\frac k m & -\frac b m
	\end{array}
\right], \qquad \textbf B = 
\left[
	\begin{array}{}
		0 \\
		\frac 1 m
	\end{array}
\right], \qquad \textbf C = 
\left[
	\begin{array}{}
		1 & 0
	\end{array}
\right], \qquad D = 0$$

---

參考資料:

Automatic Control class
Modern Control Engineering, 5th edition

---

link:

[[Matrix]]
[[Block Diagram]]
[[Laplace Transform]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.