# Math Application Project 2

- 109611066 吳典謀
- 109611030 陳柏文
- 109611004 張瀚元

## 4. What You Need To Do:

### 1. Defining your scalar field:

- <font color = "#3a86ff">Come up with an equation that describes the 3D temperature-field (i.e. a scalar field 𝑇(𝑥, 𝑦, 𝑧)), which satisfy the three constraints given above.</font>

A two-dimentional Gaussian function:

$$f(x, y, z) = A e^{
	-\left(
		\frac{(x - x_0)^2}{2\sigma_x^2} +
		\frac{(y - y_0)^2}{2\sigma_y^2} +
		\frac{(z - z_0)^2}{2\sigma_z^2}
	\right)
}$$

where $A$ is amplitude, $x_0, y_0, z_0$ is the center, and $\sigma_x, \sigma_y, \sigma_z$ are $x$, $y$ and $z$ spreads

in our case, $x_0, y_0, z_0 = 0$, $\sigma_x = \sigma_y = \sigma_z$

$$\implies f(x, y, z) = A e^{
	-\left(
	\frac{x^2}{2\sigma^2} +
	\frac{y^2}{2\sigma^2} +
	\frac{z^2}{2\sigma^2}
	\right)
}$$

First condition: $f(0, 0, 0) = 1000000$

$$\implies A = 10^6$$

Second condition: $f(1000, 0, 0) = 10000$

$$\implies 10000 = 10^6 e^{
	-\left(
		\frac{10^6}{2\sigma^2}
	\right)
}$$

$$\implies -\frac{10^6}{2\sigma^2} = 
\ln\left(
	\frac{10000}{10^6}
\right)$$

$$\implies-\frac{10^6}{2\sigma^2} = -4.6052$$

$$\implies \frac{1}{2\sigma^2} = 4.6052 \times 10^{-6}$$

$$\implies 2\sigma^2 = 217147.241$$

$$\implies \sigma = 329.5051$$

$$\therefore \underline{
	f(x, y, z) = 10^6 e^{
		-\left(
			\frac{ x^2 }{ 217147.241 } +
			\frac{ y^2 }{ 217147.241 } +
			\frac{ z^2 }{ 217147.241 }
		\right)
	}
}_\#$$

- <font color = "#3a86ff">Describe the properties of your equation, why you choose it, and how you tune it to have the correct values.</font>

We figured that Gaussian function may fit our usage because it has a bump in the middle, which is similar to the temperature field of nuclear explosion.

We simply use the two constraint given to get the right function.

### 2. Finding the level surface:

- <font color = "#3a86ff">Using your equation, find the radius $R_{15000}$ where $T = 15,000 \text K$</font>

$$
f(x, y, z) = 10^6 e^{
	-\left(
		\frac{ x^2 }{ 217147.241 } +
		\frac{ y^2 }{ 217147.241 } +
		\frac{ z^2 }{ 217147.241 }
	\right)
}$$

$$\implies f(r) = 10^6 e^{
	-\left(
		\frac{ r^2 }{ 217147.241 }
	\right)
}$$

$$\implies 15000 = 10^6 e^{
	-\left(
		\frac{ R_{15000}^2 }{ 217147.241 }
	\right)
}
$$

$$\implies \frac{15 \times 10^3}{10^6} = 
e^{-\left(
	\frac{R_{15000}^2}{217174.241}
\right)}$$

$$\implies \ln\left( 
	\frac{15}{10^3}
\right) = 
-\frac{R_{15000}^2}{217174.241}$$

$$\implies R_{15000} = \sqrt{-217174.241 \times \ln\left( \frac{15}{10^3} \right)}$$

$$\implies\underline{
	R_{15000} = 955 \text m
}_\#$$

- <font color = "#3a86ff">Plot the level surface on a graph.</font>

![[工程數學(二) Project 2 level surface.png]]

### 3. Surface normal via tangents of curves

- <font color = "#3a86ff">Write an equation that describes a circle (i.e. a closed-path circular curve) which is tangent to the $R_{15000}$ level surface along its entire length. The circle may have any orientation. (See Circle 1 in Figure 4).</font>

We have a sphere

$$x^2 + y^2 + z^2 = 955^2$$

For the first circle, we use a plane $x = 0$ to constrain the sphere

