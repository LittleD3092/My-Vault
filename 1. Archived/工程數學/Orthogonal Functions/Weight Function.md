標籤: #工程數學 

---

加上 weight function 後， [[Inner Product]] 的定義會改變

$$(f_1(x), f_2(x)) = \int_a^b w(x)f_1(x)f_2^*(x)dx$$

$w(x)$: weight function

並且其他的定義也會改變

# [[Orthogonal]]

$$(f_m, f_n) = \int_a^b w(x)f_m(x) f_n^*(x)dx = 0 \qquad \text{ for } m \neq n$$

# [[Square Norm]]

$$\vert\vert f(x) \vert\vert^2 = \int_a^b w(x)f(x)f^*(x)dx$$

# [[Norm]]

$$\vert\vert f(x) \vert\vert = \sqrt{ \int_a^b w(x)f(x)f^*(x)dx }$$

# [[Orthonormal Set]]

$$\int_a^b w(x)f_m(x)f_n^*(x)dx = 0 \qquad \text{ for } m\neq n$$

$$\int_a^b w(x)f_n(x)f_n^*(x)dx = 1$$

# [[Normalize]]

$$v(x) = \frac{ \psi(x) }{ \vert\vert \psi(x) \vert\vert } = \frac{ \psi(x) }{ \sqrt{ \int_a^b w(x) \psi(x) \psi^*(x)dx } }$$

# [[Orthogonal Series Expansion]]

$$f(x) = \sum_{ n = 0 }^{ \infty }c_n\phi_n(x)$$

# [[Generalized Fourier Series]]

$$c_n = \frac{ \int_a^b w(x)f(x)\phi_n^*(x)dx }{ \int_a^b w(x)\phi_n(x)\phi_n^*(x)dx }$$

---

參考資料:

微分方程OCW class 24

---

link:

