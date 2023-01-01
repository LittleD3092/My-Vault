標籤: #工程數學 

---

主要把high order 簡化成1st order 方便運算

可以求出complementary function

# 條件有四個:
1. 2nd Order
2. linear
3. homogeneous
4. One of the [[Nontrivial Solution]] $y_1(x)$ has been known

$$a_2(x)y'' + a_1(x)y' + a_0(x)y = 0$$

# 解法

先將 DE 變成 Standard form
$$y'' + P(x)y' + Q(x)y = 0$$
.
$$\text{將}\; y(x) = u(x)y_1(x) \text{代入}$$
$$\left( \; y' = uy_1' + u'y_1 \qquad y'' = uy_1'' + 2u'y_1' + u''y_1 \;  \right )$$
.
$$uy_1'' + 2u'y_1' + u''y_1 + P(x)uy_1' + P(x)u'y_1 + Q(x)uy_1 = 0$$
$$u\underbrace{ (y_1'' + P(x)y_1' + Q(x)y_1) }_{ \text{zero} } + 2u'y_1' + u''y_1 + P(x)u'y_1 = 0$$
.
$$u''y_1 + u'(2y_1' + P(x)y_1) = 0$$
set $w = u'$
$$\frac{dw}{dx}y_1 + w(2\frac{dy_1}{dx} + P(x)y_1) = 0$$
multiplied by $dx/(y_1w)$
$$\frac{dw}{w} + 2\frac{dy_1}{y_1} + P(x)dx = 0$$
.
$$\int\frac{dw}{w} + 2\int\frac{dy_1}{y_1} + \int P(x)dx = 0$$
.
$$\ln\vert w\vert + c_3 + 2\ln\vert y_1\vert + c_4 = -\int P(x)dx$$
.
$$\ln\vert wy_1^2\vert = -\int P(x)dx + c$$
.
$$\ln\vert wy_1^2\vert = -\int P(x)dx + c$$
.
$$wy_1^2 = \pm e^{\int P(x)dx + c}$$
.
$$w = c_1e^{P(x)dx} / y_1^2$$
.
$$u = \int wdx = c_1\int \frac{e^{-\int P(x)dx}}{y_1^2}dx + c_2$$
.
$$\underbrace{y_2(x) = y_1(x)\int \frac{e^{-\int P(x)dx}}{y_1^2(x)}dx}_{\text{公式}}$$

(因為我們算 $u(x)$ 的目的，只是為了要算出與 $y_1(x)$ 互相 independent 的另一個解)

# Case 1

The 2nd order DE has the form of 
$$F(x, \underbrace{\frac{d}{dx}y}_{u}, \underbrace{\frac{d^2}{dx^2}y}_{\frac{d}{dx}u}) = 0$$

Step 1: Set $u = \frac{d}{dx}y$
此時 DE 變成
$$F(x, u, \frac{d}{dx}u) = 0$$
(對 $u$ 而言，是1st order DE)

Step 2: 將 $u$ 解出來

Step 3: 對 $u$ 做積分，即解出 $y$

## Example 1

$$y'' = 2x(y')^2$$
.
(Step 1)
$$u = y'$$
$$\frac{d}{dx}u = 2xu^2$$
.
(Step 2)
$$u = -\frac{1}{x^2 + c}$$
.
(Step 3)
$$y = -\int \frac{1}{x^2 + c}$$
[[Table of Integration]]
.
$$=-\frac{1}{\sqrt{c}}\tan^{-1}(\frac{x}{\sqrt{c}}) + c_1$$

---

# Case 2

$$F(y, \underbrace{\frac{d}{dx}y}_{u}, \underbrace{\frac{d^2}{dx^2}y}_{u\frac{d}{dy}u}) = 0$$

解法:

(Step 1):
Set
$$u = \frac{d}{dx}y$$
$$\frac{d^2}{dx^2}y = \frac{d}{dx}u = \frac{dy}{dx}\frac{d}{dy}u = u\frac{d}{dy}u\quad \text{(Chain rule)}$$
.
此時DE變成
$$F(y, u, u\frac{d}{dy}u) = 0$$
(對 $u$ 而言，是 1st order DE, independent variable 為 $y$)
.
(Step 2):
將 $u$ 解出來(用Section 2的方法)
得出的解， $u$ 是 $y$ 的函數 $u = F_1(y)$
.
(Step 3):
$$\frac{dy}{dx} = F_1(y)\quad \frac{dy}{F_1(y)} = dx$$
用 separable variable 的方法即可將解得出

## Example 2

$$yy'' = (y')^2$$

(Step 1)
Set
$$u = \frac{d}{dx}y$$
$$y\cdot u\frac{d}{dy}u = 
u^2$$
.
(Step 2)
$$\frac{du}{u} = 
\frac{dy}{y}$$
.
$$\ln\vert u\vert = \ln\vert y\vert + c_1$$
.
$$\vert u\vert = \vert y\vert e^{c_1}$$
.
$$u = c_2y \quad (c_2 = \pm e^{c_1})$$
.
(Step 3)
$$\frac{dy}{dx} = c_2 y$$
.
$$\frac{dy}{y} = c_2dx$$
.
$$\ln\vert y \vert = c_2x + c_3$$
.
$$\vert y\vert = e^{c_2x}e^{e_3}$$
.
$$y = c_4e^{c_2x}\quad (c_4 = \pm e^{c_3})$$

---

# Case 3: if one solution is known

如果有一個解已知，也可以使用 Reduction of Order 來解出答案

這個方法需要 DE 是 homogeneous $g(x) = 0$

基本想法是假設 $y_2 = u(x)y_1$, 然後把它代入並整理

---

題目DE:
$$y''+ p(x)y' + q(x)y = 0$$
.
Step 1, 代入
$$
\left\{
	\begin{array}{l}
		y & = & y_2 & = & uy_1 \\
		y' & = & y_2' & = & u'y_1 + uy_1' \\
		y'' & = & y_2'' & = & u''y_1 + 2u'y_1' + uy_1''
	\end{array}
\right.
$$
得到
$$u''y_1 + 2u'y_1' + uy_1'' + p(u'y_1 + uy_1') + quy_1 = 0$$
$$\implies u''y_1 + u'(2y_1' + py_1) + u(y_1'' + py_1' + qy_1) = 0$$
.
Step 2, 消去$u$
$$\because y'' + p(x)y' + q(x)y = 0$$
$$\therefore \implies u''y_1 + u'(2y_1' + py_1) = 0$$
.
Step 3, use reduction of order [[#Case 1]]
$$u' = U\qquad u'' = U'$$
$$U' + U(\frac{2y_1' + py_1}{y_1}) = 0$$
$$U' + (\frac{2y_1'}{y_1} + p)U = 0$$
.
Step 4, use [[Separable Variables]] 得出解

---

參考資料:

[Systems of Linear DEs; Nonlinear DEs](https://youtu.be/4g4Jft-3LCU)
工程數學課本

---

link:

[[Higher Order DE解法]]
