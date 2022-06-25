標籤: #工程數學 

---

# Derivatives

- [[#Scalar Field]]
	- Gradient
- [[#Vector Field]]
	- Divergence
	- Curl

## Scalar Field

### Gradient

假設有一個 Scalar Field $f(x, y, z)$

$$
\underbrace{grad}_{ \text{ gradient } }(f) = \nabla f = 
\left[
	\begin{array}{}
		df / dx \\
		df / dy \\
		df / dz
	\end{array}
\right]
$$

$$
= \frac{ \partial f }{ \partial x } \hat i + \frac{ \partial f }{ \partial y } \hat j + 
\frac{ \partial f }{ \partial z } \hat k
$$

$$\nabla = \frac{ \partial }{ \partial x } \hat i + 
\frac{ \partial }{ \partial y } \hat j + 
\frac{ \partial }{ \partial z } \hat k$$

Gradient turns a scalar field into a [[Vector]] field.

### Directional Derivative

$$D_af = \frac 1 {\vert\vec a \vert}\vec a \cdot \nabla f \quad \leftarrow \text{ the rate of change in the derection of }\vec a$$

### [[Laplacian]]

![[Laplacian]]

## [[Vector]] Field

[[Vector]] Field 的微分包含兩種

- [[#Divergence]]: 用來看流進與流出的量的差
- [[#Curl]]: 用來看漩渦的方向

### Divergence

Let the [[Vector]] field be: $\vec v(x, y, z)$

$$div\vec v = \nabla \cdot \vec v = 
\left[
	\frac{ \partial }{ \partial x } \hat i + 
	\frac{ \partial }{ \partial y } \hat j + 
	\frac{ \partial }{ \partial z } \hat k
\right]\cdot
[v_1 \hat i + 
v_2 \hat j + 
v_3 \hat k]$$

$$ = \frac{ \partial v_1 }{ \partial x } + 
\frac{ \partial v_2 }{ \partial y } + 
\frac{ \partial v_3 }{ \partial z }$$

> [[#Scalar Field|Gradient]] 和 [[#Divergence]] 的比較
> - $div$: $\nabla \cdot \vec v$: $\text{ vector } \rightarrow \text{ scalar }$
> - $grad$: $\nabla f$: $\text{ scalar } \rightarrow \text{ vector }$

#### For [[Control Volume]] Analysis

- left-right

$$\dot m_{ CV, x } = \rho
(v_x(x_1) - v_x(x_1 + \Delta x))\Delta y\Delta z$$

- Up-down:

$$\dot m_{ CV, y } = \rho
(v_y(y_1) - v_y(y_1 + \Delta y))\Delta x\Delta z$$

- Front-back:

$$\dot m_{ CV, z } = \rho
(v_z(z_1) - v_z(z_1 + \Delta z))\Delta x\Delta y$$

$$\implies \frac{ \Delta m_{ CV } }{ \Delta t } = 
\dot m_{ CV } = 
\dot m_{ CV, x } + 
\dot m_{ CV, y } + 
\dot m_{ CV, z }$$

$$\implies \dot m_{ CV } = 
\rho\left\{
	\left(
		v_x - 
		\left[
			v_x + 
			\frac{\Delta v_x}{ \Delta x }
		\right]
	\right)\Delta y\Delta z + 
	\left(
		v_y - 
		\left[
			v_y + 
			\frac{ \Delta v_y }{ \Delta y } \Delta y
		\right]
	\right)\Delta x \Delta z + 
	\left(
		v_z - 
		\left[
			v_z + 
			\frac{ \Delta v_z }{ \Delta z } \Delta z
		\right]
	\right)\Delta x \Delta y
\right\}$$

$$ = -\rho \left[
	\frac{ \Delta v_x }{ \Delta x } + 
	\frac{ \Delta v_y }{ \Delta y } + 
	\frac{ \Delta v_z }{ \Delta z }
\right]\underbrace{\Delta V}_{ \text{ Volume } }$$

$$\implies \frac{ \dot m_{ CV } }{ \Delta V } = 
\frac{ \Delta m_{ CV } }{ \Delta t \Delta V } = 
\frac{ \Delta \rho }{ \Delta t } = -\rho
\left[
	\frac{ \Delta v_x }{ \Delta x } + 
	\frac{ \Delta v_y }{ \Delta y } + 
	\frac{ \Delta v_z }{ \Delta z }
\right]$$

$$\overset{ \Delta x, 
\Delta y, 
\Delta z, 
\Delta t \rightarrow 0}{ \implies }
\frac{ \partial \rho }{ \partial t } = 
-\rho\left(
	\frac{ \partial v_x }{ \partial x } + 
	\frac{ \partial v_y }{ \partial y } + 
	\frac{ \partial v_z }{ \partial z }
\right) = 
-\rho \,div(\vec v)
$$

### Curl

$$curl \,\vec v = \nabla \times \vec v$$

$$ = \left\vert
	\begin{array}{}
		\hat i & \hat j & \hat k \\
		\frac{ \partial }{ \partial x } & \frac{ \partial }{ \partial y } & \frac{ \partial }{ \partial z } \\
		v_x & v_y & v_z
	\end{array}
\right\vert$$

$$ = 
\left(
	\frac{ \partial v_z }{ \partial y } - 
	\frac{ \partial v_y }{ \partial z }
\right)\hat i + 
\left(
	\frac{ \partial v_x }{ \partial z } - 
	\frac{ \partial v_z }{ \partial x }
\right)\hat j + 
\left(
	\frac{ \partial v_y }{ \partial x } - 
	\frac{ \partial v_x }{ \partial y }
\right)\hat k$$

可以得到旋轉沿著的向量

### Properties

- $curl\, (grad \, f) = 0$
- $div \, (curl \, \vec v) = 0$
- If $curl \, \vec v = 0 \rightarrow$ "irrotational field"
- $curl\, \vec v$ and $div\, \vec v$ do not care about your coordinate system's origin

### Example

> $$\vec v(\vec r) = 
> \left[
>	\begin{array}{}
>		-y \\
>		xy \\
>		0
>	\end{array}
> \right]$$

$$curl\, \vec v = \nabla \times \vec v$$

$$ = \left(
	\frac{ \partial v_z }{ \partial y } - 
	\frac{ \partial v_y }{ \partial z }, 
	\frac{ \partial v_x }{ \partial z } - 
	\frac{ \partial v_z }{ \partial x },
	\frac{ \partial v_y }{ \partial x } - 
	\frac{ \partial v_x }{ \partial y }
\right)$$

$$ = 
\left[
	\begin{array}{}
		0 \\
		0 \\
		y + 1
	\end{array}
\right]$$

$$div \, \vec v = \nabla \cdot \vec v$$

$$ = \frac{ \partial v_x }{ \partial x } + 
\frac{ \partial v_y }{ \partial y } + 
\frac{ \partial v_z }{ \partial z }$$

$$ = 0 + x + 0 = x$$

---

參考資料:

工程數學上課

---

link:

[[Cross Product]]
[[Table of Differentiation]]