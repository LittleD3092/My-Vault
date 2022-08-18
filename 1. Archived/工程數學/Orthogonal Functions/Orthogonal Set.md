標籤: #工程數學 

---

有一組 functions

$$\phi_0(x), \ \phi_1(x), \ \phi_2(x), \ \phi_3(x) \dots$$

$$\text{ 若 } \int_a^b \phi_m(x)\phi_n^*(x)dx = 0 \qquad \text{ for } m \neq n$$

(彼此 [[Orthogonal]])

$$\text{ 則 } \phi_0(x), \phi_1(x), \phi_2(x), \phi_3(x) \dots \text{ 被稱作 orthogonal set on interval } [a, b]$$

# 例子

> Show that the set $\{ 1, \cos x, \cos 2x, \cos 3x, \dots \}$ is an orthogonal set on the interval $[-\pi, \pi]$

when one of the function is $1$

$$\int_{ -\pi }^{ \pi }1 \cdot \cos nx dx = \left. \frac{ 1 }{ n }\sin nx \right\vert_{ -\pi }^{ \pi } = 0$$

when both the two functions are not $1$

$$\int_{ -\pi }^{ \pi }\cos mx \cos nx dx$$

$$ = \int_{ -\pi }^{ \pi }\frac{ 1 }{ 2 }(\cos(m + n)x + \cos(m - n)x)dx$$

$$ = \left. \frac{ \sin(m + n)x }{ 2(m + n) } \right\vert_{ -\pi }^{ \pi } + \left. \frac{ \sin(m - n)x }{ 2(m - n) } \right\vert_{ -\pi }^{ \pi }$$

$$ = \frac{ \sin((m + n)\pi) }{ 2(m + n) } - \frac{ \sin(-( m + n )\pi) }{ 2(m + n) } + \frac{ \sin((m - n)\pi) }{ 2(m - n) } - \frac{ \sin(-(m - n)\pi) }{ 2(m - n) }$$

$$ = 0 \qquad (\because 
\begin{array}{}
	m + n \\
	m - n
\end{array}
\text{ 必為整數 , }
\begin{array}{}
	\sin(m + n)\pi \\
	\sin(m - n)\pi
\end{array}
 = 0)$$

---

參考資料:

微分方程OCW class 24

---

link:

