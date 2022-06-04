標籤: #工程數學

---

For a linear DE:
$$a_ny^{(n)}(x) + a_{n-1}y^{(n-1)}(x) + ... + a_1y'(x) + a_0y = g(x)$$

Annihilator: 可以殲滅 $g(x)$ 的 operator

## 使用條件

 > 和[[Superposition Approach]]一樣

1. Linear
2. Constant coefficients
3. $g(x)$, $g'(x)$, $g''(x)$, $g'''(x)$, $g^{(4)}(x)$, $g^{(5)}(x)$, ...contain finite number of terms
 
## General rule

### rule 1

If $g(x) = (a_nx^n + a_{n-1}x^{n-1} + ... + a_0)e^{ax}$

then the annihilator is $(D - \alpha)^{n+1}$

### rule 2

If $g(x) = (a_nx^n + a_{n-1}x^{n-1} + ... + a_0)e^{\alpha x}(b_1\cos \beta x + b_2\sin \beta x)$

$b_1 \neq 0 \;\text{or }\; b_2 \neq 0$

then the annihilator is $\left(D^2 - 2\alpha D + (\alpha^2 + \beta^2)\right)^{n+1}$

> 原理:
> $$g(x) = (a_nx^n + a_{n-1}x^{n-1} + ... + a_0)\underline{e^{\alpha x}(b_1\cos \beta x + b_2\sin \beta x)}$$
> $$\implies (c_1e^{\alpha x + j\beta x} + c_2e^{\alpha x - j \beta x})$$
> $$(D - \alpha - j\beta)(D - \alpha + j\beta) = (D^2 - 2\alpha D + \alpha^2 + \beta^2)$$

### rule 3

If $g(x) = g_1(x) + g_2(x) + ... + g_k(x)$
$$L_h[g_h(x)] = 0 \;\text{but}\; L_h[g_m(x)] \neq 0 \;\text{if}\; m\neq h,$$
then the annihilator of $g(x)$ is the product of $L_h(h = 1~k)$
$$L_k L_{k-1} ... L_2 L_1$$

## Examples

### Example 1

$$y'' + 3y' + 2y = 4x^2$$
.
$$\text{Step 1: Complementary function}$$
$$\text{solution of the associated homogeneous function}$$
$$y_c = c_1e^{-x} + c_2e^{-2x}$$
.
$$\text{Step 2-1: Annihilation: }D^3$$
$$L_1[L(y)] = L_1[g(x)] = 0$$
.
$$\text{Step 2-2: }D^3(D^2 + 3D + 2)y = 0$$
.
$$\text{Step 2-3: auxiliary function} \; m^3(m^2 + 3m + 2) = 0$$
$$\text{roots: }m_1 = m_2 = m_3 = 0, m_4 = -1, m_5 = -2$$
$$\text{Solution for }L_1[L(\tilde{y})] = 0 \text{:}$$
$$\tilde{y} = d_1 + d_2x + d_3x^2 + \underbrace{d_4e^{-x} + d_5e^{-2x}}_{\text{移除和complementary function 相同的部分}}$$
.
$$\begin{array}{}\text{Step 2-4: particular solution } & y_p = A + Bx + Cx^2 & y_p' = B + 2Cx \\ & & y_p'' = 2C \end{array}$$
.
$$\text{Step 2-5: }y_p'' + 3y_p' + 2y = 2Cx^2 + (2B + 6C)x + (2A + 3B + 2C) = 4x^2$$
$$\left\{ \begin{array}{} 2C = 4 \\ 2B + 6C = 0 \\ 2A + 3B + 2C = 0 \end{array} \right. \implies \begin{array}{} C = 2 \\ B = -6 \\ A = 7 \end{array}$$
.
$$\text{Step 3: } y = y_c + y_p = c_1e^{-x} + c_2e^{-2x} + 7 - 6x + 2x^2$$

---

參考資料:

[Class 11: Annilator Approach](https://youtu.be/JcgQYtArOWA)

[[Higher Order DE解法]]