標籤: #工程數學 

---

integrating across a 3D plane

$$\underset T \iiint f(x, y, z)dxdydz$$

$$ = \underset T \iiint f(x, y, z)dV$$

Try to calculate 3D integral using just 2D integration

$$div\vec F = \frac{ \partial F_1 }{ \partial x } +
\frac{ \partial F_2 }{ \partial y } +
\frac{ \partial F_3 }{ \partial z }$$

$$\underset T \iiint div(\vec F)dV = \underset T \iiint 
\left(
	\frac{ \partial F_1 }{ \partial x } + 
	\frac{ \partial F_2 }{ \partial y } +
	\frac{ \partial F_3 }{ \partial z }
\right)dxdydz$$

$$\underline{ \underset T \iiint div(\vec F)dV = \underset S \iint \vec F \cdot \hat n dA }_\#$$

# Physics Application

Deriving the [[Heat]] Transfer Equation through Divergence Theorem

1. [[Heat]] transfer model

$$\underbrace{\vec q}_{ \text{ heat flux }[\text{W}/\text{m}^2] } = -\underbrace{ k }_{ \text{ conductivity }[\text{W}/\text{m}\cdot\text{K}] }grad \underbrace{ T }_{[\frac{ \text{K} }{ \text{m} }]}$$

$$ = -k\left(
	\frac{ \partial T }{ \partial x }\hat i +
	\frac{ \partial T }{ \partial y }\hat j +
	\frac{ \partial T }{ \partial z }\hat k
\right)$$

[[Heat]] leaving through $S$:

$$\underset S \iint \vec q \cdot \hat n dA \qquad, \qquad \hat n = \text{ outwards }$$

2. Divergence Theorem

$$\underset S \iint \vec q\cdot \hat n dA = 
\underset V \iiint div \vec q \,dxdydz$$

$$ = -k \underset V \iiint div(grad(T))dxdydz$$

$$ = -k\underset V \iiint \nabla^2 T dxdydz \quad [\text{W}] = [\text{J}/\text{s}]$$

3. [[Heat]] in System

$$H\;[\text{J}] = \underset V \iiint \underbrace{ \sigma }_{ \text{ specific heat }[\text{J}/\text{kg}\cdot \text{K}] }\underbrace{ \rho }_{ \text{ density }[\text{kg}/\text{m}^3] }\underbrace{ T }_{ [\text{K}] }dxdydz$$

$$-\frac{ \partial H }{ \partial t } = -\underset V \iiint \sigma \rho \frac{ \partial T }{ \partial t }dxdydz$$

$$\implies \underset V \iiint (\sigma \rho \frac{ \partial T }{ \partial t } - k \nabla^2 T)dxdydz = 0$$

$$\implies \sigma \rho \frac{ \partial T }{ \partial t } = k \nabla^2T$$

$$\implies \underline{ \frac{ \partial T }{ \partial t } = \frac{ k }{ \sigma \rho }\nabla^2T \equiv c^2 \nabla^2 T }_{ \#\text{heat equation } }$$

---

參考資料:

工程數學上課

---

link:

