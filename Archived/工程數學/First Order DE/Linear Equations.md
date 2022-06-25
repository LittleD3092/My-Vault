標籤: #工程數學

# 原理

linear equations的長相
$$a_1(x)\frac{dy}{dx}+a_0(x)y=g(x)$$

$g(x)=0:\text{homogeneous}$
$g(x)\neq 0:\text{nonhomogeneous}$
如果是Homogeneous 可以用分離變數解出來

$$\text{standard form: }\frac{dy}{dx}+P(x)y=f(x)$$
![[工程數學線性解.png]]
子問題一 (by seperation): $$\frac{dy_c}{dx}+P(x)y_c=0$$
$$\implies \frac{dy_c}{y_c}=-P(x)dx$$
$$\implies ln\vert y_c\vert=\int -P(x)dx+c_1$$
$$\implies y_c=ce^{-\int P(x)dx}$$

$$\text{Set } y_1=e^{-\int P(x)dx}\text{, then }y_c=cy_1$$

子問題二 (by 代入 $y_1$): 
$$\frac{dy_p(x)}{dx}+P(x)y_p(x)=f(x)$$
$$\text{Set }y_p(x)=u(x)y_1(x)$$
$$\implies u(x)\frac{dy_1(x)}{dx}+y_1(x)\frac{du(x)}{dx}+P(x)u(x)y_1(x)=f(x)$$
$$\implies y_1(x)\frac{du(x)}{dx}+u(x)\underbrace{\left(\frac{dy_1}{dx}+P(x)y_1(x)\right)}_{\text{equals zero}}=f(x)$$
$$\implies y_1(x)\frac{du(x)}{dx}=f(x)$$
$$\implies du(x)=\frac{f(x)}{y_1(x)}dx \implies u(x)=\int \frac{f(x)}{y_1(x)}dx \implies y_p(x)=y_1(x)\int \frac{f(x)}{y_1(x)}dx$$

![[工程數學線性解和 intergrating factor.png]]

# 五步驟解法

![[螢幕擷取畫面 (214).png]]

> $$\text{example: }\frac{dy}{dx} - 3y = 6$$
$$\overset{ \text{Step 1} }{ \implies } P(x) = -3$$
$$\overset{ \text{Step 2} }{ \implies } e^{\int p(x)dx} = e^{ -3x }$$
$$\overset{ \text{Step 3} }{ \implies } \frac{ d }{ dx } \left( e^{ -3x }y \right) = 6e^{-3x}$$
$$\overset{ \text{Step 4} }{ \implies } e^{-3x}y = -2e^{-3x} + c$$
$$\implies y = -2 + ce^{3x}$$

# 特別題型: 要求 y(x) continuous

## example

$$\frac{dy}{dx} + y = f(x) \qquad y(0) = 0 \quad f(x) = \left\{ \begin{matrix} 1, \quad & 0 \leq x \leq 1 \\ 0, \quad & x > 1 \end{matrix} \right.$$

$$\overset{ \text{step 2} }{ \implies }e^{ \int P(x)dx } = e^x$$
$$\overset{ \text{step 3} }{ \implies } \frac{d}{dx}( e^xy ) = e^xf(x)$$

.

$$\overset{0\leq x\leq 1}{\implies}\frac{d}{dx}(e^xy) = e^x$$
$$\implies e^xy = e^x + c_1$$
$$\implies y = 1 + c_1e^{-x}$$
$$\overset{\text{from initial condition}}{\implies}y = 1 - e^{-x}$$

.

$$\overset{x>1}{\implies} \frac{d}{dx}(e^xy)=0$$
$$\implies e^xy = c_2$$
$$\implies y = c_2e^{-x}$$
$$\overset{y(x)\text{ is continuous at }x = 1}{\implies} y = (e-1)e^{-x}$$