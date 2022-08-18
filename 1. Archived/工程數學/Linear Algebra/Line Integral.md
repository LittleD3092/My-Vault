標籤: #工程數學 

---

有兩個 application

1. Scalar Value: 沿著路線採茶，不同地方茶葉有密度的不同，最後採了多少茶葉？
2. [[Vector]]: 發射火箭，有了火箭的路線與 [[Vector]] [[Field]] ，引擎[[Work|作功]]多少？

# Mathematical Expression

比較 Classical 1D definite integral:

$$F = \int_a^b f(t)dt$$

Line Integral 有更高的 dimension ，積分相對複雜，如下圖

![[line integral schematic diagram.png|400]]

## [[Curve]]

先從 [[Curve]] 開始定義

$$C = \vec r (t)$$

$$ = 
\left[	
	\begin{array}{}
		x(t) \\
		y(t)
	\end{array}
\right]$$

$$ = x(t) \hat i + y(t) \hat j$$

### Definition

- If $\vec r(a) = \vec r(b) \rightarrow$ closed path
- If $\vec r(a) \neq \vec r(b) \rightarrow$ open path
- $C$ is a smooth [[Curve]] if
$$\frac {d\vec r}{ dt } = 
\vec r' = \text{ tangent }$$
is unique at all points, and 
$$\vec r' \text{ is continuous and non-zero }$$

## Mathematical Expression

