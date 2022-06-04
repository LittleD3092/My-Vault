標籤: #工程數學 

---

# Bessel's Equation of Order $v$

$$x^2y'' + xy' + (x^2 - v^2)y = 0$$
$$\text{solution:}\; c_1J_v(x) + c_2Y_v(x)$$
$$\left\{
	\begin{array}{l}
		J_v(x) = \sum_{n = 0}^\infty\frac{(-1)^n}{n!\Gamma(1 + v + n)}(\frac{x}{2})^{2n + v} & \text{first kind bessel function} \\
		Y_v(x) = \frac{\cos v\pi J_v(x) - J_{-v}(x)}{\sin v\pi} & \text{second kind bessel function}
	\end{array}
\right.$$
.
$$\Gamma(x)$$
[[Gamma Function]]

# Modified Bessel Equation of order $v$

$$x^2y'' + xy' - (x^2 + v^2)y = 0$$
$$\text{solution:}\; c_1I_v(x) + c_2K_v(x)$$
其中 $I_v(x) = i^{-v}J_v(ix)$ ，叫做 modified Bessel Function of the first kind of order $v$
.
$$K_v(x) = \frac{\pi}{2}\frac{I_{-v}(x) - I_v(x)}{\sin v\pi} \qquad \text{second kind}$$

# Spherical Bessel Function

$$J_v(x) \qquad \text{當}\; v = \pm\frac{1}{2}, \;\pm\frac{3}{2},\;\pm\frac{5}{2},\;\dots \; \text{時，稱作 Spherical Bessel Function}$$
$$J_{\frac{1}{2}}(x) = \sqrt{\frac{2}{\pi x}}\sin x$$
$$J_{-\frac{1}{2}}(x) = \sqrt{\frac{2}{\pi x}}\cos x$$

---

參考資料:

[Solutions About Singular Points](https://youtu.be/Nw39CK6x5VE)

[[Higher Order DE解法]]