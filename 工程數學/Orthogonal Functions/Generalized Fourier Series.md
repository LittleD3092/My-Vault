標籤: #工程數學 

---

為了算出 [[Orthogonal Series Expansion]] 中的 $c_n$

對 $f(x) = \sum_{ n = 0 }^{ \infty }c_n \phi_n(x)$ 兩邊乘上 $\phi_n^*(x)$ 並積分

$$\int_a^b f(x)\phi_n^*(x)dx = \sum_{ m = 0 }^{ \infty } c_m\int_a^b\phi_m(x)\phi_n^*(x)dx$$

$\because \phi_), \phi_1, \phi_3 \dots$ [[Orthogonal]]

$\therefore \int_a^b \phi_m(x)\phi_n^*(x)dx$ 只有在 $m = n$ 時不為 $0$
只保留 $m = n$ 那一項，其他項刪掉

$$\implies \int_a^b f(x) \phi_n^*(x)dx = c_n\int_a^b\phi_n(x)\phi_n^*(x)dx$$

$$\implies c_n = \frac{ \int_a^b f(x) \phi_n^*(x)dx }{ \int_a^b \phi_n(x)\phi_n^*(x)dx }$$

$c_n$ 被稱為 generalized fourier series

# 進一步簡化

當 $\phi_0(x), \phi_1(x), \phi_2(x), \phi_3(x) \dots$ 為 [[Orthogonal]]

$$c_n = \int_a^b f(x)\phi_n^*(x)dx$$

---

參考資料:

微分方程OCW class 24

---

link:

