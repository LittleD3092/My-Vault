標籤: #工程數學 

especially for computer analysis, can only approximate

$$x\overset{sampling}{\implies}x_0, x_1, x_2, ...$$
$$\frac{dy(x)}{dx} = f(x, y)$$
$$\overset{approximation}{\implies}\frac{y(x_{n+1})-y(x_n)}{x_{n+1}-x_n} = f(x_n, y(x_n))$$
$$\implies y(x_{n+1}) = y(x_n)+f(x_n, y(x_n))(x_{n+1}-x_n)$$

> Example:
> $$\frac{dy(x)}{dx} = 0.2xy$$
> $$\implies y(x_{n+1}) = y(x_n)+0.2x_ny(x_n)*(x_{n+1}-x_n)$$

> Example:
> $$\frac{dy}{dx} = sin(x)$$
> $$\implies y(x_{n+1}) = y(x_n)+sin(x_n)*(x_{n+1}-x_n)$$