標籤: #工程數學 

---

This "wave" is referred to the waves traveling on a vibrating string, not ocean wave or other wave.

# Modeling

![[modelling a wave equation.png]]

Assumptions:
1. String has uniform density $\rho$
2. The tension from stretching ($T$) is much larger than force of gravity (so ignore gravity)
3. The problem is 1-D. Also, assume $u(x, t)$ is small, so that any point on the string is displaced only vertically.
4. The string has no bending stiffness.

We focus on a very small section of the overall problem.

![[modeling of small section of string.png]]

- $T_1, T_2$: Tension forces at $P, Q$, respectively
- $T_1, T_2$ are tangential to the local slope

Equation of motion (horizontal):

By assumption the string has no horizontal motion, so the horizontal components of $T_1, T_2$ must cancel out

$$T_1\cos \alpha = T_2\cos\beta = \text{ constant } = T$$

Equation of motion (vertical):

The vertical forces must equal to acceleration of the mass of string between $P-Q$

$$T_2\sin\beta - T_1\sin\alpha = \rho\Delta x\frac{\partial^2 u}{\partial t^2}$$

$\rho$: lengthwise density $[kg / m]$

We devide the vertical forces by $T$

$$\implies \frac{T_2\sin\beta}{T} - \frac{T_1\sin\alpha}{T} = \frac{\rho \Delta x}{T}\frac{\partial^2 u}{\partial t^2}$$

$$\implies \frac{T_2\sin\beta}{T_2\cos\beta} - \frac{T_1\sin\alpha}{T_1\cos\alpha} = \frac{\rho \Delta x}{T}\frac{\partial^2 u}{\partial t^2}$$

$$\implies \tan\beta - \tan\alpha = \frac{\rho \Delta x}{T}\frac{\partial^2 u}{\partial t^2}$$

![[one end of string when modeling.png]]

since tangent = slope

$$\implies
\frac 1 {\Delta x}\left[
	\left.
		\left(
			\frac{\partial u}{\partial x}
		\right)
	\right\vert_{x + \Delta x} - 
	\left.
		\left(
			\frac{\partial u}{\partial x}
		\right)
	\right\vert_x
\right] = 
\frac \rho T
\frac{\partial^2 u}{\partial t^2}$$

As $\Delta x \rightarrow 0$

$$\underline{
	c^2 \frac{\partial^2 u}{\partial x^2} = 
	\frac{\partial^2 u}{\partial t^2}
}_\#$$

$c^2 = \frac T \rho$, $c^2$ is always $\geq 0$
Equation above is 1D wave equation.

# Solution

- Equation
$$\frac{\partial^2 u}{\partial t^2} = c^2\frac{\partial^2 u}{\partial x^2}$$
- Boundary conditions
$$
\left.
	\begin{array}{}
		u(0, t) = 0 \\
		u(L, t) = 0
	\end{array}
\right\} \text{ fixed ends }
$$
- Initial conditions
	- Initial shape: $u(x, 0) = f(x)$
	- Initial velocity: $\dot u(x, 0) = g(x)$

To derive the solution, we have 3-step solution process
1. Assume $u(x, t) = F(x)G(t)$
2. Solve for $F(x)$ and $G(t)$ such that it satisfies the partial differential equation and boundary condition
3. Making sure it also satisfy the initial condition

## Step 1: Seperation of Variable

Assume $u(x, t)$ can be separated into

$$u(x, t) = \underbrace{ F(x) }_{\text{some function of } x}\cdot \underbrace{G(t)}_{\text{ some function of }t}$$

> Note: We're not saying all solutions of the wave equation will look like $F(x)G(t)$. We're just saying some solution will look like that, and we're looking at these solutions.

$$\therefore 
\left\{
	\begin{array}{}
		\frac{\partial^2 u}{\partial t^2} = F\ddot G \\
		\frac{\partial^2 u}{\partial x^2} = F''G
	\end{array}
\right.$$

Therefore, wave equation become

$$F\ddot G = c^2 F'' G$$

$$\frac{\ddot G}{c^2G} = \frac{F''}{F} = k$$

For the above equation, the left-side is a function only of time, and the middle is a function of space. We say they are both equal to constant $k$. 
(this equation represents the only way for a time and a space function to both be equal)

By seperating, we get two equations

$$
\left\{
	\begin{array}{}
		F'' - kF = 0 \\
		\ddot G - c^2kG = 0
	\end{array}
\right.
$$

## Step 2: Solving the ODE in a Way That Satisfy the Boundary Condition

| $$F''(x) - kF(x) = 0$$                                                                                                                                                                 | $$\ddot G(t) - c^2kG(t) = 0$$ |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------- |
| As is usual for ODE, try solution of the form: $F(x) = e^{rx}$ $$\frac{\partial^2}{\partial x^2}(e^{rx}) - ke^{rx} = 0$$ $$(r^2 - k)e^{rx} = 0$$ $$(r^2 - k) = 0$$ $$r = \pm\sqrt{k}$$ | Try: $G(t) = e^{st}$ $$\frac{\partial^2}{\partial t^2}(e^{st}) - c^2ke^{st} = 0$$ $$(s^2 - c^2k)e^{st} = 0$$ $$s^2 - c^2k = 0$$ $$s = \pm c\sqrt{k}$$                          |

If $k\neq 0$, there'll be two independent solutions for $F$ and $G$ each:

$$
\left\{
	\begin{array}{}
		F(x) = Ae^{\sqrt k x} + Be^{-\sqrt k x} \\
		G(t) = Ce^{c\sqrt k t} + De^{-c\sqrt k t}
	\end{array}
\right.$$

If $k = 0$, $F(x) = \text{constant}$, $G(t) = \text{constant}$. This is not interesting at all. Instead, we get $k\neq 0$ results:

$$u(x, t) = (Ae^{\sqrt k x} + Be^{-\sqrt k x})(Ce^{c\sqrt k t} + De^{-c\sqrt k t})$$

First, we have to satisfy the boundary condition: $u(0, t) = u(L, t) = 0$

> - The condition $u(t) = 0$ is true only if $A = -B$
> - The condition $u(t) = 0$ and $u(L, t) = 0$ is both true only if $A(e^{\sqrt{k}L} - e^{-\sqrt kL}) = 0$
>     - We can choose $A = 0$, but this is not interesting as it means $u(t) = 0$
>     - Instead we must have:
>     $$e^{\sqrt{k}L} - e^{-\sqrt kL} = 0$$
>     $$\implies e^{\sqrt k L} = e^{-\sqrt kL}$$
>     $$\implies e^{2\sqrt kL} = 1$$
> 
> One thing that satisfy this is:
> $$e^{2\pi ni} = \cos(2\pi n) + i\sin(2\pi n) = 1\qquad \text{for integer }n$$
> Thus we say
> $$e^{2\sqrt kL} = e^{2\pi ni} = 1$$
> $$\implies 2\sqrt kL = 2\pi ni$$
> $$\implies \sqrt k = n\frac \pi L i$$
> $$\implies k = -n^2\frac{\pi^2}{L^2}$$
> Overall, using the boundary condition we get 
> $$\left\{\begin{array}{}A & = & -B \\ k & = & -n^2\frac{\pi^2}{L^2}\end{array}\right.$$

$$\implies u(x, t) = A\left(
	e^{i\frac{n\pi}{L}x} - 
	e^{-i\frac{n\pi}{L}t}
\right)
\left(
	Ce^{i\frac{cn\pi}{L}t} +
	De^{-i\frac{cn\pi}{L}t}
\right)$$

$$\implies u(x, t) = 2iA\sin\left(
	\frac{n\pi}{L}x
\right)
\left[
	(C + D)\cos\left(
		\frac{cn\pi}{L}t
	\right) +
	i(C - D)\sin\left(
		\frac{cn\pi}{L}t
	\right)
\right]$$

$$\implies u(x, t) \equiv
\sin(\frac{n\pi}{L}x)
\left[
	\alpha_n\cos\left(
		\frac{cn\pi}{L}t
	\right) +
	\beta_n\sin\left(
		\frac{cn\pi}{L}t
	\right)
\right]$$

where 
$\alpha_n = 2iA(C + D)$
$\beta_n = -2A(C - D)$

## Step 3: Satisfying the Initial Condition

We have considerably narrow down the solution-spqce using the boundary condition.

Next, we nust make it satisfy the initial condition.

$$\left\{
	\begin{array}{}
		u(x, 0) = f(x) \\
		\dot u(x, 0) = g(x)
	\end{array}
\right.$$

Here we need to notice that because the wave equation is linear, any linear combo of solution is also a solution. In fact, in general we can write

$$u(x, t) = \sum_{n = 1}^\infty
\sin\left(
	\frac{n\pi}{L}x
\right)
\left[
	\alpha_n\cos\left(
		\frac{cn\pi}{L}t
	\right) +
	\beta_n\sin\left(
		\frac{cn\pi}{L}t
	\right)
\right]$$

> note: if we just look at the $x$-dependent part.
> - Realize that a specific "n" gives use a specific sine-wave shape on the string.
> - Here we're saying the full solution can be a linear combo of infinite different sine waves.

If we evaluate the equation (and its partial derivative) at $t = 0$

$$\left\{
	\begin{array}{}
		u(x, 0) & = & f(x) & = & \sum_{n = 1}^\infty \alpha_n\sin\left(
			\frac{n\pi}{L}x
		\right) \\
		\dot u(x, 0) & = & g(x) & = & \sum_{n = 1}^\infty \beta_n\frac{cn\pi}{L}\sin\left(
			\frac{n\pi}{L}x
		\right)
	\end{array}
\right.$$

> Recall from Fourier-Series, any smooth odd function can have any form:
> $$h(x) = \sum_{n = 1}^\infty b_n\sin\left(\frac{n\pi}{L}x\right)$$
> $$b_n = \frac 2 L \int_0^L h(x)\sin\left(\frac{n\pi}{L}x\right)dx$$
> With suitable replacement, we can pretend that the two equations above are both fourier series, and use the fourier series definition to find $\alpha_n, \beta_n$

If $f(x)\equiv h(x) \implies b_n = \alpha_n$

$$\alpha_n = \frac 2 L \int_0^L f(x)\sin\left(
	\frac{n\pi}{L}x
\right)dx$$

If $g(x)\equiv h(x) \implies b_n = \beta_n\frac{cn\pi}{L}$

$$\beta_n \frac{cn\pi}{L} = 
\frac 2 L \int_0^L g(x)\sin\left(
	\frac{n\pi}{L}x
\right)dx$$

Thus, overall

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

Each term in the sum is called a "mode".

![[different mode string analysis.png]]

## Special Case

If the string has zero initial velocity,

$$\beta_n = \frac{2}{cn\pi}
\int_0^L \underbrace{
	g(x)
}_{ = \dot u(x, 0) = 0}
\sin\left(
	\frac{n\pi}{L}x
\right)dx$$

Then,

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

## Special Interpretation: Two-Sided Waves

Using the previous $g(x) = 0$ equation:

$$u(x, t) = \sum_{n = 1}^\infty
\alpha_n\cos\left(
	\frac{cn\pi}{L}t
\right)\sin\left(
	\frac{n\pi}{L}x
\right)$$

> Trigonometric Identity
> $$\sin x \cos y = \frac 1 2 \left[\sin(x + y) + \sin (x - y)\right]$$

$$ = \sum_{n = 1}^\infty
\alpha_n \frac 1 2\left[
	\sin\left(
		\frac{n\pi}{L}x + \frac{cn\pi}{L}t
	\right) +
	\sin\left(
		\frac{n\pi}{L}x - \frac{cn\pi}{L}t
	\right)
\right]$$

$$ = \sum_{n = 1}^\infty
\alpha_n\frac 1 2\left\{
	\sin\left[
		\frac{n\pi}{L}(x + ct)
	\right] + \sin\left[
		\frac{n\pi}{L}(x - ct)
	\right]
\right\}$$

$$ = \frac 1 2 \sum_{n = 1}^\infty
\alpha_n\sin\left[
	\frac{n\pi}{L}(x + ct)
\right] +
\frac 1 2 \sum_{n = 1}^\infty
\alpha_n\sin\left[
	\frac{n\pi}{L}(x - ct)
\right]$$

$$\implies u(x, t) = \frac 1 2
\left[
	f^*(x + ct) +
	f^*(x - ct)
\right]$$

$f^*$ is some odd function.

- What's important:
	- When $t = 0$, the two $f^*$ terms overlap.
	- When $t$ increase, $f^*(x + ct)$ move left. $f^*(x - ct)$ move right. It is like the initial deflection move away in a left-traveling and right-traveling waves.
	![[left-traveling and right-traveling waves.png]]

---

參考資料:

工程數學筆記 [[6.2 - Intro to Wave Eqn.pdf]]

---

link:

[[Rigid Body]]
[[Higher Order DE解法]]
[[Fourier Series]]
[[Trigonometric Function]]