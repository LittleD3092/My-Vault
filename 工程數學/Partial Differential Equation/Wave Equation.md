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

- $T_1, T_2$: tension forces at $P, Q$, respectively
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



---

參考資料:

工程數學筆記 [[6.2 - Intro to Wave Eqn.pdf]]

---

link:

[[Rigid Body]]