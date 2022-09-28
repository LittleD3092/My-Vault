標籤: #automatic-control 

---

[TOC]

---

The control systems is often modelled as a mathematical model, therefore this note shows how to model the system dynamics in mathematical format.

> # Causality
> 
> Before we begin, we first need to know what causality is. Causality is a rule that says "current output of the system depends on the past input but does not depend on the future input".
>
> For example, an output $@ t = 0$ depends on the input for $t \leq 0$, but does not depend on the input for $t > 0$.
>
> This rule may be simple, but it is important.

# Format

The mathematical model of a control system is usually [[Differential Equation]] or difference equation. We give those model names:

1. State-space representation (differential equation): suitable for optimal control, nonlinear systems.
2. Tranfer funcction representation (difference equation): suitable for transient response, single-input-single-output, linear time-invariant system.

The course of automatic control (I) focus on the second one.

## Linear System

A system is called linear if the principle of superposition applies.

$$u_1 \rightarrow y_1$$

$$u_2 \rightarrow y_2$$

Superposition:
$$u_1 + u_2 \rightarrow y_1 + y_2$$

Multiply by a constant:
$$cu_1 \rightarrow cy_1$$

## Linear Time-Invariant System (LTI)

A differential equation is linear and time-invariant if the coefficients are constnat. The coefficients should not depend on time.

ex.

$$
\begin{array}{}
	\dot x = ax + bu & \implies & LTI \\
	\dot x = a(t)x + b(t)u & \implies & time-variant
\end{array}
$$

The system often uses differential equation to analysis.

There are two ways of analysis:

- [[#Transfer Function]]
- [[#State Space]]

### Transfer Function

Transfer function is a property of a [[#Linear System]] that decribe the relationship between input and output.

$$\text{Transfer Function} \triangleq G(s) = 
\left.\frac{ \mathcal{L}(\text{output}) }{ \mathcal{L}(\text{input}) }\right\vert_{\text{zero initial condition}}$$

The $\mathcal L$ represent [[Laplace Transform]].

- Order: The highest power of $s$ in the denominator of the transfer function is called the ==order== of the system.
$$\text{e.g. }G(s) = \frac{5s + 6}{s^2 + 2s + 3}, \text{ order } = 2$$

- Note that transfer function is limited to systems that are described by linear time-invariant [[Differential Equation]]s.
- Note that transfer function is independent of the magnitude & nature of the input function.
- Transfer function can be obtained from differential equations or established experimentally.

#### Impulse Response Function

We may do a [[Inverse Laplace Transform]] to the transfer function. What we get is called ==implulse response function==, represented as $g(t)$. 

$$\mathcal{L}^{-1}(G(s)) = g(t)$$

The impulse response function is the response of a linear time-invariant system to a unit impulse input when the initial conditions are zero. This is used as a characteristic of a system.

Let's see why $\mathcal L^{-1}(G(s)) = g(t)$ is a impulse response:

When $x(t)$ is an impulse function


$$s(t) \overset \Delta =
\left\{
	\begin{array}{}
		0 & t \neq 0 \\
		\infty & t = 0
	\end{array}
\right.
\quad\& \quad 
\int_{-\infty}^\infty s(t)dt = 1
$$

Do laplace transform:

$$x(s) = \mathcal L (s(t))$$

$$ = \int_{0^-}^\infty e^{-st}s(t)dt$$

$$ = \int_{0^-}^\infty\delta(t)dt = 1$$

---

$$G(s) = \frac{Y(s)}{X(s)}$$

$$Y(s) = G(s) \cdot X(s)$$

when $x(t) = s(t)$

$$\implies x(s) = 1$$

$$\implies Y(s) = G(s)$$

$$y(t) = \mathcal L^{-1}(Y(s)) = \mathcal L^{-1}(G(s)) = g(t)$$

$\implies g(t)$ is the impulse reponse of the system

#### Convolution

In a linear time invariant system, the output response is a convolution of input function and impulse responce of the system.

$$y(t) = \int_0^t g(\tau)x(t - \tau)d\tau$$

---

We can prove the above equation by using [[Inverse Laplace Transform]]:

Because the following is true:

$$
\left\{
\begin{array}{}
	Y(s) & = & G(s) \cdot X(s) \\
	Y(s) & = & \mathcal L(y(t)) \\
	X(s) & = & \mathcal L(x(t)) \\
	G(s) & = & \mathcal L(g(t))
\end{array}
\right.
$$

Therefore we can do a [[Inverse Laplace Transform]] to the first equation and get the following result:

$$y(t) = \int_0^t x(\tau) \cdot g(t - \tau)d\tau$$

$$ = \int_0^t g(\tau) x(t - \tau)d\tau$$

where $g(t), x(t) = 0$ for $t < 0$

$\implies$ In a LTI system, the output response is a convolution of input function and impulse response of the system.

### State Space

To model using state space, we use something like a matrix. For a nonlinear $n$-state, $r$-input, $m$-output system described in state space form.

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

- $x_1, x_2, \dots, x_n$ are the states (or state variables) of the system. They are the smallest set of variables that completely determine the behavior of the system.

> State variables need NOT be measurable nor represent physical quantities.

- The state space representation can be written in a vector form.

$$\left[
	\begin{array}{}
		\dot x_1 \\
		\dot x_2 \\
		\vdots \\
		\dot x_n
	\end{array}
\right]_{n \times 1} = 
\left[
	\begin{array}{}
		f_1(\dots) \\
		f_2(\dots) \\
		\vdots \\
		f_n(\dots)
	\end{array}
\right]$$

$$\left[
	\begin{array}{}
		\dot y_1 \\
		\dot y_2 \\
		\vdots \\
		\dot y_m
	\end{array}
\right]_{m \times 1} = 
\left[
	\begin{array}{}
		g_1(\dots) \\
		g_2(\dots) \\
		\vdots \\
		g_m(\dots)
	\end{array}
\right]$$

If the above equations are linearized at an operation point, we can use four matrix ${\bf A}(t), {\bf B}(t), {\bf C}(t), {\bf D}(t)$ to represent $f$ and $g$:

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

Let's use $\dot x(t), u(t), y(t)$ to simplify the above representation:

$$\begin{array}{}
	\dot x(t) = {\bf A}(t) X(t) + {\bf B}(t) u(t) \\
	y(t) = {\bf C}(t)X(t) + {\bf D}(t)u(t)
\end{array}$$

- ${\bf A}(t)$: state matrix
- ${\bf B}(t)$: input matrix
- ${\bf C}(t)$: Output matrix
- ${\bf D}(t)$: Direct transmission matrix

If the above system is time-invariant, the matrix ${\bf A}, {\bf B}, {\bf C}, {\bf D}$ can be constant:

$$
\begin{array}{}
	\dot x(t) = {\bf A}X(t) + {\bf B}u(t) \\
	y(t) = {\bf C}X(t) + {\bf D}u(t)
\end{array}
$$

Where ${\bf A}, {\bf B}, {\bf C}, {\bf D}$ are constant matrix.

---

參考資料:

Automatic Control class

---

link:

[[Laplace Transform]]