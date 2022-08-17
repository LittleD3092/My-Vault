標籤: #工程數學 

Bernoulli's equation:
$$\frac{dy}{dx} + P(x)y = f(x)y^n$$
$$\text{We can set}\quad u = y^{1-n},\; \frac{dy}{dx} = \frac{1}{1 - n}u^{\frac{n}{1-n}}\frac{du}{dx}$$

代入後
$$\frac{1}{1-n}u^{\frac{n}{1-n}}\frac{du}{dx} + P(x)u^{\frac{1}{1-n}} = f(x)u^{\frac{n}{1 - n}}$$
$$\overset{\text{乘}\;(1-n)u^{\frac{-n}{1-n}}}{\implies}\frac{du}{dx} + P(x)(1-n)u = (1-n)f(x)$$

接著可以用 [[Linear Equations]] 解

最後記得代回$u = y^{1-n}$

還有算[[singular point]]