# Engineering Math II$\qquad$Final-Exam

## Sec 2

### 2.1

When we have a periodic signal, it is good to know the frequency of the signal. Fourier series can decompose the signal into a series of $\sin$ and $\cos$ signals, then we know what frequency the signal is composed of.

For a signal $f(x)$, we can convert it to:

$$f(x) = a_0 + \sum_{n = 1}^\infty (a_n\cos\frac{n\pi}{L}x + b_n\sin\frac{n\pi}{L}x)$$ $$a_0 = \frac 1 {2L}\int_{-L}^L f(x)dx$$ $$a_n = \frac 1 L \int_{-L}^L f(x)\cos \frac{n\pi x}{L}dx$$ $$b_n = \frac 1 L \int_{-L}^L f(x)\sin\frac{n\pi x}{L}dx$$

where $L$ is half period.

The equation above is fourier series.

### 2.2

Fourier Series:

$$f(x) = a_0 + \sum_{n = 1}^\infty (a_n\cos\frac{n\pi}{L}x + b_n\sin\frac{n\pi}{L}x)$$ $$a_0 = \frac 1 {2L}\int_{-L}^L f(x)dx$$ $$a_n = \frac 1 L \int_{-L}^L f(x)\cos \frac{n\pi x}{L}dx$$ $$b_n = \frac 1 L \int_{-L}^L f(x)\sin\frac{n\pi x}{L}dx$$

We use Fourier series to represent $f(x)$ in a series which is more understandable. $f(x)$ must be periodic.

Fourier Integral:

$$f(x) = \int_0^\infty\left[A(w)\cos wx + B(w)\sin wx\right]dw$$ $$A(w) = \frac 1 \pi\int_{-\infty}^\infty f(v)\cos wv dv$$ $$B(w) = \frac 1 \pi \int_{-\infty}^\infty f(v)\sin wv dv$$

If the signal we are processing isn't periodic, we should use Fourier Integral.

Fourier Transform:

$$\hat f(w) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty f(x)e^{-iwx}dx$$

The fourier transform $\hat f(w)$ is equivalent to the Fourier coefficient $A(w)$ and $B(w)$. $\hat f(w)$ is the amplitude of $e^{-iwx}$ that is needed to form $f(x)$.

### 2.3

If we only have one part of $f(x)$ defined, say $0 < x < L$, we can assume that $f(x)$ is an even function or an odd function, and get our fourier series. This process is called half-range expansion.

### 2.4

- Odd function: A function that is symmetric to the origin. Sine function is an odd function.
- Even function: A function that is symmetric to the $y$-axis. Cosine function is an even function.

If we know whether $f(x)$ is even or odd function, we can simplify Fourier Series into Fourier sine series or Fourier cosine series. This makes calculation simpler.

### 2.5

Because in wave equation, we are calculating the acceleration of the mass of string, so we have 2nd-order equation.

In heat equation, we are calculating heat flow, which is velocity, so we have 1st-order equation.

### 2.6

D'Alembert think the Fourier series solution is not simple enough, and find out that by introducing new variables

$$v = x + ct$$

$$w = x - ct$$

one can obtain another form of solution as follows.

$$
u(x, t) = \frac 1 2\left[
	f(x + ct) + f(x - ct)
\right] + \frac{1}{2c}
\int_{x - ct}^{x + ct} g(s)ds
$$
If the initial velocity $\dot u(x, 0) = g(x) = 0$, we can make it even simpler:
$$
	u(x, t) = \frac 1 2
	\left[
		f(x + ct) + f(x - ct)
	\right]
$$

### 2.7

We need two boundary conditions by fixed ends.

$$u(0, t) = 0$$

$$u(L, t) = 0$$

And two initial conditions of initial shape and initial velocity.

$$u(x, 0) = f(x)$$

$$\dot u(x, 0) = g(x)$$

### 2.8

The orange term is shape and the blue term is motion. The "n" in the solution is called the "mode" of the string.
 If we take partial derivative with $t$ of the orange and blue term, we find that the orange term is independent of $t$, therefore represents shape, and the blue term represent motion.

## Sec 4.1:

### a. 

Assumptions:
1. String has uniform density $\rho = 50\frac g m$
2. The tension from stretching ($T$) is much larger than force of gravity (so ignore gravity)
3. Assume the problem is 1-D. Also, assume $u(x, t)$ is small, so that any point on the string is displaced only vertically.
4. The string has no bending stiffness.

### b. 

The boudary conditions are that both ends are fixed.

$$
\left.
	\begin{array}{}
		u(0, t) = 0 \\
		u(L, t) = 0
	\end{array}
\right\} \text{ fixed ends }
$$

### c. 

