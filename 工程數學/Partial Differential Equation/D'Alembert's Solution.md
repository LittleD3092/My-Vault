標籤: #工程數學 

---

# Motivation

Our previous solution for $\dot u(x, 0) = 0$ case

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

is not very simple.

In wave equation, we see with some transformation

$$\implies u(x, t) = \frac 1 2
\left[
	f^*(x + ct) +
	f^*(x - ct)
\right]$$

for odd function $f^*$

So D'Alembert observed that a solution can be obtained by introducing new variables

$$v \equiv x + ct$$
$$w \equiv x - ct$$

# Solution

Let $u(x, t) \rightarrow u(v, w)$

$$v = x + ct$$
$$w = x - ct$$

The derivatives:

$$\frac{\partial u}{\partial x} = u_x = u_vv_x + u_ww_x = u_v + u_w$$
.
$$\frac{\partial^2 u}{\partial x^2} = u_{xx} = (u_v + u_w)_x$$
$$= (u_v + u_w)_vv_x + (u_v + u_w)_ww_x$$
$$= u_{vv} + 2u_{vw} + u_{ww}$$
.
$$\frac{\partial^2 u}{\partial t^2} = 
\frac{\partial}{\partial t}\left(
	u_v v_t + u_w w_t
\right)$$
$$ = \frac{\partial}{\partial t}(cu_v - cu_w)$$
$$ = c(u_{vw}w_t + u_{vv}v_t)
- c(u_{vw}v_t + u_{ww}w_t)$$
$$ = c(-cu_{vw} + cu_{vv})
- c(cu_{vw} - cu_{ww})$$
$$ = c^2(u_{vv} - 2u_{vw} + u_{ww})$$

The new wave equation:

$$c^2 \frac{\partial^2 u}{\partial x^2} = \frac{\partial^2 u}{\partial t^2}$$
$$\implies c^2(u_{vv} - 2u_{vw} + u_{ww}) = c^2(u_{vv} + 2u_{vw} + u_{ww})$$
$$\underline{
	u_{vw} \equiv \frac{\partial^2 u}{\partial w \partial v} = 0
}_\#$$

$\frac{\partial^2 u}{\partial w\partial v}$ is nice because it only has one term.

$$\frac{\partial u}{\partial v} = h(v)$$

$$u = \int h(v)dv + \psi(w)$$

$$\equiv \phi(v) + \psi(w)$$

$$ = \underline{
	\phi(x + ct) + \psi(x - ct)
}_\#$$

The equation above is the d'Alembert's solution.

## Finding $\psi$ and $\phi$ using initial conditions

After we found that 

$$u = \phi(x + ct) + \psi(x - ct)$$

It's time to find what $\phi$ and $\psi$ are.

Initial conditions we'll consider

$$
\left\{
	\begin{array}{}
		u(x, 0) = f(x) \\
		u_t(x, 0) = g(x)
	\end{array}
\right.
$$

Plug in the initial condition to the equation

> Note:
> $$\frac{\partial u}{\partial t} = \frac{\partial \phi}{\partial t} + \frac{\partial \psi}{\partial t}$$
> and $\frac{\partial \phi}{\partial t}$ is
> $$\frac{\partial \phi}{\partial t} = \frac{\partial \phi}{\partial v}\cdot \frac{\partial v}{\partial t}$$
> $$ = \frac{\partial \phi}{\partial v}\cdot c$$
> $$ = \frac{\partial \phi}{\partial(x + ct)}\cdot c$$
> At: $t = 0$:
> $$ = \frac{\partial \phi}{\partial x}\cdot c = c\phi'$$
> The same way works for $\frac{\partial \psi}{\partial t}$

$$
\left\{
	\begin{array}{}
		u(x, 0) = \phi(x) + \psi(x) = f(x) \\
		u_t(x, 0) = c\phi'(x) - c\psi'(x) = g(x)
	\end{array}
\right.
$$

By dividing $c$ and integrate

$$
\implies\left\{
	\begin{array}{}
		\phi(x) + \psi(x) & = & f(x) \\
		\phi(x) - \psi(x) & = & \frac 1 c\int_{x_0}^x g(s) ds + k(x_0)
	\end{array}
\right.
$$

- $k(x_0) = \phi(x_0) - \psi(x_0)$

兩式相加和相減可以求出 $\phi(x)$ 和 $\psi(x)$

$$
\implies \left\{
	\begin{array}{}
		2\phi(x) = f(x) + \frac 1 c \int_{x_0}^x g(s)ds + k(x_0) \\
		2\psi(x) = f(x) - \frac 1 c\int_{x_0}^x g(x)ds - k(x_0)
	\end{array}
\right.
$$

$$
\implies \left\{
	\begin{array}{}
		\phi(x) = \frac 1 2f(x) + \frac 1 {2c}\int_{x_0}^xg(s)ds + \frac 1 2 k(x_0) \\
		\psi(x) = \frac 1 2 f(x) - \frac 1 {2c}\int_{x_0}^x g(s)ds - \frac 1 2k(x_0)
	\end{array}
\right.
$$

$$
\implies \left\{
	\begin{array}{}
		\phi(x + ct) = \frac 1 2f(x + ct) + \frac 1 {2c}\int_{x_0}^{x + ct}g(s)ds + \frac 1 2 k(x_0) \\
		\psi(x - ct) = \frac 1 2 f(x - ct) - \frac 1 {2c}\int_{x_0}^{x - ct} g(s)ds - \frac 1 2k(x_0)
	\end{array}
\right.
$$

Substitude into $u(x, t)$

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

## Boundary Conditions

The solution above did not consider boundary conditions.

On an infinite string, the initial deflections move away and never return. That's OK because the string is infinite.

![[infinite string scenario.png]]

When the string is tied at the ends, whatever wave traveling to the end must reflect back and in the reversed amplitude.

![[string tied scenario.png]]

We make $f(x)$ an odd periodic function with $P = 2L$

![[periodic function with P = 2L.png]]

This solves our problem.

---

參考資料:

工程數學筆記 [[6.4 - dAlembert Solution to Wave Eqn.pdf]]

---

link:

[[Wave Equation]]