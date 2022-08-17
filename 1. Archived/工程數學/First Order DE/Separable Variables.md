標籤: #工程數學

## limitation

$\frac{dy(x)}{dx} = f(x,y)$ should be able to separate as $f(x,y) = g(x)h(y)$

> Example:
> $$\frac{dy}{dx} = cos(x)e^{x+2y}$$
> $$\implies\begin{cases} g(x)=cos(x)e^x \\ h(y)=e^{2y} \end{cases}$$

## solve

$$\frac{dy}{dx} = g(x)h(y)$$

**step1 seperate variebles:**
> $$\frac{dy}{h(y)} = g(x)dx$$
$$\implies p(y)dy = g(x)dx, \qquad where\quad p(y) = \frac{1}{h(y)}$$

**step2 integrate each side:**
> [[Table of Integration]]
$$\int p(y)dy=\int g(x)dx$$
$$\implies P(y)+c_1 = G(x)+c_2$$
$$\implies P(y) = G(x)+c$$

**Extra Step:**
1. Check initial conditions
2. Check [[singular solution]]
3. Check [[singular point]]