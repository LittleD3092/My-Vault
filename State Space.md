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

Since the transfer fuction is defined as the laplace transform of input and output when initial conditinos are zero, $\textbf x(0)$

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