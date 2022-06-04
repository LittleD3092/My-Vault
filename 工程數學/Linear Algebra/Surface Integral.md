標籤: #工程數學 

---

2D Integral 主要是關於
1. 2D region in 2D space
2. 2D [[Surface]] in 3D space

# 面積求法

Evaluating integral across $R$:

$$\underset{ R }{ \int\int } fdydx = 
\int_a^b
\left[
	\int_{ g(x) }^{ h(x) }
	f(x, y) dy
\right] dx$$

![[2D integral evaluate area R.png|400]]

# Green's Theorem

將 [[Line Integral]] 與 2D Integral 結合

![[green's theorem.png]]

當我們嘗試將 vector field 與路徑積分，我們會發現

tank 1:

$$\oint_C \vec v \cdot d\vec r = 4vL$$

tank 2:

$$\oint_C \vec v \cdot d \vec r = 4vL$$

於是我們得到一個結論，不管一個 tank 分成幾個小漩渦，積分起來都一樣

Evaluate integral across $R$:

$$\implies 
\underbrace { 
	\oint_C \vec F(\vec r) \cdot d\vec r 
}_{ \text{ 1D integral } }
$$

$$ = \oint_C(F_1 dx + F_2 dy)$$

$$ = \underset{ R }{ \int\int }(\underbrace{ \nabla \times \vec F }_{ \text{ curl } }) \cdot \hat k dx dy
$$

$$ = \underbrace{ 
	\underset{ R }{ \int\int } \left(
		\frac{ \partial F_2 }{ \partial x } - 
		\frac{ \partial F_1 }{ \partial y }
	\right) dA
}_{ \text{ 2D integral } }$$

## Prove

### 第一式 = 第二式

> $$\underbrace { 
>	\oint_C \vec F(\vec r) \cdot d\vec r 
> }_{ \text{ 1D integral } } = \oint_C(F_1 dx + F_2 dy)$$

因為
$$ = \oint_C [F_1, F_2] \cdot [dx, dy]$$

### 第三式 = 第四式

> $$\underset{ R }{ \int\int }(\underbrace{ \nabla \times \vec F }_{ \text{ curl } }) \cdot \hat k dx dy = \underbrace{ \underset{ R }{ \int\int } \left(\frac{ \partial F_2 }{ \partial x } - \frac{ \partial F_1 }{ \partial y }\right) dA}_{ \text{ 2D integral } }$$

因為
$$curl(\vec F) = \nabla \times \vec F$$
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
$$ = \left(
	\frac{ \partial F_2 }{ \partial x } - 
	\frac{ \partial F_1 }{ \partial y }
\right)\hat k$$

### 第二式 = 第四式

> $$\oint_C(F_1 dx + F_2 dy) = \underbrace{ 
> 	\underset{ R }{ \int\int } \left(
> 		\frac{ \partial F_2 }{ \partial x } - 
> 		\frac{ \partial F_1 }{ \partial y }
> 	\right) dA
> }_{ \text{ 2D integral } }$$

先從其中一項開始分析

$$\iint_R\frac{\partial F_1}{ \partial y }
dxdy = 
\int_a^b\left[
	\int_{u(x)}^{v(x)}\frac{ \partial F_1 }{ \partial y }dy
\right]dx$$

$$ = \int_a^b\left[
	\left.
		F_1(x, y)
	\right\vert_{y = u(x)}^{v(x)}
\right]dx$$

$$ = \int_a^b
\left[
	F_1(x, v(x)) - F_1(x, u(x))
\right]dx$$

$$ = \int_a^bF_1[x, v(x)]dx - 
\int_a^b F_1[x, u(x)]dx$$

$$ = -\int_b^a F_1[x, v(x)]dx - 
\int_a^bF_1[x, u(x)]dx$$

$$ = -\int_{C**}F_1(x, y)dx - 
\int_{C*}F_1(x, y)dx$$

$$ = -\oint_C F_1(x, y)dx$$

similarly

$$\underset R \iint
\frac{ \partial F_2 }{ \partial x }dxdy = \int_c^d
\left[
	\int_{ p(y) }^{ q(y) } \
	\frac{\partial F_2}{ \partial x }dx
\right]dy$$

$$ = \int_c^dF_2(q(y), y)dy + \int_d^c F_2(p(y), y)dy$$

$$ = \oint_C F_2(x, y)dy$$

therefore

$$\underset R \iint
\left(
	\frac{ \partial F_2 }{ \partial x } - 
	\frac{ \partial F_1 }{ \partial y }
\right)dxdy$$

$$ = \oint_C F_2(x, y)dy + \oint_C F_1(x, y)dx$$

$$ = \oint_C(F_1dx + F_2dy)$$

## Application

### Area as a Line Integral Over the Boundary

$$\underline{A = \frac 1 2 \oint_C(xdy - ydx)}_{\#}$$

### Area in Polar Coordinates

$$x = r\cos \theta,\quad y = r\sin\theta$$
.
$$dx = \cos\theta dr - r\sin\theta d\theta$$
$$dy = \sin\theta dr + r\cos \theta d\theta$$

代入 [[#Area of a Plane Region as a Line Integral Over the Boundary]]

$$\underline{A = \frac 1 2 \oint_C r^2 d\theta}_{\#}$$

### Integral of the Normal Derivative

we set

$$F_1 = -\partial w / \partial y$$

$$F_2 = \partial w / \partial x$$

so the green's theorem's left side

$$\underset R \iint
\left(
	\frac{ \partial F_2 }{ \partial x } - 
	\frac{ \partial F_1 }{ \partial y }
\right)dxdy = \oint_C(F_1dx + F_2dy)$$

$$\implies \underset R \iint
\left(
	\frac{ \partial^2 w }{ \partial x^2 } +
	\frac{ \partial^2 w }{ \partial y^2 }
\right)dxdy = \oint_C(F_1dx + F_2dy)$$

$$\implies \underset R \iint
\left(
	\nabla^2 w
\right)dxdy = \oint_C(F_1dx + F_2dy)$$

then the right side

$$\implies \underset R \iint
\left(
	\nabla^2 w
\right)dxdy = \oint_C\left(F_1\frac{dx}{ds} + F_2\frac{dy}{ds}\right)ds$$

$$\implies \underset R \iint
\left(
	\nabla^2 w
\right)dxdy = \oint_C\left(-\frac{\partial w}{\partial y}\frac{dx}{ds} + \frac{ \partial w }{ \partial x }\frac{dy}{ds}\right)ds$$

> $$grad(w) \cdot \vec n $$
> > $$\vec r'(s) = \frac{ d\vec r }{ ds } = [dx / ds, dy / ds]$$
> > $$\vec n \cdot \vec r'(s) = 0$$ 
> > so that $\vec n$ is perpendicular to $\vec r'$
> > $$\vec n = \left[ \frac{ dy }{ ds }, -\frac{ dx }{ ds }\right]$$
> $$ = 
> \left[
>   \frac{ \partial w }{ \partial x }, \frac{ \partial w }{ \partial y }
> \right]\cdot
> \left[ 
>   \frac{ dy }{ ds }, -\frac{ dx }{ ds }
> \right]$$
> $$ = \frac{\partial w}{\partial x}\frac{dy}{ds} - \frac{\partial w}{\partial y}\frac{dx}{ds}$$

$$\implies \underline{\underset R \iint \nabla^2 w dx dy = 
\oint_C \frac{ \partial w }{ \partial n }ds}_{\#}$$

# 2D [[Surface]] in 3D Integral

2D [[Surface]] $S$ within 3D space:

![[surface integral.png|300]]

$$
\vec r(u, v) = 
\left[
	\begin{array}{}
		x(u, v) \\
		y(u, v) \\
		z(u, v)
	\end{array}
\right]
$$

> e.g.
> $(u, v)$ parametric representation of a cylinder in 3D space.

$$\vec r = 
\left[
	\begin{array}{}
		a\cos u \\
		a\sin u \\
		v
	\end{array}
\right]$$

$$\text{ gives a cylinder with radius } a$$

---

cone:

$$\vec r = 
\left[
	\begin{array}{}
		v\cos u \\
		v\sin u \\
		v
	\end{array}
\right]$$

## Flux Through [[Surface]]

### uv-integration

$$Flux = 
\underset{ S }{ \iint } \vec F \cdot 
\hat n dA$$

$$ = \iint \vec F(\vec r(u, v)) \cdot 
\hat n dA$$

> need to write $\hat n$ in terms of $u, v$
> ![[normal of surface.png|200]]
> $$\vec N = \frac{ \partial \vec r }{ \partial u } \times \frac{ \partial \vec r }{ \partial v }$$
> $$dA = \vert \vec N \vert dudv$$
> $$\hat n dA = \hat n \vert \vec N \vert dudv$$
> $$ = \vec N dudv$$

$$\implies \underline{ Flux = \underset R \iint \vec F(\vec r(u, v)) \cdot \vec N dudv }_\#$$

### xyz-integration

$$\vec F = 
\left[
	\begin{array}{}
		F_1 \\
		F_2 \\
		F_3
	\end{array}
\right]$$

$$\vec N = 
\left[
	\begin{array}{}
		N_1 \\
		N_2 \\
		N_3
	\end{array}
\right]$$

$$\hat n = 
\left[
	\begin{array}{}
		\cos\alpha \\
		\cos\beta \\
		\cos\gamma
	\end{array}
\right] = 
\left[
	\begin{array}{}
		\hat n \cdot \hat i \\
		\hat n \cdot \hat j \\
		\hat n \cdot \hat k
	\end{array}
\right]$$

$$Flux = \underset S \iint \vec F \cdot \hat n dA$$

$$ = \underset{ R }{ \iint } 
\vec F(\vec r(u, v))\cdot \vec N dudv$$

$$ = \underset S \iint (
	F_1 \cos \alpha + 
	F_2 \cos \beta +
	F_3 \cos \gamma
)dA$$

$$ = \underset S \iint (
	F_1 dydz + 
	F_2 dxdz + 
	F_3 dxdy
)$$

$$ = 
\underline{
	\pm \underset { R_1 } 
	\iint F_1(f(y, z), y, z)dydz
	\pm \underset { R_2 }
	\iint F_2(x, g(x, z), z)dzdx
	\pm \underset { R_3 } 
	\iint F_3(x, y, h(x, y))dxdy
}_\#$$

上面的 $\pm$ 在於 $\cos\alpha, \cos\beta, \cos\gamma$ 的正負號

### example

![[example of uv integration and xyz integration.png|300]]

- shape:
	- $0 \leq x \leq 4$
	- $0 \leq z \leq 3$
	- $y = x^2$
- [[vector]] [[field]]:
	- $\vec F = \left[ \begin{array}{} 3z^2 \\ 6 \\ 6xz \end{array} \right]$

#### Method 1: uv-integration

Let

$$\begin{array}{}
	x = u \\
	z = v
\end{array}\qquad , \qquad y = u^2$$

Then

$$\vec r = \left[
	\begin{array}{}
		u \\
		u^2 \\
		v
	\end{array}
\right] \qquad , \qquad 
\begin{array}{}
	0 \leq u \leq 2 \\
	0 \leq v \leq 3
\end{array}$$

Normal:

$$\vec N = \vec r_u \times \vec r_v = 
\left[
	\begin{array}{}
		1 \\
		2u \\
		0
	\end{array}
\right] \times
\left[
	\begin{array}{}
		0 \\
		0 \\
		1
	\end{array}
\right] = 
\left[
	\begin{array}{}
		2u \\
		-1 \\
		0
	\end{array}
\right]$$

[[Field]]:

$$\vec F(u, v) = [3v^2, 6, 6uv]$$
.
$$\implies \vec F \cdot \vec N = 6uv^2 - 6$$

$$Flux = \underset R \iint \vec F \cdot \vec N dudv$$

$$ = \int_0^3 \int_0^2(6uv^2 - 6)dudv$$

$$ = 72$$

#### Method 2: xyz-integration

Find the angles between $\vec N$ and $\hat i, \hat j, \hat k \quad (\alpha, \beta, \gamma)$

$$\vec N = \vert \vec N \vert \hat n$$

$$ = \vert \vec N \vert
\left[
	\begin{array}{}
		\cos\alpha \\
		\cos\beta \\
		\cos\gamma
	\end{array}
\right]$$

$$ = \vert \vec N \vert
\left[
	\begin{array}{}
		\hat n \cdot \hat i \\
		\hat n \cdot \hat j \\
		\hat n \cdot \hat k
	\end{array}
\right]$$

$$ = \frac{ \vert \vec N \vert }
{ \vert \vec N \vert }
\left[
	\begin{array}{}
		\vec N \cdot \hat i \\
		\vec N \cdot \hat j \\
		\vec N \cdot \hat k
	\end{array}
\right]$$

$$ = 
\left[
	\begin{array}{}
		2x \\
		-1 \\
		0
	\end{array}
\right]$$

$$
\left\{
	\begin{array}{}
		sign(\cos \alpha) & = & sign(2x) & = & (+) \\
		sign(\cos \beta) & = & sign(-1) & = & (-) \\
		sign(\cos \gamma) & = & sign(0) & = & N/A
	\end{array}
\right.
$$

$$\implies \underset S \iint \vec F \cdot \hat n dA = 
\int_0^3 \int_0^4 F_1 dydz - \int_0^2\int_0^3 F_2dzdx + 0$$

$$ = \int_0^3 \int_0^4 3z^2dydz - 
\int_0^2 \int_0^3 6dzdx$$

$$ = 72$$

### Orientation

積分出來的結果其實是有方向性的

![[orientation of flux surface integral.png|150]]

拿上一題為例

$$\vec r = 
\left[
	\begin{array}{}
		u \\
		u^2 \\
		v
	\end{array}
\right]$$

$$\text{ Reverse } \tilde r = 
\left[
	\begin{array}{}
		v \\
		v^2 \\
		u
	\end{array}
\right]$$

$$\tilde N = \tilde r_u \times \tilde r_v = 
\left[
	\begin{array}{}
		0 \\
		0 \\
		1
	\end{array}
\right] \times 
\left[
	\begin{array}{}
		1 \\
		2v \\
		0
	\end{array}
\right] = 
\left[
	\begin{array}{}
		2v \\
		1 \\
		0
	\end{array}
\right]$$

$$\underset R \iint \vec F(\tilde s(u, v)) \cdot \tilde N dvdu$$

$$ = \int_0^3\int_0^2(-6u^2v + 6)dvdu$$

$$ = -72$$

答案與上一題差一個負號，方向不同

#### Integral without orientation

$$\underset S \iint g(\vec r)dA = \underset R \iint g(\vec r(u, v)) \vert \vec N(u, v) \vert dudv$$

- no orientation
- scalar [[field]] $g(\vec r(u, v))$

---

參考資料:

工程數學上課

---

link:

$\nabla f$: [[Field#Scalar Field]]