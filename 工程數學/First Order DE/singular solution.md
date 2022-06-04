標籤: #工程數學 

將 $y$ 代入 $r$ 當成常數，最後 $r$ 算出來就是 singular solution

> Example:
> $$(1+x)dy-ydx=0$$
> $$\implies \frac{dy}{dx} = \frac{y}{1+x}$$
> $$\text{set} y = r$$
> $$0=\frac{r}{1+x}$$
> $$\implies r = 0$$
> $$\implies y = 0\qquad\text{a special case of the general solution}$$

> Example:
> $$\frac{dy}{dx} = -\frac{x}{y}, \; y(4) = -3$$
> $$\text{set}\; y = r$$
> $$\implies 0 = -\frac{x}{r}$$
> $$\implies \text{not satisfy}\;y(4) = -3$$
> $$\implies \text{no singular solution}$$

singular solution 有可能會提供更多的解，但也有可能不會。**是否會提供更多解:**

若題目長這樣
$$\frac{dy}{dx}=f(x,y)$$
對f微分
$$\frac{\partial f(x,y)}{\partial y}$$
將結果趨近initial condition ，看是不是continuous，如果不是continuous 就會有singular solution