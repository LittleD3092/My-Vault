標籤: #工程數學 

---

利用 [[Eigenvalue]]，求出 [[ODE & PDE|ODE]] 的解

# 解法

## 列出兩行式子的情況

### Step 1 列式

$$
\begin{array}{}
y_1' & = & -0.02y_1 & + & 0.02y_2 \\
y_2' & = & 0.02y_1 & - & 0.02y_2
\end{array}
$$

$y$ 向量如下

$$
y = 
\left[
\begin{array}{}
y_1 \\
y_2
\end{array}
\right]
$$

利用 $y$ 向量重新列式

$$
y' = Ay \qquad A = 
\left[
\begin{array}{}
-0.02 & 0.02 \\
0.02 & -0.02
\end{array}
\right]
$$

### Step 2 求 general solution

假設解為 exponential function

$$y = xe^{ \lambda t }$$

則解 $y$ 的微分

$$y' = \lambda x e^{ \lambda t }$$

根據 [[#Step 1 列式|Step 1]] 的列式整理 $y'$

$$y' = \lambda x e^{ \lambda t } = Axe^{ \lambda t }$$

同時除以 $e^{ \lambda t }$

$$\lambda x = Ax$$

使用 [[Eigenvalue]] 的解法，得出 $\lambda$

$$\det (A - \lambda I) = 
\left\vert
\begin{array}{}
-0.02 - \lambda & 0.02 \\
0.02 & -0.02 - \lambda
\end{array}
\right\vert = 
(-0.02 - \lambda)^2 - 0.02^2 = \lambda(\lambda + 0.04) = 0$$

$$
\left\{
\begin{array}{l}
\lambda_1 = 0 \\
\lambda_2 = -0.04
\end{array}
\right.
$$

將 $\lambda$ 代入下式，求出 [[Eigenvector]]

$$
\left[
\begin{array}{}
a_{ 11 } - \lambda & a_{ 12 } \\
a_{ 21 } & a_{ 22 } - \lambda
\end{array}
\right]
\left[
\begin{array}{}
x_1 \\
x_2
\end{array}
\right] = 
\left[
\begin{array}{}
0 \\
0
\end{array}
\right]
\quad , \quad
\left\{
\begin{array}{l}
\lambda_1 = 0 \\
\lambda_2 = -0.04
\end{array}
\right.
$$
.
$$
\implies
\left[
\begin{array}{}
-0.02 - \lambda & 0.02 \\
0.02 & -0.02 - \lambda
\end{array}
\right]
\left[
\begin{array}{}
x_1 \\
x_2
\end{array}
\right] = 
\left[
\begin{array}{}
0 \\
0
\end{array}
\right]
$$
.
$$
\implies
\left\{
\begin{array}{}
	\left[
	\begin{array}{}
		-0.02 - 0 & 0.02 \\
		0.02 & -0.02 - 0
	\end{array}
	\right]
	\left[
	\begin{array}{}
		x_1 \\
		x_2
	\end{array}
	\right] = 
	\left[
	\begin{array}{}
		0 \\
		0
	\end{array}
	\right]
	
	\\
	
	\left[
	\begin{array}{}
		-0.02 - (-0.04) & 0.02 \\
		0.02 & -0.02 - (-0.04)
	\end{array}
	\right]
	\left[
	\begin{array}{}
		x_1 \\
		x_2
	\end{array}
	\right] = 
	\left[
	\begin{array}{}
		0 \\
		0
	\end{array}
	\right]
\end{array}
\right.
$$
.
$$
\implies 
\left\{
\begin{array}{l}
-0.02x_1 + 0.02x_2 = 0 \\
(-0.02 + 0.04)x_1 + 0.02x_2 = 0
\end{array}
\right.
\qquad
\text{ 最後只會得出兩個，因為另外兩個無效 }
$$
.
$$
\implies
\left\{
\begin{array}{l}
	x_1 = x_2 \\
	x_1 = -x_2
\end{array}
\right.
$$

可以得出兩個 [[Eigenvector]]

$$x^{(1)} = 
\left[
\begin{array}{}
	1 \\
	1
\end{array}
\right]
\quad \text{ and } \quad
x^{ (2) } = 
\left[
\begin{array}{r}
	1 \\
	-1
\end{array}
\right]$$

將 [[Eigenvalue]] 和 [[Eigenvector]] 代入

$$
\left\{
\begin{array}{}
	\lambda_1 = 0 \\
	\lambda_2 = -0.04 \\
	x^{ (1) } = 
	\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
	\right] \\
	x^{ (2) } = 
	\left[
	\begin{array}{r}
		1 \\
		-1
	\end{array}
	\right]
\end{array}
\right.
\quad , \quad 
y = c_1x^{ (1) }e^{ \lambda_1 t } + c_2x^{ (2) }e^{ \lambda_2 t }
$$
.
$$
\implies y = c_1
\left[
\begin{array}{}
	1 \\
	1
\end{array}
\right] + c_2
\left[
\begin{array}{r}
	1 \\
	-1
\end{array}
\right] e^{ -0.04t }
$$

### Step 3 initial condition

$$
t = 0 \quad , \quad y(0) = 
\left[ 
\begin{array}{}
	0 \\
	150
\end{array}
\right]
$$

$$
\implies y(0) = c_1
\left[
\begin{array}{}
	1 \\
	1
\end{array}
\right] + c_2
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right] = 
\left[
\begin{array}{}
	0 \\
	150
\end{array}
\right]
$$

$$
\implies 
\left\{
\begin{array}{}
	c_1 = 75 \\
	c_2 = -75
\end{array}
\right.
$$

$$\implies y = 75
\left[
\begin{array}{}
	1 \\
	1
\end{array}
\right] - 75
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right] e^{ -0.04 t }$$

$$
\implies 
\left\{
\begin{array}{}
	y_1 = 75 - 75 e^{ -0.04t } \\
	y_2 = 75 + 75 e^{ -0.04t }
\end{array}
\right.
$$

## 解一般 [[ODE & PDE|ODE]] 的情況

有一個 ODE

$$y^{ (n) } = F(t, y, y', \dots , y^{ (n - 1) })$$

將所有微分換成 $y_{component}$

$$y_1 = y, \quad y_2 = y' , \quad y_3 = y'' , \quad \dots , \quad y_n = y^{ (n - 1) }$$

整理成矩陣

$$
\left\{
\begin{array}{}
y_1'       & =      & y_2 \\
y_2'       & =      &     & y_3 \\
           & \vdots &     &     & \ddots\\
y_{n - 1}' & =      &     &     &        & y_n \\
y_n'       & =      &     &     &        & F(t, y_1, y_2, \dots , y_n)
\end{array}
\right.
$$

$$
y' = Ay = 
\left[
\begin{array}{}
0 & 1      & 0 & \dots  & 0 \\
0 & 0      & 1 & \dots  & 0 \\
0 & \vdots &   & \ddots & 0 \\
0 & 0      & 0 & \dots  & 1 \\
a_1 & a_2  & a_3 & \dots & a_n
\end{array}
\right]
\left[
\begin{array}{}
y_1 \\
y_2 \\
\vdots \\
y_{ n - 1 } \\
y_n
\end{array}
\right]
$$

利用 $\det (A - \lambda I) = 0$ 求出 [[Eigenvalue]] (如果不重根會有 $n$ 個)，帶入 $(A - \lambda I)x = 0$ 求 [[Eigenvector]] $x$

$$y = c_1x^{ (1) }e^{ \lambda_1 t } + c_2x^{ (2) }e^{ \lambda_2 t } + \dots + c_nx^{ (n) }e^{ \lambda_n t }$$

### 重根

直接看例子

> Example:
> $$
> \vec{ y' } = A \vec{ y } = 
> \left[
> \begin{array}{}
>     4 & 1 \\
>     -1 & 2
> \end{array}
> \right]
> $$

#### [[Eigenvalue]]:

一般的 [[Eigenvalue]] 求法，但是 [[Eigenvalue]] 有重根

$$
\det(A - \lambda I) = 
\left\vert
\begin{array}{}
	4 - \lambda & 1 \\
	-1 & 2 - \lambda
\end{array}
\right\vert
$$

$$ = \lambda^2 - 6\lambda + 9$$

$$ = (\lambda - 3)^2 = 0$$

$$\lambda = 3$$

#### [[Eigenvector]]:

先使用一般的 [[Eigenvector]] 求法求

$$
\left[
\begin{array}{}
	4 - 3 & 1 \\
	-1 & 2 - 3
\end{array}
\right] \vec{ k } = 
\left[
\begin{array}{}
	1 & 1 \\
	-1 & -1
\end{array}
\right] \vec{ k } = 
\left[
\begin{array}{}
	0 \\
	0
\end{array}
\right]
$$

$$\implies \vec{ k }^{ (1) } = 
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right]$$

$$
\implies
\vec{ y }_1 = 
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right] e^{ 3t }
$$

$\vec{ y }_2$ ，也就是重根會長的像下面這樣

$$\vec{ y }_2 = \vec{ k }^{ (1) } t e^{ \lambda t } + \vec{ k }^{ (2) } e^{ \lambda t }$$

把 $\vec{ y }_2$ 微分

$$\vec{ y }_2' = A \vec{ y }_2$$

$$\implies \vec{ k }^{ (1) } e^{ \lambda t } + \vec{ k }^{ (1) } \lambda t e^{ \lambda t } + \lambda \vec{ k }^{ (2) }e^{ \lambda t } = A \vec{ k }^{ (1) } t e^{ \lambda t } + A \vec{ k }^{ (2) } e^{ \lambda t }$$

把相似的係數整理

$$
\implies 
\left\{
\begin{array}{}
\vec{ k }^{ (1) } \lambda = A \vec{ k }^{ (1) } \\
\vec{ k }^{ (1) } + \lambda \vec{ k }^{ (2) } = A \vec{ k }^{ (2) }
\end{array}
\right.
$$

$$
\implies
\left\{
\begin{array}{}
	(A - \lambda I)\vec{ k }^{ (1) } = 0 \\
	(A - \lambda I)\vec{ k }^{ (2) } = \vec{ k }^{ (1) }
\end{array}
\right.
$$

第一條式子和我們之前做的事情一樣，所以把 $A$ 和 $\lambda$ 代入第二個式子

$$
\left[
\begin{array}{}
	4 - 3 & 1 \\
	-1 & 2 - 3
\end{array}
\right] \vec{ k }^{ (2) } = 
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right]
$$

$$
\implies
\left[
\begin{array}{}
	1 & 1 \\
	-1 & -1
\end{array}
\right] \vec{ k }^{ (2) } = 
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right]
$$

$$
\implies
\left\{
\begin{array}{}
	k_1^{ (2) } & + & k_2^{ (2) } & = & 1 \\
	-k_1^{ (2) } & - & k_2^{ (2) } & = & -1
\end{array}
\right.
$$

$$
\implies \vec{ k }^{ (2) } = 
\left[
\begin{array}{}
	1 - k_2^{ (2) } \\
	k_2^{ (2) }
\end{array}
\right]
$$

$$
\implies \vec{ k }^{ (2) } = 
k_2^{ (2) }
\left[
\begin{array}{}
	-1 \\
	1
\end{array}
\right] + 
\left[
\begin{array}{}
	1 \\
	0
\end{array}
\right]
$$

假設 $k_2^{ (2) } = 0$

$$\implies \vec{ k }^{ (2) } = 
\left[
\begin{array}{}
	1 \\
	0
\end{array}
\right]$$

有了 $\vec{ y }_1$ 和 $\vec{ y }_2$ 就可以代入

$$\vec{ y }_h = \vec{ y }_1 + \vec{ y }_2 = c_1
\left[
\begin{array}{}
	1 \\
	-1
\end{array}
\right] e^{ 3t } + c_2
\left(
	\left[
	\begin{array}{}
		1 \\
		-1
	\end{array}
	\right] t e^{ 3t } + 
	\left[
	\begin{array}{}
		1 \\
		0
	\end{array}
	\right] e^{ 3t }
\right)$$

### 虛根

跟實根的方法一樣，不過可以根據 [[Euler Formula]] 把他轉換成 $\sin$ 和 $\cos$

> [[Euler Formula]]:
> $$e^{ ix } = \cos x + i \sin x$$
> $x$: 任意實數

### Particular Solution

總共有兩種解法，分別是 [[Superposition Approach]] 和 [[Variation of Parameters]]

#### Superposition Approach (Undetermined Coefficients)

> 題目:
> $$\vec{ y }' = [A]\vec{ y } + \vec{ g } = 
> \left[
> \begin{array}{}
>     -3 & 1 \\
>     1 & -3
> \end{array}
> \right]\vec{ y } + 
> \left[
> \begin{array}{}
>     -6 \\
>     2
> \end{array}
> \right] e^{ -2t }$$
> 我們已經先解出 Homogeneous Solution:
> $$\vec{ y }_{ h } = c_1 
> \left[
> \begin{array}{}
>     1 \\
>     1
> \end{array}
> \right] e^{ -2t } + c_2 
> \left[
> \begin{array}{}
>     1 \\
>     -1
> \end{array}
> \right]e^{ -4t }$$

Particular Solution 的基礎型態(根據常數項)
$$\vec{ y }_{ p } = \vec{ u } e^{ -2t }$$

因為 $e^{ -2t }$ 和 $\vec{ y }_h$ 重複，因此修改 $\vec{ y }_p$ ，並且求出 $\vec{ y }_p'$ 。注意會多一個 $\vec{ v }$

$$\implies 
\left\{
\begin{array}{l}
\vec{ y }_p = \vec{ u } t e^{ -2t } + \vec{ v } e^{ -2t } \\
\vec{ y }_{ p }' = \vec{ u }e^{ -2t } - 2 \vec{ u } t e^{ -2t } - 2 \vec{ v } e^{ -2t }
\end{array}
\right.$$

帶回原式 $\vec{ y }' = [A] \vec{ y } + \vec{ g }$

$$\implies \vec{ u } e^{ -2t } - 2 \vec{ u }t e^{ -2t } - 2 \vec{ v } e^{ -2t } = [A](\vec{ u }te^{ -2t } + \vec{ v } e^{ -2t }) + 
\left[
\begin{array}{}
	-6 \\
	2
\end{array}
\right] e^{ -2t }$$

$$
\implies
\left\{
\begin{array}{}
	\text{ Collect } t e^{ -2t } \text{ terms } &  \rightarrow & ([A] + 2 I) \vec{ u } t e^{ -2t } = 0 \\
	\text{ Collect } e^{ -2t } \text{ terms } & \rightarrow & (\vec{ u } - ([A] + 2 I)\vec{ v }) e^{ -2t } = 
	\left[
	\begin{array}{}
		-6 \\
		2
	\end{array}
	\right] e^{ -2t }
\end{array}
\right.
$$

觀察上式可以看出 $\lambda = -2$ ，並且使用 [[Eigenvector]] 的方法也可以得出 $\vec{ u }$

$$
\left\{
\begin{array}{}
	\lambda = -2 \\
	\vec{ u } = 
	\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
	\right]a
\end{array}
\right.
$$

觀察下式

$$
(\vec{ u } - ([A] + 2 I)\vec{ v }) e^{ -2t } = 
\left[
\begin{array}{}
	-6 \\
	2
\end{array}
\right] e^{ -2t }
$$

$$
\implies
\vec{ u } - 2 \vec{ v } = [A] \vec{ v } + 
\left[
\begin{array}{}
	-6 \\
	2
\end{array}
\right]
$$

$$
\implies
\left[
\begin{array}{}
	a \\
	a
\end{array}
\right] - 2 
\left[
\begin{array}{}
	v_1 \\
	v_2
\end{array}
\right] = 
\left[
\begin{array}{}
	-3v_1 + v_2 \\
	v_1 - 3v_2
\end{array}
\right] + 
\left[
\begin{array}{}
	-6 \\
	2
\end{array}
\right]
$$

$$
\implies
\left\{
\begin{array}{}
	v_1 - v_2 & = & -a-6 \\
	-v_1 + v_2 & = & -a + 2
\end{array}
\right.
$$

$$
\implies
\left\{
\begin{array}{}
	a = -2 \\
	v_2 = v_1 + 4
\end{array}
\right.
$$

$$
\therefore
\left\{
\begin{array}{l}
	\vec{ u } = -2
	\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
	\right] \\
	\vec{ v } = 
	\left[
	\begin{array}{}
		0 \\
		4
	\end{array}
	\right] (\text{ assume } k = 0)
\end{array}
\right.
$$

$$
\implies \vec{ y }_p = -2
\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
\right] te^{ -2t } + 
\left[
	\begin{array}{}
		0 \\
		4
	\end{array}
\right] e^{ -2t }
$$

#### Variation of Parameters

> 題目:
> $$
> \vec{y}' = 
> \left[
>     \begin{array}{}
>         -3 & 1 \\
>         1 & -3
>     \end{array}
> \right] \vec{ y } + 
> \left[
>     \begin{array}{}
>         -6 \\
>         2
>     \end{array}
> \right] e^{ -2t }
> $$

Homogeneous Solution:

$$
\vec{ y }_h = c_1
\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
\right] e^{ -2t } + c_2
\left[
	\begin{array}{}
		1 \\
		-1
	\end{array}
\right] e^{ -4t }
$$

$$
[Y] = [\vec{ y }^{ (1) } \quad \vec{ y }^{ (2) }] = 
\left[
	\begin{array}{}
		e^{ -2t } & e^{ -4t } \\
		e^{ -2t } & -e^{ -4t }
	\end{array}
\right]
$$

Particular Solution:

$$
\vec{ y }_p = [Y]\vec{ u } = 
\left[
	\begin{array}{}
		e^{ -2t } & e^{ -4t } \\
		e^{ -2t } & -e^{ -4t }
	\end{array}
\right]
\left[
	\begin{array}{}
		u_1 \\
		u_2
	\end{array}
\right]
$$

$$
\vec{ y }_p' = [Y]'\vec{ u } + [Y]\vec{ u }' = [A]\vec{ y }_p + \vec{ g }
$$

$$
\implies[Y]' \vec{ u } + [Y] \vec{ u }' = [A][Y] \vec{ u } + \vec{ g }
$$

$$
\implies [Y]\vec{ u }' = \vec{ g }
$$

$$
\implies
\vec{ u }' = [Y]^{ -1 } \vec{g} = 
\left[
	\begin{array}{}
		-2 \\
		-4e^{ 2t }
	\end{array}
\right]
$$

> [[Inverse of Matrix]]

$$
\vec{ u } = \int_0^t 
\left[
	\begin{array}{}
		-2 \\
		-4e^{ 2t }
	\end{array}
\right] d\widetilde{ t }
$$

$$
= 
\left[
	\begin{array}{}
		-2 \widetilde{ t } \\
		-2e^{ 2 \widetilde{ t } }
	\end{array}
\right]_0^t
$$

$$
= 
\left[
	\begin{array}{}
		-2t \\
		-2e^{ 2t } + 2
	\end{array}
\right]
$$

$$
\vec{ y }_p = [Y]\vec{u}
$$

$$
=
\left[
	\begin{array}{}
		e^{ -2t } & e^{ -4t } \\
		e^{ -2t } & -e^{ -4t }
	\end{array}
\right]
\left[
	\begin{array}{}
		-2t \\
		-2e^{ 2t } + 2
	\end{array}
\right]
$$

$$
=
\left[
	\begin{array}{}
		-2te^{ -2t } - 2e^{ -2t } + 2e^{ -4t } \\
		-2te^{ -2t } + 2e^{ -2t } - 2e^{ -4t }
	\end{array}
\right]
$$

$$
= -2
\left[
	\begin{array}{}
		1 \\
		1
	\end{array}
\right] t e^{ -2t } + 2
\left[
	\begin{array}{}
		-1 \\
		1
	\end{array}
\right] e^{ -2t } + 2
\left[
	\begin{array}{}
		1 \\
		-1
	\end{array}
\right]e^{ -4t }
$$

記得 absorb

---

參考資料:

工數課本P131
工數PPT 4.0~4.1 P51
[Euler Formula - wiki](https://zh.wikipedia.org/wiki/%E6%AC%A7%E6%8B%89%E5%85%AC%E5%BC%8F)

---

link:

