標籤: #工程數學 

---

用猜的方法

可以解 particular solution

$g(x)$: 前面沒有 $y$ (常數項)
$$y'' + p(x)y' + q(x)y = g(x)$$

# 條件

1. 線性
2. constant coefficient
3. $g(x), g'(x), g''(x), g'''(x), g^{(4)}(x), g^{(5)}(x),...\text{contain finite number of terms}$

# 解法

$g(x)$ 長什麼樣子，解就要長什麼樣子

| $g(x)$                   | $Form\, of \, y_p$                                |
| ------------------------ | ------------------------------------------------- |
| $1(\text{any constant})$ | $A$                                               |
| $5x + 7$                 | $Ax + B$                                          |
| $3x^2 - 2$               | $Ax^2 + Bx + C$                                   |
| $x^3 - x + 1$            | $Ax^3 + Bx^2 + Cx + E$                            |
| $\sin 4x$                | $A\cos 4x + B\sin 4x$                             |
| $\cos 4x$                | $A\cos 4x + B\sin 4x$                             |
| $\cosh 4x$               | $Ae^{4x} + Be^{-4x}$                              | 
| $e^{5x}$                 | $Ae^{5x}$                                         |
| $(9x - 2)e^{5x}$         | $(Ax + B)e^{5x}$                                  |
| $x^2e^{5x}$              | $(Ax^2 + Bx + C)e^{5x}$                           |
| $e^{3x}\sin 4x$          | $Ae^{3x}\cos 4x + Be^{3x}\sin 4x$                 |
| $5x^2\sin 4x$            | $(Ax^2 + Bx + C)\cos 4x + (Ex^2 + Fx + G)\sin 4x$ |
| $xe^{3x}\cos 4x$         | $(Ax + B)e^{3x}\cos 4x + (Cx + E)e^{3x}\sin 4x$   |

這張表依照 Form Rule

> Form Rule:
> $y_p$ should be a linear combination of $g(x)$, $g'(x)$, $g''(x)$, $g'''(x)$, $g^{(4)}(x)$, $g^{(5)}(x)$,...

# 小缺陷

## example

$$y'' - 5y' + 4y = 8e^x$$
$$\text{Particular solution guessed by Form Rule:}$$
$$y_p = Ae^x$$
$$y_p'' - 5y_p' + 4y_p = Ae^x - 5Ae^x + 4Ae^x = 8e^x$$
$$0 = 8e^x \qquad \text{(no solution)}$$
$$\text{why?}$$

## Glitch condition

The particular solution we guess belongs to the complementary function.
.
For example above $\qquad y'' - 5y' + 4y = 8e^x$
$$\text{Complementary function \qquad} y_c = c_1e^x + c_2e^{4x} \qquad Ae^x \in y_c$$
.
解決方法: 再乘一個 $x$
$$\begin{array}{} y_p = Axe^x & y_p' = Axe^x + Ae^x \\ & y_p'' = Axe^x + 2Ae^x \end{array}$$
.
$$y_p'' - 5y_p' + 4y_p = -3Ae^x = 8e^x \implies A = -\frac{8}{3}$$
.
$$y_p = -\frac{8}{3}xe^x$$
$$y = c_1e^x + c_2e^{4x} - \frac{8}{3}xe^x$$

> 如果乘一個 $x$ 不夠，還可以再乘多一點

---

參考資料:

[Class 10: Solving the Linear and Constant Coefficient DE](https://youtu.be/4yTXud2Ig88)
[Class 11: Annilator Approach](https://youtu.be/JcgQYtArOWA)

[[Higher Order DE解法]]
[[Nonhomogeneous Equations]]
[[Superposition Principle]]