$$\left\{
	\begin{array}{}
		F(\vec x) & : & \text{ a function carrying scalar/vector values } \\
		C & 
		: & 
		\text{ a path in } 
		\vec x 
		\text{ , described by } 
		\vec r (t) = 
		\left[
			\begin{array}{}
				x(t) \\
				y(t) \\
				z(t)
			\end{array}
		\right]
	\end{array}
\right.$$

$$\implies \int_C \vec F(\vec r) \cdot 
d\vec r$$

$$ = \int_C
\left[
	\begin{array}{}
		F_1 \\
		F_2 \\
		F_3
	\end{array}
\right]\cdot
\left[
	\begin{array}{}
		dx \\
		dy \\
		dz
	\end{array}
\right]
$$

$$ = \int_C F_1 dx + F_2 dy + F_3 dz$$

$$ = 
\int_{ t = a }^{ t = b }
\left(
	F_1 \frac{ dx }{ dt } + 
	F_2 \frac{ dy }{ dt } + 
	F_3 \frac{ dz }{ dt }
\right) dt$$

$$ = 
\int_a^b \vec F(\vec r(t)) \cdot
\vec r'(t) \cdot dt$$

### Comparison

| Classical 1D definite integral | [[Vector]] [[Field]] Line Integral                                                                      | Scalar [[Field]] Line Integral                                                                                                                       |
| ------------------------------ | ----------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| $$R = \int_a^b f(t)dt$$        | $$R = \int_C \vec F(\vec r)\cdot d\vec r$$ $$ = \int_a^b \vec F(\vec r(t))\cdot \vec r'(t) dt$$ | $$r = \int_Cf(\vec r) \underbrace{ ds }_{ \text{ arc length } }$$ $$ = \int_a^b f(\vec r (t)) \cdot \left\vert \vec r'(t) \right\vert \cdot dt$$ | 

## Example

### Vector Field Line Integral

> Find the value of the line integral when $${\bf F}({\bf r}) = [-y, -xy] = -y\,{\bf i} - xy\,{\bf j}$$ and $C$ is the circular arc in figure from $A$ to $B$
> ![[example of vector line integral.png|300]]

We may represent $C$ by 

$${\bf r}(t) = [\cos t, \sin t] = \cos t \,{\bf i} + \sin t\,{\bf j}$$

where $0 \leq t \leq \pi / 2$

Then $x(t) = \cos t, y(t) = \sin t$, and 

$${\bf F}({\bf r}(t)) = -y(t){\bf i} - x(t)y(t){\bf j}$$

$$ = [-\sin t, -\cos t\sin t]$$

$$ = -\sin t {\bf i} - \cos t \sin t {\bf j}$$
.
$${\bf r}'(t) = [-\sin t, \cos t] = -\sin t {\bf i} + \cos t {\bf j}$$
.
$$\int_C {\bf F}({\bf r}) \cdot d{\bf r} = \int_a^b \vec F(\vec r(t))\cdot \vec r'(t) dt$$

$$ = \int_0^{ \pi / 2 }[-\sin t, -\cos t \sin t] \cdot [-\sin t, \cos t] dt$$

$$ = \int_0^{ \pi / 2 }(\sin^2 t - \cos^2 t \sin t)dt$$

$$ = \int_0^{\pi / 2}\frac 1 2 (1 - \cos 2t)dt - \int_1^0 u^2 (-du)$$

$$ = \frac \pi 4 - 0 - \frac 1 3$$

$$\approx 0.4521$$

# Physics in Line Integral

## [[Work]]

$$W = \int_C \vec F \cdot d\vec r$$

$$ = \int_a^b \vec F(\vec r(t)) \cdot 
\vec r' dt$$

$$ = \int_a^b \vec F(\vec r(t))\cdot 
\vec v dt$$

$$ = \int_a^b m\vec v'(t) \cdot \vec v(t)dt$$

$$ = \int_a^b m\left( 
	\frac{ \vec v\cdot \vec v }{ 2 }
\right)'dt$$

$$ = \left. 
	\frac m 2 \vert \vec v \vert^2
\right\vert_{ t = a }^b$$

## [[Impulse]]

$$R = \int_a^b \vec F(\vec r(t))dt$$

# Path dependence and independence

在一般情況下

$$\int_{ C_1 } F(\vec r_1 (t))dt \neq 
\int_{ C_2 } F(\vec r_2(t))dt$$

路線不一樣時，通常 Line Integral 也會不一樣。因為 Line Integral 會受到 path 影響，所以稱為 path dependence

但是也有特定情況下會發生 path independence ，不同的 path 做 Line Integral 的結果一樣

$$\int_{ C_1 } Fdt = 
\int_{ C_2 } Fdt ,\qquad 
\text{ for any } C_1, C_2 
\text{ with same starting \& ending points}$$

---

在以下情況下會發生 path independence 的情況

Let $f(\vec x)$ be a scalar-field, then $grad(f)$ describes the slope of $\vec f$ in all directions

$$\text{ If: } \vec F = grad(f) = 
\frac { \partial f }{ \partial x } + 
\frac{ \partial f }{ \partial y } + 
\frac{ \partial f }{ \partial z }$$

$$\text{ then } \int_C \vec F dt 
\text{ is path-independent }$$

並且我們稱 scalar field $f$ 為 $\vec F$ ==potential==

## Proof

$$\int_C\vec F \cdot d \vec r = 
\int_C\left(
	F_1dx + F_2dx + F_3dx
\right)$$

$$ = \int_C 
\frac{ \partial f }{ \partial x }dx + 
\frac{ \partial f }{ \partial y }dy + 
\frac{ \partial f }{ \partial z }dz$$

$$ = \int_a^b
\left(
	\frac{ \partial f }{ \partial x }
	\frac{ dx }{ dt } + 
	\frac{ \partial f }{ \partial y }
	\frac{ dy }{ dt } + 
	\frac{ \partial f }{ \partial z }
	\frac{ dz }{ dt }
\right)dt$$

$$ = \int_a^b \frac{ df }{ dt } dt$$

$$ = \left.
	f[x(t), y(t), z(t)]
\right\vert_{ t = a }^b$$

$$ = f(x(b), y(b), z(b)) - 
f(x(a), y(a), z(a))$$

$$ = f(B) - f(A)$$

## Property

If $\vec F = grad(f)$:

1. [[#Path-independent]]
2. $curl \vec F = 0$

### Path-independent

$$\int_{ C_1 }
\vec F(\vec r(t)) \cdot \vec r'dt + 
\int_{ C_2 }
\vec F(\vec r(t)) \cdot \vec r'dt = 0$$

$$
\begin{array}{}
	\text { if } & C_1 & \text{ goes from } & 
	a\rightarrow b \\
	& C_2 & \text{ goes from } & b\rightarrow a
\end{array}
$$

---

$$\implies \oint_C \vec F \cdot d\vec r = 0$$

$C$: 封閉曲線

### $curl\vec F = 0$ proof

$$\vec F = 
\left[
	\begin{array}{}
		\partial f / \partial x \\
		\partial f / \partial y \\
		\partial f / \partial z
	\end{array}
\right] = 
\left[
	\begin{array}{}
		F_1 \\
		F_2 \\
		F_3
	\end{array}
\right]$$

$$curl\vec F = \det
\left(
	\begin{array}{}
		\hat i & \hat j & \hat z \\
		\partial / \partial x & 
		\partial / \partial y & 
		\partial / \partial z \\
		F_1 & F_2 & F_3
	\end{array}
\right)$$

$$ = 
\left(
	\frac{ \partial F_3 }{ \partial y } - 
	\frac{ \partial F_2 }{ \partial z }
\right)\hat i +
\left(
	\frac{ \partial F_1 }{ \partial z } - 
	\frac{ \partial F_3 }{ \partial x }
\right)\hat j +
\left(
	\frac{ \partial F_2 }{ \partial x } - 
	\frac{ \partial F_1 }{ \partial y }
\right)\hat k$$

$$ = 
\left(
	\frac{ \partial^2 f }
	{ \partial y \partial z } - 
	\frac{ \partial^2 f }
	{ \partial y \partial z }
\right)\hat i +
\left(
	\frac{ \partial^2 f }
	{ \partial x \partial z } - 
	\frac{ \partial^2 f }
	{ \partial x \partial z }
\right)\hat j +
\left(
	\frac{ \partial^2 f }
	{ \partial x \partial y } - 
	\frac{ \partial^2 f }
	{ \partial x \partial y }
\right)\hat k$$

$$ = 0$$

## Exactness

當 scalar field $f$ 的 gradient $= \vec F$ ，我們會說 $\vec F d\vec r$ 為 path independent

.

反過來，我們有一個 $\vec F$ ，並且將他對 $\vec r$ 內積

$$\vec F \cdot d \vec r = F_1 dx + F_2 dy + F_3 dz$$

如果我們可以找到一個 scalar field $f$ ，並且 $grad (f) = \vec F$ ，我們會稱 $\vec F$ 為 ==exact==

### Motivation

時常我們需要判斷 $\vec F$ 是否為 path independent ，因此我們需要一個指標來判斷是不是。這個指標就稱為 Exactness

### 如何判斷

我們可以用 $curl \vec F = 0$ 的性質來判斷

$$curl \vec F = \nabla \times \vec F$$

$$ = \left\vert
	\begin{array}{}
		\hat i & \hat j & \hat k \\
		\frac{ \partial }{ \partial x } & \frac{ \partial }{ \partial y } & \frac{ \partial }{ \partial z } \\
		F_x & F_y & F_z
	\end{array}
\right\vert$$

$$ = 
\left(
	\frac{ \partial F_z }{ \partial y } - 
	\frac{ \partial F_y }{ \partial z }
\right)\hat i + 
\left(
	\frac{ \partial F_x }{ \partial z } - 
	\frac{ \partial F_z }{ \partial x }
\right)\hat j + 
\left(
	\frac{ \partial F_y }{ \partial x } - 
	\frac{ \partial F_x }{ \partial y }
\right)\hat k$$

如果 $curl \vec F$ 要等於 $0$

$$
\underline{
	\left\{
		\begin{array}{}
			\frac{ \partial F_z }{ \partial y } & = & \frac{ \partial F_y }{ \partial z } \\
			\frac{ \partial F_x }{ \partial z } & = & \frac{ \partial F_z }{ \partial x } \\
			\frac{ \partial F_y }{ \partial x } & = & \frac{ \partial F_x }{ \partial y }
		\end{array}
	\right.
}_{ \# }
$$

以上就是判斷條件

### 如何求解 $f$

$$grad(f) = \vec F$$

$$\frac{ \partial f }{ \partial x } \hat i + \frac{ \partial f }{ \partial y } \hat j + 
\frac{ \partial f }{ \partial z } \hat k = F_x \hat i + 
F_y \hat j + 
F_z \hat k$$

因此我們可以使用以下這三條公式

$$f = \int F_x dx$$

$$f = \int F_y dy$$

$$f = \int F_z dz$$

並進行比較得出 $f$

#### Example

> show that the differential form under the integral sign of
> $$I = \int_C [2xyz^2 dx + (x^2z^2 + z \cos yz)dy + (2x^2yz + y \cos yz)dz]$$
> is exact, so that we have independence of path in any domain, and find the value of $I$ from $A: (0, 0, 1)$ to $B: (1, \pi / 4, 2)$

step 1. verify exactness

$$
\begin{array}{}
	F_x & = & 2xyz^2 \\
	F_y & = & x^2z^2 & + & z\cos yz \\
	F_z & = & 2x^2yz & + & y\cos yz
\end{array}
$$

use $curl\vec F = 0$, we found out that

$$
\begin{array}{}
	\frac{ \partial F_z }{ \partial y } & = & \frac{ \partial F_y }{ \partial z } & = & 2x^2z & + & \cos yz \\
	\frac{ \partial F_x }{ \partial z } & = & \frac{ \partial F_z }{ \partial x } & = & 4xyz \\
	\frac{ \partial F_y }{ \partial x } & = & \frac{ \partial F_x }{ \partial y } & = & 2xz^2
\end{array}
$$

therefore it is exact

step 2. find $f$

$$
\begin{array}{}
	f & = & \int2xyz dx & = & x^2yz^2 &&& + & a(y, z) \\
	f & = & \int (x^2z^2 + z\cos yz)dy & = & x^2yz^2 & + & \sin yz & + & b(x, z) \\
	f & = & \int (2x^2yz + y\cos yz)dz & = & x^2yz^2 & + & \sin yz & + & c(x, z) \\
\end{array}
$$

through comparison, we get

$$f = x^2 y z^2 + \sin yz$$

step 3. find value $I$

$$f(B) - f(A) = 1 \cdot \frac \pi 4 \cdot 4 + \sin \frac \pi 2 - 0 = \underline{ \pi + 1 }_\#$$

---

參考資料:

工程數學上課

---

link:

$grad(f)$: [[Field#Scalar Field]]
$curl(f)$: [[Field#Curl]]

[[Table of Integration]]