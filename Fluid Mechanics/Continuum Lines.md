標籤: #fluid-mechanics 

---

[TOC]

---

The field representation is given by $\rho(x, y, z, t)$.

There are four lines that can represent the fluid flow:

- Timelines: lines formed by adjacent fluid particles at a given constant
- Pathlines: the actual path travelled by an individual fluid particle over some time interval.
- Streaklines: lines joining different particles passing through a point
- Streamlines: lines that at a given instant are tangent to the direction of flow at every point in the flow field.

When the fluid is in [[Fluid Mechanics Basics#Steady Flow|steady flow]], pathlines, streaklines, and streamlines are identical.

## Calculate Pathlines

To demonstrate the calculatinos, we use a velocity field $\vec V$ as an example:

$$\vec V = Ax\hat i - Ay\hat j$$

To calculate pathlines from [[Velocity Field]], we need to know that pathlines are the path travelled by a particle. So we use velocity and position relationship:

$$\left\{
\begin{array}{}
	u_p & = & \frac{dx}{dt} & = & Ax \\
	v_p & = & \frac{dy}{dt} & = & -Ay
\end{array}
\right.$$

And solve the above [[Differential Equation]]s for $x$ and $y$, we get:

$$\left\{
	\begin{array}{}
		x & = & x_0e^{At} \\
		y & = & y_0e^{-At}
	\end{array}
\right.$$

This is the pathline equation.

## Calculate Streamlines

To demonstrate the calculations, we use a velocity field $\vec V$ as an example:

$$\vec V = Ax\hat i - Ay \hat j$$

To calculate streamlines from [[Velocity Field]], we need to know that streamlines are lines drawn in the flow field that are tangent to the direction of flow. Therefore the direction $dy / dx$ equals to velocity flow:

$$
\left.
\frac{dy}{dx}
\right)_{\text{streamline}} = \frac v u = \frac{-Ay}{Ax} = \frac{-y}{x}$$

We obtain the [[Differential Equation]]:

$$\frac{dy}{dx} = \frac{-y}{x}$$

$$\implies \int\frac{dy}{y} = -\int\frac{dx}{x}$$

$$\implies \ln y = -\ln x + c_1$$

$$\implies \underline{xy = c}_\#$$

You may substitude $c$ for a value, and the above equation represent a streamline.

To find a streamline passing through a point, we substitude the point's coordinate $x$, $y$ and solve for $c$. For example, the streamline through point $(2, 8)$ will have $c$ equals:

$$c = 2 \cdot 8 = 16$$

The streamline passing through the point will be:

$$\underline{xy = 16}_\#$$

---

參考資料:



---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.