標籤: #工程數學 

---

解 particular solution

# 限制

1. 線性

> 只有一個限制

# 方法

## 2nd order

已經解出 $y_1$, $y_2$
假設 $u_1(x)$ 和 $u_2(x)$
$$y_p = u_1(x)y_1(x) + u_2(x)y_2(x)$$
.
$$y_p' = u_1'y_1 + u_1y_1' + u_2'y_2 + u_2y_2'$$
$$y_p'' = u_1''y_1 + 2u_1'y_1' + u_1y_1'' + u_2''y_2 + 2u_2'y_2' + u_2y_2''$$
.
$$\text{代入}\; y''(x) + P(x)y'(x) + Q(x)y = f(x)$$
$$P(x) = \frac{a_1(x)}{a_2(x)}, \; Q(x) = \frac{a_0(x)}{a_2(x)}, \; f(x) = \frac{f(x)}{a_2(x)}$$
.
$$y_p'' + P(x)y_p' + Q(x)y_p = u_1\underbrace{\left[y_1'' + Py_1' + Qy_1\right]}_{\text{zero}} + u_2\underbrace{\left[y_2'' + Py_2' + Qy_2\right]}_{\text{zero}} + y_1u_1'' + 2u_1'y_1' + y_2u_2'' + 2u_2'y_2' + P\left[y_1u_1' + y_2u_2'\right]$$
.
簡化
$$\frac{d}{dx}\left[ y_1u_1' + y_2u_2' \right] + P\left[ y_1u_1' + y_2u_2' \right] + y_1'u_1' + y_2'u_2' = f(x)$$
.
進一步簡化(假設$y_1u_1' + y_2u_2' = 0$)
$$y_1'u_1' + y_2'u_2' = f(x)$$
.
聯立方程式
$$\left\{\begin{array}{} y_1u_1' + y_2u_2' = 0 \\ y_1'u_1' + y_2'u_2' = f(x) \end{array} \right.$$
.
$$\implies \begin{array}{} u_1' = \frac{W_1}{W} = -\frac{y_2f(x)}{W} \\ u_2' = \frac{W_2}{W} = \frac{y_1f(x)}{W} \end{array} \implies \begin{array}{} u_1 = \int u_1'(x)dx \\ u_2 = \int u_2'(x)dx \end{array} $$
$$\text{where}\; W = \left\vert \begin{array}{} y_1 & y_2 \\ y_1' & y_2' \end{array} \right\vert \quad W_1 = \left\vert \begin{array}{} 0 & y_2 \\ f(x) & y_2' \end{array} \right\vert \quad W_2 = \left\vert \begin{array}{} y_1 & 0 \\ y_1' & f(x) \end{array} \right\vert$$
$$\vert \; \vert\text{: determinant}$$
.
$$y_p = u_1(x)y_1(x) + u_2(x)y_2(x)$$

## higher order

high order ODE 長這樣
$$a_n(x)y^{ (n) }(x) + a_{ n - 1 }(x)y^{ (n - 1) }(x) + \dots + a_1(x)y'(x) + a_0(x)y = g(x)$$

$$u_k'(x) = \frac{ W_k }{ W }$$

$$W = 
\left\vert
	\begin{array}{}
		y_1 & y_2 & y_3 & \dots & y_n \\
		y_1' & y_2' & y_3' & \dots & y_n' \\
		y_1'' & y_2'' & y_3'' & \dots & y_n'' \\
		\vdots & \vdots & \vdots & \ddots & \vdots \\
		y_1^{(n - 1)} & y_2^{(n - 1)} & y_3^{(n - 1)} & \dots & y_n^{(n - 1)}
	\end{array}
\right\vert$$

$$
W_k = 
\left\vert
	\begin{array}{}
		y_1 & y_2 & \dots & y_{ k - 1 } & 0 & y_{ k + 1 } & \dots & y_n \\
		y_1' & y_2' & \dots & y_{ k - 1 }' & 0 & y_{ k + 1 }' & \dots & y_n' \\
		\vdots & \vdots & \ddots & \vdots & \vdots & \vdots & \ddots & \vdots \\
		y_1^{ (n - 2) } & y_2^{(n - 2)} & \dots & y_{k - 1}^{(n - 2)} & 0 & y_{k + 1}^{(n - 2)} & \dots & y_n^{(n - 2)} \\
		y_1^{ (n - 1) } & y_2^{(n - 1)} & \dots & y_{k - 1}^{(n - 1)} & f(x) & y_{k + 1}^{(n - 1)} & \dots & y_n^{(n - 1)}
	\end{array}
\right\vert
$$

> $$f(x) = \frac{ g(x) }{ a_n(x) }$$

# 例子

## example 1

$$\text{example:}\;y'' - 4y' + 4y = (x + 1)e^{2x}$$
.
$$\text{step 1: solution of} \; y'' - 4y' + 4y = 0 \text{:}$$
$$y_c = c_1e^{2x} + c_2xe^{2x}$$
.
$$\text{step 2-2:}\; y_p = u_1y_1 + u_2y_2, \;
y_1 = e^{2x},\;
y_2 = xe^{2x}$$
$$W = 
\left\vert
	\begin{array}{}
		e^{2x} & xe^{2x} \\
		2e^{2x} & 2xe^{2x} + e^{2x}
	\end{array}
\right\vert
= e^{4x}$$
$$W_1 = 
\left\vert
	\begin{array}{}
		0 & xe^{2x} \\
		(x + 1)e^{2x} & 2xe^{2x} + e^{2x}
	\end{array}
\right\vert = -(x + 1)xe^{4x}$$
$$W_2 = 
\left\vert
	\begin{array}{}
		e^{2x} & 0 \\
		2e^{2x} & (x + 1)e^{2x}
	\end{array} 
\right\vert = (x + 1)e^{4x} = (x + 1)e^{4x}$$
.
$$\text{Step 2-3: } 
u_1' = \frac{W_1}{W} = -x^2 - x \qquad
u_2' = \frac{W_2}{W} = x + 1$$
.
$$\text{Step 2-4: }
u_1 = \int u_1'dx 
    = \int(-x^2 - x)dx 
    = -\frac{1}{3}x^3 - \frac{1}{2}x^2 + c_1$$
$$u_2 = \int u_2'dx
    = \int (x + 1)dx
	= \frac{1}{2}x^2 + x + c_2$$
.
$$\text{Step 2-5: }
y_p = (-\frac{1}{3}x^3 - \frac{1}{2}x^2)e^{2x}
      + (\frac{1}{2}x^2 + x)xe^{2x}
	= (\frac{1}{6}x^3 + \frac{1}{2}x^2)e^{2x}$$
.
$$\text{Step 3: }
y = c_1e^2x + c_2xe^{2x} + 
    (\frac{1}{6}x^3 + \frac{1}{2}x^2)e^{2x}$$

---

參考資料:

[Class 12 - Variation of Parameters and Cauchy-Euler Equation](https://youtu.be/TWnudCfwofE)

[[Higher Order DE解法]]