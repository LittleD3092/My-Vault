標籤: #list #工程數學 

> 解法: 
> 
> - [[Solution Curves without a Solution]]
> - [[Numerical Method]]
> - [[Separable Variables]]
> - [[Linear Equations]]
> - [[Exact Equations]]
>   - Modified Exact Equation
> - [[Homogeneous Substitution]]
> - [[Bernoulli's Equations Substitution]]
> - [[Substitution Ax By C]]
> ---
> - Extra step
>   - [[singular solution]]
>   - [[singular point]]
> - [[#tips]]
> ---
> [[工程數學/First Order DE/Table of Integration]]

---

# tips

## 如果不容易積分

1. 可以像這樣寫

> $$\frac{dy}{dx} = e^{-x^2}\qquad y(3)=5$$
> $$\text{Solution}\quad y(x)=5+\int_{3}^{x}e^{-t^2}dt$$

2. 或者表示成[[complementary error function]]

> [[error function]]: 
> $$erf(x)=\frac{2}{\sqrt{\pi}}\int_{0}^{x}e^{-t^2}dt$$
> [[complementary error function]]: 
> $$erfc(x)=\frac{2}{\sqrt{\pi}}\int_{x}^{\infty}e^{-t^2}dt=1-erf(x)$$

> 上面的例子寫成[[complementary error function]]
> $$y(x)=5+\frac{\sqrt{\pi}}{2}(erfc(3)-erfc(x))$$

3. when $dy/dx$ is not easy to calculate, try to calculate $dx/dy$


---

link:

[[Higher Order DE解法]]