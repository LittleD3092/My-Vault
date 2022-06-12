標籤: #list #工程數學 

---

[[Inner Product]]
[[Orthogonal]]
[[Orthogonal Set]]
[[Square Norm]]
[[Norm]]
[[Orthonormal Set]]
[[Normalize]]
[[Complete]]
[[Orthogonal Series Expansion]]
[[Generalized Fourier Series]]
[[Weight Function]]

---

==Cheat Sheet==:

All $p$ below is period.
All $L$ below is half period.

| Method                                                                          | Equation                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| ------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| [[Fourier Series]] of $p = 2\pi$                                                | $$f(x) = a_0 + \sum_{n = 1}^\infty a_n\cos nx + b_n\sin nx$$ $$a_0 = \frac 1 {2\pi} \int_{-\pi}^\pi f(x)dx$$ $$a_n = \frac 1 \pi \int_{-\pi}^\pi f(x)\cos nx dx$$ $$b_n = \frac 1 \pi \int_{-\pi}^{\pi} f(x)\sin nx dx$$                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [[Fourier Series]] of any $p = 2L$                                              | $$f(x) = a_0 + \sum_{n = 1}^\infty (a_n\cos\frac{n\pi}{L}x + b_n\sin\frac{n\pi}{L}x)$$ $$a_0 = \frac 1 {2L}\int_{-L}^L f(x)dx$$ $$a_n = \frac 1 L \int_{-L}^L f(x)\cos \frac{n\pi x}{L}dx$$ $$b_n = \frac 1 L \int_{-L}^L f(x)\sin\frac{n\pi x}{L}dx$$                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [[Fourier Series#Half-range Expansion\|Odd / Even & Half-Range]]                | Odd: $$f(x) = \sum_{n = 1}^\infty b_n \sin\frac{n\pi}{L}x$$ $$b_n = \frac 2 L \int_0^L f(x)\sin\frac{n\pi x}{L}dx$$ Even: $$f(x) = a_0 + \sum_{n = 1}^\infty a_n \cos\frac{n\pi}{L}x$$ $$a_0 = \frac 1 L \int_0^L f(x)dx$$ $$a_n = \frac 2 L \int_0^L f(x)\cos\frac{n\pi x}{L}dx$$                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [[Fourier Integral]]                                                            | $$f(x) = \int_0^\infty\left[A(w)\cos wx + B(w)\sin wx\right]dw$$ $$A(w) = \frac 1 \pi\int_{-\infty}^\infty f(v)\cos wv dv$$ $$B(w) = \frac 1 \pi \int_{-\infty}^\infty f(v)\sin wv dv$$ Fourier Sine Integral: $$f(x) = \frac{ 2 }{ \pi }\int_0^\infty B(\alpha)\sin(\alpha x)d\alpha$$ $$B(\alpha) = \int_0^\infty f(x)\sin(\alpha x)dx$$ Fourier Cosine Integral: $$f(x) = \frac{ 2 }{ \pi }\int_0^\infty A(\alpha)\cos(\alpha x)d\alpha$$ $$A(\alpha) = \int_0^\infty f(x)\cos(\alpha x)dx$$                                                                                                                                                                                                              | 
| Fourier Transform (switch from trigonometry basis to complex-exponential basis) | $$\hat f(w) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty f(x)e^{-iwx}dx$$ $$f(x) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty f(x)e^{iwx}dw$$                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| Discrete Fourier Transform                                                      | $$\hat f_n \equiv Nc_n = \sum_{k = 0}^{N - 1}f_ke^{-inx_k}\qquad ; n = 0, 1 \dots, N - 1$$ $$f_k = f(x_k) = q(x) = \sum_{n = 0}^{N - 1}c_n e^{inx_k}$$ Fourier matrix $\vec F_N = [e_{nk}]$: $n\times n$ matrix $$\left[\begin{array}{}\hat f_0 \\ \hat f_1 \\ \vdots \\ \hat f_{N - 1}\end{array}\right] = \vec{\hat f}_n = \vec F_N \vec f = \left[\begin{array}{} e^{-ix_0} & e^{-ix_1} & \dots & e^{-ix_{N - 1}} \\ e^{-i2x_0} & e^{-i2x_1} & \dots & e^{-i2x_{N - 1}} \\ \vdots & \vdots & \ddots & \vdots \\ e^{-inx_0} & e^{-inx_1} & \dots & e^{-inx_k}\end{array}\right]\left[\begin{array}{} f(x_0) \\ f(x_1) \\ \vdots \\ f(x_{N - 1}) \end{array}\right]$$ <ul><li>$x_k = \frac{2\pi k}{N}$</ul> |

Table of Fourier Transforms:

| $$f(x)$$                                                                                                                         | $$\hat f(w) = \mathcal F(f)$$                                                                          |
| -------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| $$\left\{ \begin{array}{} 1 & \text{if }-b < x < b \\ 0 & \text{otherwise} \end{array}\right.$$                                  | $$\sqrt{\frac 2 \pi}\frac{\sin bw}{w}$$                                                                |
| $$\left\{ \begin{array}{} 1 & \text{if }b < x < c \\ 0 & \text{otherwise} \end{array} \right.$$                                  | $$\frac{e^{-ibw} - e^{-icw}}{iw\sqrt{2\pi}}$$                                                          |
| $$\frac{1}{x^2 + a^2} \qquad (a > 0)$$                                                                                           | $$\sqrt{\frac \pi 2}\frac{e^{-a\vert w \vert}}{a}$$                                                    |
| $$\left\{ \begin{array}{} x & \text{if }0 < x < b \\ 2x - b & \text{if }b < x < 2b \\ 0 & \text{otherwise} \end{array} \right.$$ | $$\frac{-1 + 2e^{ibw} - e^{-2ibw}}{\sqrt{2\pi}w^2}$$                                                   |
| $$\left\{ \begin{array}{} e^{-ax} & \text{if }x > 0 \\ 0 & \text{otherwise} \end{array} \right. \qquad (a > 0)$$                 | $$\frac 1 {\sqrt{2\pi}(a + iw)}$$                                                                      |
| $$\left\{ \begin{array}{} e^{ax} & \text{if }b < x < c \\ 0 & \text{otherwise} \end{array} \right.$$                             | $$\frac{e^{(a - iw)c} - e^{(a - iw)b}}{\sqrt{2\pi}(a - iw)}$$                                          |
| $$\left\{ \begin{array}{} e^{iax} & \text{if }-b < x < b \\ 0 & \text{otherwise} \end{array} \right.$$                           | $$\sqrt{\frac 2 \pi}\frac{\sin b(w - a)}{w - a}$$                                                      |
| $$\left\{ \begin{array}{} e^{iax} & \text{if }b < x < c \\ 0 & \text{otherwise} \end{array} \right.$$                            | $$\frac{i}{\sqrt{2\pi}}\frac{e^{ib(a - w)} - e^{ic(a - w)}}{a - w}$$                                   |
| $$e^{-ax^2}\qquad(a > 0)$$                                                                                                       | $$\frac 1 {\sqrt{2a}}e^{-w^2 / 4a}$$                                                                   |
| $$\frac{\sin ax}{x} \qquad (a > 0)$$                                                                                             | $$\sqrt{\frac{\pi}{2}} \qquad \text{if } \vert w \vert < a;$$ $$0 \qquad \text{if }\vert w \vert > a$$ | 

[[Fourier Series]]
[[Fourier Integral]]
[[Fourier Transform]]

---

參考資料:

微分方程OCW class 24
工程數學上課

---

link:

