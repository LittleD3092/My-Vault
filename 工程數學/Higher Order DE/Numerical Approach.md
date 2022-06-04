標籤: #工程數學 

---

$$\frac{d^2y}{dx^2} = f(x, y, y')$$
$$y(x_0) = y_0$$
$$y'(x_0) = u_0$$

解法
$$\left\{ 
	\begin{array}{}
		y' = u \\
		u' = f(x, y, u)
	\end{array}
\right.$$
$$y(x_0) = y_0, \; u(x_0) = u_0$$
.
使用 Euler's Method
$$y(x_{n + 1}) = y(x_n) + (x_{n + 1} - x_n)y'(x_n)$$
$$y(x_{n + 1}) = y(x_n) + 
                 (x_{n + 1} - x_n)u(x_n)$$
$$\begin{array}{rl}
u(x_{n + 1}) & = u(x_n) + 
                 (x_{n + 1} - 
				  x_n) u'(x_n) \\
			 & = u(x_n) + 
			     (x_{n + 1} - x_n)
				 f(x_n, y(x_n), u(x_n))
\end{array}$$
.
Recursive 的解法
.
1. Initial condition:
$$y(x_0) = y_0,\; u(x_0) = u_0$$
.
2. 算 $y$
$$y(x_{n + 1}) = y(x_n) + 
                 (x_{n + 1} - x_n)u(x_n)$$
.
3. 算 $u$
$$u(x_{n + 1}) = u(x_n) + 
                 (x_{n + 1} - x_n)
				 f(x_n, y(x_n), u(x_n))$$
4. 把 $n = n + 1$ 代入第二步，算下一個

---

參考資料:

[Systems of Linear DEs; Nonlinear DEs](https://youtu.be/4g4Jft-3LCU)

[[Higher Order DE解法]]