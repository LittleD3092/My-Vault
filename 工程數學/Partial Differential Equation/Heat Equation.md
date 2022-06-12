標籤: #工程數學 

---

# Heat Equation

## Fundamental Physics

For 1D problem, heat flow ($v$) from high to low temperature ($u$) in proportion to the temperature gradient:

$$v = -K\frac{du}{dx}$$

For 3D, we use vector form

$$\vec v = -K\left[
	\begin{array}{}
		\partial u / \partial x \\
		\partial u / \partial y \\
		\partial u / \partial z
	\end{array}
\right] = -K\text{grad} (u)$$

$u = u(x, y, z, t)$

Assume the following are all constant:
- thermal conductivity $K$
- specific heat $\sigma$
- density $\rho$

## 3D Model

![[3D model of heat equation.png]]

$$
\begin{array}{}
	\vec v \cdot \vec n > 0 & \text{heat flow out of }T \text{ through }S \\
	\vec v\cdot \vec n < 0 & \text{heat flow in of }T \text{ through }S
\end{array}
$$

Therefore the amount of heat leaving through a surface $S$:

$$\iint_S \vec v\cdot \vec n dA$$

Using [[Gauss's Divergence Theorem]]

$$\text{Heat leaving }S = \text{Time-rate change of heat energy in }T$$

And Universal Law:

$$\text{Heat change} = \text{time-rate change of energy in }T$$

Heat leaving $S$:

$$\iint_S \vec v\cdot \vec n dA = 
-K\iint_S (\text{grad}(u))\cdot \vec n dA$$

Time-rate change of heat energy in $T$:

$$\underline{-K\iiint_T\text{div}(\text{grad}(u))dxdydz = -K\iiint_T\nabla^2 udxdydz}$$

Using the material properties $\sigma$ and $\rho$, we can get the total heat energy in $T$ is:

$$H = \iiint_T\sigma\rho udxdydz$$

Then we take the differential of $H$, we may get heat change:

$$\underline{-\frac{\partial H}{\partial t} = -\iiint_T \sigma\rho\frac{\partial u}{\partial t}dxdydz}$$

Using heat change and time-rate change of heat energy in $T$, we have following equation

$$-\iiint_T\sigma\rho\frac{\partial u}{\partial t}dxdydz = -K\iiint_T\nabla^2 udxdydz$$

Then we gather all constants $K, \sigma, \rho$ and define a constant $c$, thermal diffusivity

$$\implies -\iiint_T\frac{\partial u}{\partial t}dxdydz = -c^2\iiint_T\nabla^2u dxdydz$$

$c^2 = \frac{K}{\sigma\rho}$: Thermal Diffusivity

$$\implies \iiint_T\left(
	\frac{\partial u}{\partial t} -
	c^2\nabla^2 u
\right)dxdydz = 0$$

$$\implies \underline{
	\frac{\partial u}{\partial t} = 
	c^2\nabla^2 u
}_\#$$
$c^2 = \frac{K}{\sigma\rho}$
$K$: thermal conductivity
$\sigma$: specific heat
$\rho$: density

The equation above is the general heat equation. Note that $\nabla^2 u$ also models other diffusion process.

## 1D Heat Equation with Isothermal Boundary Condition

> Before start, lets see [[Wave Equation]] compared to Heat Equation
> [[Wave Equation]]:
> $$u_{tt} - c^2u_{xx} = 0$$
> Heat Equation:
> $$u_t - c^2u_{xx} = 0$$
> They are very similar, so the solution will employ almost same steps.

Assume narrow long bar ($\approx$ 1 dimension). The ends ($x = 0, L$) are "isothermal", therfore $u = 0$ at the ends no matter what. Given initial temperature $f(x)$, find $u(x, t)$.

![[1d heat equation boundary condition model.png]]

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
	$$\implies \underline{G_n(t) = B_ne^{-\lambda_n^2 t}}_\#$$
	2. $F$:
	$$F'' + p^2F = 0$$
	General solution: $$F(x) = A\cos px + B\sin px$$
	Apply boundary condition:
	$$u(0, t) = F(0)G(t) = 0$$
	$$u(L, t) = F(L)G(t) = 0$$
	Since $G(t) = 0\longrightarrow u = 0$, not interesting
	Therefore let $F(0) = 0 = A, F(L) = 0 = B\sin pL$
	Implies $$A = 0$$ and $\sin pL = 0$, which $$p = \frac{n\pi}{L}\ (n = 1, 2, \dots)$$
	$$\implies F_n(x) = \sin\frac{n\pi x}{L}, \ n = 1, 2, \dots$$
6. Thus $$u_n(x, t) = G(t)F(x) = B_n\sin(\frac{n\pi x}{L})e^{-\lambda_n^2 t}$$
7. The full solution by superposition
$$\underline{u(x, t) = \sum_{n = 1}^\infty u_n(x, t) = \sum_{n = 1}^\infty B_n\sin(\frac{n\pi x}{L})e^{-\lambda_n^2t}}_\#$$
$\lambda_n = \frac{cn\pi}{L}$
8. Bring in the initial condition and calculate $B_n$
$$u(x, 0) = \sum_{n = 1}^\infty B_n\sin\frac{n\pi x}{L}dx = f(x)$$
Fourier Coeffecient:
$$\underline{B_n = \frac 2 L\int_0^Lf(x)\sin\frac{n\pi x}{L}dx,\ n = 1, 2\dots}_\#$$

## 1D Heat Equation with "Adiabatic" (Insulated) Boundary Condition

The key difference from isothermal case is that the end-point can be any temperature now, as long as heat flows across the ends are zero.

$$u_x(0, t) = 0 \longrightarrow F'(0)G(t) = 0$$
$$u_x(L, t) = 0 \longrightarrow F'(L)G(t) = 0$$

If $F(x)$'s general solution was

$$F(x) = A\cos px + B\sin px$$
$$\implies F'(x) = -Ap\sin px + Bp\cos px$$

Applying boundary condition

$$\implies \left\{
	\begin{array}{}
		A & = & 1 \\
		B & = & 0 \\
		p & = & p_n & = & \frac{n\pi}{L} & ,n = 0, 1, 2, 3 \dots
	\end{array}
\right.$$

$$\therefore \underline{u_n(x, t) = A_n\cos\frac{n\pi}{L}e^{-\lambda_n^2 t}}_\#$$
$\lambda_n = \frac{cn\pi}{L}\ , n = 0, 1, 2, \dots$

Using the initial condition:

$$\underline{A_0 = \frac 1 L \int_0^Lf(x)dx}_\#$$

$$\underline{A_n = \frac 2 L\int_0^L f(x)\cos\left(
	\frac{n\pi x}{L}dx
\right)\ , n = 1, 2, \dots}_\#$$

## 2D Heat Equation

$$\frac{\partial u}{\partial t} = c^2\nabla^2 u = c^2\left(
	\frac{\partial^2 u}{\partial x^2} +
	\frac{\partial^2 u}{\partial y^2}
\right)$$

If we assume steady: if $u$ doesn't change with $t$

$$\frac{\partial u}{\partial t} = 0 \qquad\text{usually when }t \rightarrow \infty$$

$$\therefore \nabla^2u = 0$$

To make life simple, only consider a rectangular region $R$

![[rectangular region.png]]

- This is called a boundary value problem (BVP) since time does not affect the solution.
- There are 3 kinds of boundary conditions
	1. $u$ is given on $C$ (Dirichlet Problem)
	2. Normal derivative $\partial u / \partial n$ given on $C$ (Neumann Problem)
	3. Mixed type (Robin Problem)

### Dirichlet Problem

![[dirichlet problem.png]]

Let's model the spread of heat from the top-edge ($u = f(x)$) through region $R$.

1. The heat equation $\nabla^2u = 0$ is linear homogeneous, so we can use separation-of-variables

$$u(x, y) = F(x)G(y)$$

$$\nabla^2u = \frac{\partial^2u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} = 0$$

$$\implies \frac{\partial^2 u}{\partial x^2} = -\frac{\partial^2 u}{\partial y^2}$$

$$\implies G(y)\frac{\partial^2 F}{\partial x^2} = -F(x)\frac{\partial^2 G}{\partial y^2}$$

$$\implies \frac 1 F \cdot \frac{\partial^2 F}{\partial x^2} = -\frac 1 G\frac{\partial^2G}{\partial y^2} = -k$$

2. Two equations

$F$:

$$\frac{\partial^2F}{\partial x^2} + kF = 0$$

Using Fourier Series:

$$F_n = \sin\frac{n\pi}{a}x\ \ , n = 1, 2, \dots$$

where

$$k = (\frac{n\pi}{a})^2$$

Use Fourier Series to approx the ODE solution. And from there, get $k$.

$G$:

$$\frac{\partial^2 G}{\partial y^2}-kG = \frac{\partial^2G}{\partial y^2} - (\frac{n\pi}{a})^2G = 0$$

ODE solutions:

$$G_n(y) = A_ne^{n\pi\frac y a} + B_ne^{-n\pi\frac y a}$$

Boundary Conditions of $y$

$$G_n(0) = 0 = A_n + B_n$$

$$\therefore B_n = -A_n$$

$$G_n(y) = A_n(e^{n\pi\frac{y}{a}} - e^{-n\pi\frac y a})$$

$$ = A_n^2\sinh(\frac{n\pi y}{a})$$

$$\equiv A^*\sinh(\frac{n\pi y}{a})$$

3. Combine

$$u_n(x, y) = F_nG_n$$

$$ = A_n^*\sin(\frac{n\pi x}{a})\sin(\frac{n\pi y}{a})$$

$$\implies \underline{u(x, y) = \sum_{n = 1}^\infty
u_n(x, y) = 
\sum_{n = 1}^\infty A^*_n\sin(\frac{n\pi x}{a})\sinh(\frac{n\pi y}{a})}$$

4. Use the final boundary condition: $u(x, y = b) = f(x)$

$$u(x, b) = \sum_{n = 1}^\infty A_n^*\sin(\frac{n\pi x}{a})\sinh(\frac{n\pi b}{a}) = f(x)$$

if $\sin(\frac{n\pi x}{a})$ is the fourier basis, $A_n^*\sinh(\frac{n\pi b}{a})$ must be the fourier coefficient.

$$\therefore\underline{
	A_n^* = \frac{2}{a\sinh(n\pi b / a)}\int_0^a f(x)\sin(\frac{n\pi x}{a})dx
}_\#$$

---

參考資料:

[[6.5 - Heat Eqn.pdf]]

---

link:

[[Gauss's Divergence Theorem]]
[[Laplacian]]
[[Wave Equation]]
[[Fourier Series]]
[[Differential Equation]]
[[Euler Formula]]