$$c^2 = \frac T \rho$$

Substituting values:

$$\implies 400 = \frac{T}{0.05}$$

$$\implies \underline{T = 20 \text{N}}_\#$$

### d. 

The $u_n$ is one of the solution. However, because the wave equation is linear, any linear combo of solution is also a solution. Therefore, we need to sum $u_n$ to infinitely many terms.

### e.

Because no initial movement, 

$$
	u(x, t) = \sum_{n = 1}^\infty
	\sin\left(
		\frac{n\pi}{L}x
	\right)
	\left[
		\alpha_n\cos\left(
			\frac{cn\pi}{L}t
		\right)
	\right]
$$

$$	\alpha_n = \frac 2 L
	\int_0^L f(x)\sin
	\left(
		\frac{n\pi}{L}x
	\right)dx$$

$\alpha_n$ is:

$$\implies\alpha_n = \frac 2 1\int_0^1 10\sin(\frac{4\pi}{1}x)\sin(\frac{n\pi}{1}x)dx$$

$$\implies \alpha_n = \frac{80\sin(\pi n)}{\pi(n^2 - 16)}$$

Therefore $u(x, t)$ is:

$$	
\underline{u(x, t) = \sum_{n = 1}^\infty
\sin\left(
	n\pi x
\right)
\left[
	\frac{80\sin(\pi n)}{\pi(n^2 - 16)}\cdot \cos\left(
		20\pi nt
	\right)
\right]}_\#$$

### f. 

![[Figure_1 1.png]]

### g.

If the tension increases, the pitch of the sound generated is increased.

## Sec 4.2

### a.

$$\frac{\partial u}{\partial t} - c^2 \frac{\partial^2 u}{\partial x^2} = 0$$

where

$$c^2 = \frac{K}{\sigma \rho}$$

### b.

1. Assume $$u(x, t) = F(x)G(t)$$
2. Heat Equation becomes $$F\dot G = c^2F''G$$
3. Seperate $x$ and $t$ function $$\frac{\dot G}{c^2 G} = \frac{F''}{F} = k$$ $k$: some variable
4. For $k = 0$, and $k > 0$, only $u \equiv 0$ works. For $k < 0$, let $k = -p^2$ $$\frac{\dot G}{c^2G} = \frac{F''}{F} = -p^2$$
5. Seperately solve two ODEs
	1. $G$:
	$$\dot G + c^2p^2G = 0$$
	$$\implies \dot G + \lambda_n^2G = 0$$
	$\lambda_n \equiv\frac{cn\pi}{L}$
	$p = \frac{n\pi}{L}$
	$$\implies \underline{G_n(t) = B_ne^{-\lambda_n^2 t}}$$
	2. $F$:
	$$F'' + p^2F = 0$$
	General solution: $$F(x) = A\cos px + B\sin px$$
	Apply boundary condition:
	$$u(0, t) = F(0)G(t) = 0$$
	$$u(L, t) = F(L)G(t) = 0$$
	Since $G(t) = 0\longrightarrow u = 0$, not interesting
	Therefore let $F(0) = 0 = A, F(L) = 0 = B\sin pL$
	Implies $$A = 0$$ and $\sin pL = 0$, which $$p = \frac{n\pi}{L}\ (n = 1, 2, \dots)$$
	$$\implies \underline{F_n(x) = \sin\frac{n\pi x}{L}, \ n = 1, 2, \dots}$$
6. Thus $$u_n(x, t) = G(t)F(x) = B_n\sin(\frac{n\pi x}{L})e^{-\lambda_n^2 t}$$
7. The full solution by superposition
$$\underline{u(x, t) = \sum_{n = 1}^\infty u_n(x, t) = \sum_{n = 1}^\infty B_n\sin(\frac{n\pi x}{L})e^{-\lambda_n^2t}}_\#$$
$\lambda_n = \frac{cn\pi}{L}$
8. Bring in the initial condition and calculate $B_n$
$$u(x, 0) = \sum_{n = 1}^\infty B_n\sin\frac{n\pi x}{L}dx = f(x)$$
Fourier Coeffecient:
$$\underline{B_n = \frac 2 L\int_0^Lf(x)\sin\frac{n\pi x}{L}dx,\ n = 1, 2\dots}_\#$$

### c.

When time goes to infinity, each $u_n$ becomes significantly small, means that the "shaper" of each $u_n$, which is $\sin(\frac{n\pi x}{L})$, each has very little influence. Sum $u_n$ up, we get a evenly distributed $u$ over $x$, except two ends $x = 0$ and $x = L$, where $u = 0$

### d.

From (b), we found out that $u$ is a sine fourier series, therefore cosine function in $u$ is not possible.