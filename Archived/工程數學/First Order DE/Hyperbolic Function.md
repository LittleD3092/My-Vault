標籤: #工程數學 

---

雙曲函數

## 定義

$$\sinh (x) = \frac{e^x - e^{-x}}{2}$$
$$\cosh (x) = \frac{e^x + e^{-x}}{2}$$
$$\tanh (x) = \frac{\sinh (x)}{\cosh (x)} = \frac{e^x - e^{-x}}{e^x + e^{-x}}$$
$$\cot(x) = \frac{\cosh (x)}{\sinh(x)} = \frac{e^x + e^{-x}}{e^x - e^{-x}}$$
$$\text{sech}(x) = \frac{1}{\cosh(x)} = \frac{2}{e^x + e^{-x}}$$
$$\rm{csch}(x) = \frac{1}{\sinh(x)} = \frac{2}{e^x - e^{-x}}$$
> 比較:
> $$\sin(x) = \frac{e^{jx} - e^{-jx}}{2j}$$
> $$\cos(x) = \frac{e^{jx} + e^{-jx}}{2}$$

> $$e^{jx} = \cos x + j\sin x\qquad \text{(Euler)}$$
> $$e^{-jx} = \cos x - j\sin x$$

## 微分結果

$$\frac{d}{dx}\sinh(ax) = a\cosh(ax) \qquad \qquad \sinh(0) = 0$$
$$\frac{d}{dx}\cosh(ax) = a\sinh(ax) \qquad \qquad\cosh(0) = 1$$
$$\frac{d}{dx}\tanh(ax) = a\,{\rm sech}^2 (ax) \qquad \qquad \sinh'(0) = 1$$
$$\frac{d}{dx}\,{\rm coth}(ax) = -a{\rm csch}^2(ax) \qquad \qquad {\rm cosh}'(0) = 0$$
$$\frac{d}{dx}\,{\rm sech}(ax) = -a {\rm sech}(ax){\rm tanh}(ax) \qquad \qquad \sin(ix) = i\sinh(x)$$
$$\frac{d}{dx}{\rm csch}(ax) = -a{\rm csch}(ax){\rm coth}(ax) \qquad \qquad \cos(ix) = \cosh(x)$$

---

[Class 10: Solving the Linear and Constant Coefficient DE](https://youtu.be/4yTXud2Ig88)

[[工數名詞解釋]]