$$\implies
\underline{
	\left\{
		\begin{array}{l}
			y^2 + z^2 = 955^2 \\
			x = 0
		\end{array}
	\right.
}_\#$$

- <font color = "#3a86ff">Write an equation that describes a second circle, oriented in a different direction. (See Circle 2 in Figure 4).</font>

For the second circle, we use a plane $y = 0$ to constrain the sphere

$$\implies\underline{
	\left\{
		\begin{array}{l}
			x^2 + z^2 = 955^2 \\
			y = 0
		\end{array}
	\right.
}_\#$$

- <font color = "#3a86ff">Calculate the tangent vectors of Circle 1 and Circle 2 at $\vec r_{intersect}$. Your calculation should be based on differentiating your circles’ equations. Show steps in calculation.</font>

Using the two circles we obtained

$$\left\{
	\begin{array}{}
		z^2 = 955^2 \\
		x = 0 \\
		y = 0 
	\end{array}
\right.$$

Therefore we get two intersections

$$\implies
\left\{
	\begin{array}{}
		x = 0 \\
		y = 0 \\
		z = \pm 955 
	\end{array}
\right.$$

We choose $z = -995$ for our calculation

$$\vec r_{intersect} = [0, 0, -955]$$

For Circle 1

the equation of Circle 1:

$$
\left\{
	\begin{array}{l}
		y^2 + z^2 = 955^2 \\
		x = 0
	\end{array}
\right.
$$

The path of Circle 1 can be represented by trigonometric function and $t$

$$\vec r(t) = [0, 955\cos t, 955\sin t]$$

$$\vec r'(t) = [0, -955\sin t, 955\cos t]$$

When $t = -\frac \pi 2$, $\vec r(t) = \vec r_{intersect}$, therefore the tangent of Circle 1 at intersect point is:

$$\vec t_{C1} = \vec r'\left(-\frac \pi 2\right) = \underline{[0, 955, 0]}_\#$$

Similarly, we can get the tangent vector of Circle 2 as well

$$\left\{
	\begin{array}{l}
		x^2 + z^2 = 955^2 \\
		y = 0
	\end{array}
\right.$$

$$\vec r(t) = [955\cos t, 0, 955\sin t]$$

$$\vec r'(t) = [-955\sin t, 0, 955\cos t]$$

$$\vec r\left(-\frac{\pi}{2}\right) = \vec r_{intersect} = [0, 0, -955]$$

$$\vec r'\left(-\frac \pi 2\right) = \underline{[955, 0, 0]}_\#$$

- <font color = "#3a86ff">Calculate the unit normal vector of the $R_{15000}$ level surface at $\vec r_{intersect}$ using the two tangent vectors. Show step-by-step derivation.</font>

$$\vec u = \frac{\vec t_{C1} \times \vec t_{C2}}{\vert \vec t_{C1} \vert \cdot \vert \vec t_{C2} \vert}$$

$$ = \frac{ [0, 955, 0] \times [955, 0, 0] }{ 955\cdot 955 }$$

$$ = \underline{[0, 0, -1]}_\#$$

- <font color = "#3a86ff">Plot the following on a graph: The level surface, Circles 1 and 2, the intersection point, the two tangent vectors, and the unit normal vector.</font>

![[project 2 intersection point.png]]

- red axis: $x$ axis
- green axis: $y$ axis
- blue axis: $z$ axis

### 4. Surface normal via gradient:

- <font color = "#3a86ff">Calculate the gradient of your temperature-field equation.</font>

$$
f(x, y, z) = 10^6 e^{
	-\left(
		\frac{ x^2 }{ 217147.241 } +
		\frac{ y^2 }{ 217147.241 } +
		\frac{ z^2 }{ 217147.241 }
	\right)
}
$$

$$grad\,(f) = \nabla f$$

$$
= \frac{ \partial f }{ \partial x } \hat i + \frac{ \partial f }{ \partial y } \hat j + 
\frac{ \partial f }{ \partial z } \hat k
$$

$$ = 10^6 e^{
-\left(
	\frac{ x^2 }{ 217147.241 } +
	\frac{ y^2 }{ 217147.241 } +
	\frac{ z^2 }{ 217147.241 }
\right)} \cdot 
(-\frac{2x}{217147.241} - \frac{2y}{217147.241} - \frac{2z}{217147.241})$$

$$ = \underline{10^6 e^{
-\left(
	\frac{ x^2 }{ 217147.241 } +
	\frac{ y^2 }{ 217147.241 } +
	\frac{ z^2 }{ 217147.241 }
\right)} \cdot 
(-\frac{x}{108573.6205}\hat i - \frac{y}{108573.6205}\hat j - \frac{z}{108573.6205}\hat k)}_\#$$

- <font color = "#3a86ff">Find the value of the gradient field at $\vec r_{intersect}$.</font>

$$\vec r_{intersect} = [0, 0, -955]$$

$$grad \,(f) = \nabla f = 10^6 e^{-\frac{955^2}{217147.241}}\cdot (-\frac{-955}{108573.6205})\hat k$$

$$ = \underline{131.8952\hat k}_\#$$

- <font color = "#3a86ff">Normalize to get unit normal vector.</font>

$$\frac{grad\, (f)}{\vert grad\, (f) \vert} = 1\hat k = \underline{[0, 0, 1]}_\#$$

### 5. Conclusion:

- <font color = "#3a86ff">Plot the normal vectors found using (i) tangents of circles and (ii) gradient on the same graph.</font>

![[project 2 plot two vectors on same graph.png]]

![[project 2 plot two vectors on same graph close-up.png]]

- $\vec {BE}$: normal vector found using tangent of circles
- $\vec {BF}$: normal vector found using gradient

<br>

- <font color = "#3a86ff">Comment on whether they are the same.</font>

Using the tangent of circles, we get the normal:

$$\hat n_{tangent} = [0, 0, -1]$$

Using the gradient, we get the normal:

$$\hat n_{gradient} = [0, 0, 1]$$

Although the direction of the two unit vector are inverted, they are the same because they represent the same normal axis.

---

## Reference

[Two-dimensional Gaussian function - wikipedia](https://en.wikipedia.org/wiki/Gaussian_function#Two-dimensional_Gaussian_function)