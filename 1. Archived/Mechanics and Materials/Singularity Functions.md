標籤: #Mechanics-and-Materials 

---

以下是 Singularity Function 的表示方式

$$<x - x_0>^n$$

# 定義

$$
<x - x_0>^n
\left\{
	\begin{array}{}
		0           & \text{ for } x < x_0 \\
		1           & \text{ for } n = 0 \text{ and } x \geq x_0 \\
		(x - x_0)^n & \text{ for } n \geq 1 \text{ and } x \geq x_0
	\end{array}
\right.
$$

## 微分

$$\frac{ d }{ dx }<x - x_0>^n = n<x - x_0>^{ n - 1 } \qquad \text{ for } n \geq 1$$

## 積分

$$\int <x - x_0>^n dx = \frac{ 1 }{ n + 1 }<x - x_0>^{ n + 1 } + c \qquad \text{ for } n \geq 0$$

# 將力與 moment 用 singularity function 表示

## Generalized

$$F\frac{ <x - x_{ load }>^n }{ n! }$$

$F$: magnitude of the load
$x_{ load }$: where load is applied
$n$: integer which describes the load

## Applied Moment

$$M_a\frac{ <x - a>^0 }{ 0! }$$

## Point Load

$$P_b\frac{ <x - b>^1 }{ 1! }$$

## Distributed load

$$w\frac{ <x - c>^2 }{ 2! }$$

## Ramp Load

$$\frac{\Delta w}{\Delta x}\frac{ <x - d>^3 }{ 3! }$$

Example:

![[ramp load singularity function example.png]]

$$M = \underbrace{ -\frac{ \Delta w }{ \Delta x }\frac{ <x - x_1>^3 }{ 3! } }_{ 1. } + \underbrace{ \frac{ \Delta w }{ \Delta x }\frac{ <x - x_2>^3 }{ 3! } }_{ 2. } + \underbrace{ \Delta w\frac{ <x - x_2>^2 }{ 2! } }_{ 3. }$$

---

參考資料:

coursera mechanics and materials

---

link:

