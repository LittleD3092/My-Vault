標籤: #工程數學 

---

# Unit [[Impulse]]

$$
\delta_a(t - t_0) = 
\left\{
	\begin{array}{l}
		0 & \text{ for } & t < t_0 - a \quad \text{ or } \quad t > t_0 + a \\
		\frac{ 1 }{ 2a } & \text{ for } & t_0 - a \leq t \leq t_0 + a
	\end{array}
\right.
$$

![[Unit Pulse.png]]

因為這個的面積會 $=1$ ，所以稱作 Unit Pulse

# Dirac Delta Function

> 也稱為 Delta Function, [[Impulse]] Function, 或 Unit [[Impulse]] Function

$$\delta(t - t_0) = \lim_{ a \rightarrow 0 } \delta_a( t - t_0 )$$

在 $a \rightarrow 0$ 時，寬度會越來越小，高度會越來越高

$$
\delta_a(t - t_0) = 
\left\{
	\begin{array}{}
		\infty & \text{ for } & t = t_0 \\
		0 & \text{ for } & t \neq t_0
	\end{array}
\right.
$$

![[Direc Delta Funciton.png]]

其中，下式就是 Direc Delta Function。這個也就是 [[Step Function]] 的微分。

$$\lim_{ a \rightarrow 0 } \delta_a( t - t_0 )$$

## Properties

### Integration

$$\int_{ -\infty }^{ \infty }\delta(t - t_0)dt = 1$$

### Sifting

$$\int_p^q f(t)\delta(t - t_0)dt = f(t_0) \quad \text{ when } t_0 \in [p, q]$$

Proof:
$$\int_p^q f(t)\delta(t - t_0)dt = \lim_{ a \rightarrow 0 }\int_p^q f(t)\delta_a(t - t_0)dt$$

$$\cong f(t_0) \lim_{ a \rightarrow 0 }\int_p^q \delta_a(t - t_0)dt = f(t_0)$$

當 $a$ 很小的時候，$f(t) = f(t_0) \quad \text{ for } t_0 - a \leq t \leq t_0 + a$

### [[Laplace Transform]] of $\delta(t - t_0)$

$$\mathcal{ L }\{ \delta(t - t_0) \} = e^{ -t_0s } \qquad \text{ when } t_0 > 0$$

Proof:

> 第一種解法:
> 
> $$\mathcal{ L }(u(t - t_0)) = \frac{ e^{ -st_0 } }{ s }$$
> 
> $$\delta(t - t_0) = u'(t - t_0)$$
> 
> $$\therefore L( \delta(t - t_0) ) = s( \frac{ e^{ -st_0 } }{ s } ) = e^{ -st_0 }$$

> 第二種解法:
> 
> $$\int_0^\infty e^{ -st }\delta (t - t_0)dt$$
> from [[#Sifting]] property
> $$L\{ \delta(t - t_0) \} = e^{ -t_0s }$$

### Relation with the unit step function

$$\int_{ -\infty }^t \delta(\tau - t_0)d\tau = u(t - t_0)$$

$$\frac{ d }{ dt }u(t - t_0) = \delta( \tau - t_0 )$$

### [[Convolution]]

> $$
> \begin{array}{}
> 	f(t) * \delta(t) = f(t) \\ \\
> 	\downarrow \text{ Laplace } \\ \\
> 	F(s) \cdot 1 = F(s)
> \end{array}
> $$

> $$
> \begin{array}{}
> 	f(t) * \delta(t - t_0) & = & f(t - t_0)u(t - t_0) \\ \\
> 	\downarrow \text{ Laplace } \\ \\
> 	F(s)e^{ -st_0 }
> \end{array}
> $$

## 注意

Direc Delta Function 不是 [[piecewise continuous]]

---

參考資料:

[工程數學 第23講、Sections 7-5 and 7-6 The Dirac Delta Function and Systems of Linear DEs](https://youtu.be/clnW8db1WaQ)

---

link:

[[Laplace Transform]]