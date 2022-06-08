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

All $p$ below is period.
All $L$ below is half period.

| Method                             | Equation                                                                                                                                                                                                                                               |
| ---------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| [[Fourier Series]] of $p = 2\pi$   | $$f(x) = a_0 + \sum_{n = 1}^\infty a_n\cos nx + b_n\sin nx$$ $$a_0 = \frac 1 {2\pi} \int_{-\pi}^\pi f(x)dx$$ $$a_n = \frac 1 \pi \int_{-\pi}^\pi f(x)\cos nx dx$$ $$b_n = \frac 1 \pi \int_{-\pi}^{\pi} f(x)\sin nx dx$$                               |
| [[Fourier Series]] of any $p = 2L$ | $$f(x) = a_0 + \sum_{n = 1}^\infty (a_n\cos\frac{n\pi}{L}x + b_n\sin\frac{n\pi}{L}x)$$ $$a_0 = \frac 1 {2L}\int_{-L}^L f(x)dx$$ $$a_n = \frac 1 L \int_{-L}^L f(x)\cos \frac{n\pi x}{L}dx$$ $$b_n = \frac 1 L \int_{-L}^L f(x)\sin\frac{n\pi x}{L}dx$$ |
| Odd / Even & Half-Range            | Odd: $$f(x) = \sum_{n = 1}^\infty b_n \sin\frac{n\pi}{L}x$$ $$b_n = \frac 2 L \int_0^L f(x)\sin\frac{n\pi x}{L}dx$$ Even: $$f(x) = a_0 + \sum_{n = 1}^\infty a_n \cos\frac{n\pi}{L}x$$ $$a_0 = \frac 1 L \int_0^L f(x)dx$$                                                                 |

[[Fourier Series]]
[[Fourier Integral]]
[[Fourier Transform]]

---

參考資料:

微分方程OCW class 24
工程數學上課

---

link:

