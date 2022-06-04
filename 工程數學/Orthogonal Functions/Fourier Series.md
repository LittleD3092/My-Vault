標籤: #工程數學 

---

為了將複雜的 $f(x)$ 表示成容易瞭解的型態，我們會使用 Fourier Series 來表示 $f(x)$

要將 $f(x)$ 用 Fourier Series 表示，我們需要 $f(x)$ 是具有週期性的（可以在一些地方未定義，如下圖）

![[function that can be represented by fourier transform.png]]

# Trigonometric Functions

通常我們最常使用 trigonometric function 作為 fourier series 的選擇

$$\{ 1,\  \cos\frac{ \pi }{ p }x,\  \cos \frac{ 2\pi }{ p }x,\  \cos\frac{ 3\pi }{ p }x,\  \dots,\  \sin\frac{ \pi }{ p }x,\  \sin\frac{ 2\pi }{ p }x,\  \sin\frac{ 3\pi }{ p }x,\  \dots \}$$

$$f(x) \cong \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos\frac{ n\pi }{ p }x + b_n\sin\frac{ n\pi }{ p }x \right)$$

- [[Orthogonal Set]] on the interval of $[-p, \ p]$
- [[Complete]]
- 測量頻率的工具

## 證明為 [[Orthogonal Set]]

要證明是否是 [[Orthogonal Set]] ，需要將 $1$, $\cos$, $\sin$ 互相算出為 [[Orthogonal]]

(1) $1$ v.s. $\cos$

$$\int_{ -p }^{ p } 1\cdot \cos\frac{ \pi k }{ p }xdx$$

$$ = \left. \frac{ p }{ \pi k }\sin\frac{ \pi k }{ p }x \right\vert_{ -p }^{ p }$$

$$ = \frac{ p }{ \pi k }\sin\pi k - \frac{ p }{ \pi k }\sin(-\pi k)$$

$$ = 0$$

(2) $1$ v.s. $\sin$

$$\int_{ -p }^{ p } 1 \cdot \sin\frac{ \pi k }{ p }xdx$$

$$ = \left. -\frac{ p }{ \pi k }\cos\frac{ \pi k }{ p }x \right\vert_{ -p }^{ p }$$

$$ = -\frac{ p }{ \pi k }\cos \pi k + \frac{ p }{ \pi k } \cos (-\pi k)$$

$$ = 0$$

$1$ 是 even function, $\sin$ 是 odd function, 兩個一定 [[Orthogonal]]

(3) $\cos$ v.s. $\sin$

$$\int_{ -p }^{ p } \cos\frac{ \pi k }{ p }x\cdot \sin\frac{ \pi h }{ p }xdx$$

$$ = \int_{ -p }^{ p }\frac{ 1 }{ 2 }
\left[
\sin\frac{ \pi(h + k) }{ p }x - \sin\frac{ \pi (h - k) }{ p }x
\right]dx$$

$$
= \left. \frac{ p }{ 2\pi }
\left[
	-\frac{ 1 }{ h + k }
	\cos
	\left(
		\frac{ \pi(h + k)x }{ p }
	\right) + 
	\frac{ 1 }{ h - k }\cos
	\left(
		\frac{ \pi(h - k)x }{ p }
	\right)
\right] \right\vert_{ -p }^{ p }
$$

$$
= 
\frac{ p }{ 2\pi }
\left[
-\frac{ 1 }{ h + k }
\left[
\cos(\pi(h + k)) - \cos(-\pi(h + k))
\right] + \frac{ 1 }{ h - k }
\left[
\cos(\pi(h - k)) - \cos(-\pi(h - k))
\right]
\right]
$$

$$ = 0 \qquad (\text{ when } h \neq k)$$

$$\text{ when } h = k$$

$$\int_{ -p }^{ p }\cos\frac{ \pi k }{ p }x\cdot \sin\frac{ \pi h }{ p }xdx$$

$$ = \int_{ -p }^{ p }\frac{ 1 }{ 2 }\sin\frac{ 2\pi k }{ p }xdx$$

$$ = \left. -\frac{ p }{ 4\pi k }\cos\frac{ 2\pi k }{ p } \right\vert_{ -p }^{ p }$$

$$ = 0$$

$\cos$ 是 even function, $\sin$ 是 odd function, 兩者一定 [[Orthogonal]]

(4) $\cos$ v.s. $\cos$, $k \neq h$

$$\int_{ -p }^{ p }\cos\frac{ \pi k }{ p }x\cdot \cos\frac{ \pi h }{ p }xdx$$

$$ = \int_{ -p }^{ p }\frac{ 1 }{ 2 }\left[ \cos\frac{ \pi(h + k) }{ p }x + \cos\frac{ \pi(h - k) }{ p }x \right]dx$$

$$ = \left. \frac{ p }{ 2\pi }\left[ \frac{ 1 }{ h + k }\sin\left( \frac{ \pi(h + k)x }{ p } \right) + \frac{ 1 }{ h - k }\sin\left( \frac{ \pi(h - k)x }{ p } \right) \right] \right\vert_{ -p }^{ p }$$

$$ = \frac{ p }{ 2\pi }\left[ \frac{ 1 }{ h + k }[\sin(\pi(h + k)) - \sin(-\pi(h + k))] + \frac{ 1 }{ h + k }[\sin(\pi(h - k)) - \sin(-\pi(h - k))] \right]$$

$$ = 0 \qquad \text{ when } h \neq k $$

(5) $\sin$ v.s. $\sin$, $k \neq h$

$$\int_{ -p }^{ p }\sin\frac{ \pi k }{ p }x \cdot \sin\frac{ \pi h }{ p }xdx$$

$$ = \int_{ -p }^{ p }\frac{ 1 }{ 2 }\left[ \cos\frac{ \pi(h - k) }{ p }x - \cos\frac{ \pi(h + k) }{ p }x \right]dx$$

$$ = \left. \frac{ p }{ 2\pi }\left[ \frac{ 1 }{ h - k }\sin\left( \frac{ \pi(h - k)x }{ p } \right) - \frac{ 1 }{ h + k }\sin\left( \frac{ \pi(h + k)x }{ p } \right) \right] \right\vert_{ -p }^{ p }$$
  
$$ = 0 \qquad (\text{ when } h \neq k )$$

## Fourier Series

$$\underline{f(x) \cong \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos\frac{ n\pi }{ p }x + b_n\sin\frac{ n\pi }{ p }x \right)}_\#$$

$$\underline{a_0 = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)dx}_\#$$

$$\underline{a_n = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)\cos\frac{ n\pi }{ p }xdx}_\#$$

$$\underline{b_n = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)\sin\frac{ n\pi }{ p }xdx}_\#$$

上述的 $f(x)$ 是近似，原因是 [[#Condition for Converge]] , [[#Period Extension]]

### Coefficients

#### Constant Offset Coefficient $a_0$

To filter for $a_0$ in $f(x)$, we can integrate the fourier series

$$\int_{ -\pi }^\pi f(x)dx = \int_{ -\pi }^{ \pi }\left[a_0 + \sum_{ n = 1 }^\infty (a_n \cos nx + b_n \sin nx)\right]dx$$

$$ = a_0\int_{ -\pi }^\pi dx + \sum_{ n = 1 }^{ \infty }
\left(a_n \int_{ -\pi }^\pi \cos nx dx + 
b_n \int_{ -\pi }^\pi\sin nx dx\right)$$

$$ = 2\pi a_0 + \underbrace{ 0 + 0 }_{ \text{ since all terms have period of  }2 \pi }$$

$$\therefore a_0 = \frac 1 {2\pi} \int_{ -\pi }^\pi f(x)dx$$

#### Cosine Coefficients $a_1, a_2, \dots, a_n$

we make use of the property of orthogonality

$$\int_{ -\pi }^\pi f(x)\cos mxdx = \int_{ -\pi }^\pi \left[ a_0 + \sum_{ n = 1 }^\infty(a_n \cos nx + b_n \sin nx) \right]\cos mx dx$$

due to orthogonality, all terms where $n \neq m \rightarrow 0$

$$\int_{ -\pi }^\pi f(x)\cos mx dx = \int_{ -\pi }^\pi a_m \cos^2 mx dx$$

$$ = \left[ 
	\frac 1 2 a_m x + \frac{ 1 }{ 4m } \sin 2mx
\right]_{x = -\pi}^\pi$$

$$ = a_m \pi$$

$$\therefore a_m = \frac 1 \pi \int_{ -\pi }^\pi f(x)\cos mx dx$$

#### Sine Coefficients $b_1, b_2, \dots, b_n$

we make use of the property of orthogonality

$$\int_{ -\pi }^\pi f(x)\sin mxdx = 
\int_{ -\pi }^\pi \left[ 
	a_0 + \sum_{ n = 1 }^\infty(a_n \cos nx + b_n \sin nx) 
\right]\sin mx dx$$

due to orthogonality, all terms where $n \neq m \rightarrow 0$

$$\int_{ -\pi }^\pi f(x)\sin mx dx = 
\int_{ -\pi }^\pi a_m \sin^2 mx dx$$

$$ = \left[ 
	\frac 1 2 b_m x - \frac{ 1 }{ 4m } \sin 2mx
\right]_{x = -\pi}^\pi$$

$$ = b_m \pi$$

$$\therefore b_m = 
\frac 1 \pi \int_{ -\pi }^\pi f(x)\sin mx dx$$

## 頻率與週期

對於每個 $\cos\frac{ n\pi }{ p }x$
週期: $\frac{ 2p }{ n }$
頻率: $\frac{ n }{ 2p }$

## 例題

> $$f(x) = \left\{ \begin{array}{} 0 & \text{ for } & -\pi < x < 0 \\ \pi - x & \text{ for } & 0 \leq x < \pi \end{array} \right.$$

$p = \pi$ 帶入公式

$$a_0 = \frac{ 1 }{ \pi }\int_{ -\pi }^{ \pi }f(x)dx$$

$$ = \frac{ 1 }{ \pi }(\pi - x)dx = \frac{ \pi }{ 2 }$$

$$a_n = \frac{ 1 }{ \pi }\int_{ -\pi }^{ \pi }f(x)\cos nxdx$$

$$ = \frac{ 1 }{ \pi }\int_0^\pi (\pi - x)\cos nx dx$$

$$ = \left. \frac{ \pi - x }{ \pi }\frac{ 1 }{ n }\sin nx \right\vert_{ 
0 }^{ \pi } - \frac{ 1 }{ \pi }\int_0^\pi (-1)\frac{ 1 }{ n }\sin nx dx$$

$$ = \left.-\frac{ 1 }{ n^2\pi }\cos nx \right\vert_0^\pi$$

$$ = \frac{ 1 - \cos n\pi }{ n^2\pi } \qquad (\cos n\pi = (-1)^n)$$

$$ = \frac{ 1 - (-1)^n }{ n^2 \pi }$$

$$b_n = \frac{ 1 }{ \pi }\int_{ -\pi }^{ \pi }f(x)\sin nxdx$$

$$ = \frac{ 1 }{ \pi }\int_0^\pi (\pi - x)\sin nxdx$$

$$ = \left. \frac{ \pi - x }{ \pi }\frac{ 1 }{ n }\cos nx \right\vert_0^\pi - \frac{ 1 }{ \pi }\int_0^\pi(-1)(-\frac{ 1 }{ n }\cos nx)dx$$

$$ = \frac{ 1 }{ n } - \left. \frac{ 1 }{ n^2\pi }\sin nx \right\vert_0^\pi$$

$$ = \frac{ 1 }{ n }$$

$$f(x) = \frac{ \pi }{ 4 } + \sum_{ n = 1 }^{ \infty }\left( \frac{ 1 - (-1)^n }{ n^2\pi }\cos\frac{ n\pi }{ p }x + \frac{ 1 }{ n }\sin\frac{ n\pi }{ p }x \right)$$

## Condition for Converge

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos\frac{ n\pi }{ p }x + b_n\sin\frac{ n\pi }{ p }x \right) \qquad \text{ 其實未必成立 }$$

$$a_0 = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)dx$$

$$a_n = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)\cos\frac{ n\pi }{ p }xdx$$

$$b_n = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)\sin\frac{ n\pi }{ p }xdx$$

若 $f_1(x)$ 為依上述方法轉換結果
$f(x)$ 為原式

1. $f_1(x_0) = f(x_0) \qquad \text{ if } f(x) \text{ is continuous at } x_0$ 
2. $f_1(x_0) = \frac{ f(x_{ 0+ }) + f(x_{ 0- }) }{ 2 } \text{ if } f(x) \text{ is not continuous at } x_0$
$f(x_{ 0+ })$: 趨近 $x_0$ 但大於 $x_0$ 的 $f(x)$
$f(x_{ 0- })$: 趨近 $x_0$ 但小於 $x_0$ 的 $f(x)$

## Period Extension

若 $f_1(x)$ 是週期為 $2\pi$ 的函式

$$f_1(x + 2p) = f_1(x)$$

因此對一個非週期的函式， Fourier Series Expansion 的結果不適用於 $x \notin [-p, p]$ 的區域。但是週期函式則可以。

### 證明

$$f_1(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( a_n\cos\frac{ n\pi }{ p }x + b_n\sin\frac{ n\pi }{ p }x  \right) \qquad \text{ fundamental period: } 2p$$

在 interval $x \in [-p, p]$ 以外的地方

$$f_1(x + 2p) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos(\frac{ n\pi }{ p }x + 2n\pi) + b_n\sin( \frac{ n\pi }{ p }x + 2n\pi ) \right)$$

$$\underline{ f_1(x + 2p) = f(x) }_{ \# }$$

# Fourier Cosine and Sine Functions

與 [[#Trigonometric Functions]] 很像，只是限制 $f(x)$ 必須為 odd / even functions ，這樣可以少算 $a_1, a_2, \dots, a_n$ 或 $b_1, b_2, \dots, b_n$ 其中一種

如果 $f(x)$ 是 even function ，就要使用 [[#Fourier Cosine Series]]

如果是 odd function ，就要使用 [[#Fourier Sine Series]]

## Fourier Cosine Series

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }a_n\cos\frac{ n\pi }{ p }x$$

$$a_0 = \frac{ 2 }{ p }\int_0^p f(x)dx$$

$$a_n = \frac{ 2 }{ p }\int_0^p f(x)\cos\frac{ n\pi }{ p }xdx$$

### 差異

1. 少了 $\sin$
2. $\int_{ -p }^{ p } \rightarrow \int_0^p$
3. $\frac{ 1 }{ p } \rightarrow \frac{ 2 }{ p }$

因為是 even function ，因此可以縮小積分範圍，然後 $\times 2$

## Fourier Sine Series

$$f(x) = \sum_{ n = 1 }^{ \infty }b_n\sin\frac{ n\pi }{ p }x$$

$$b_n = \frac{ 2 }{ p }\int_0^p f(x)\sin\frac{ n\pi }{ p }xdx$$

### 差異

1. 少了 $1, \cos$
2. $\int_{ -p }^{ p } \rightarrow \int_0^p$
3. $\frac{ 1 }{ p } \rightarrow \frac{ 2 }{ p }$

因為 odd funciton 和 odd function 相乘是 even function ，因此可以縮小積分範圍，然後 $\times 2$

## 例題

> Expand $$f(x) = x, \quad -2 < x < 2$$ in a fourier series

$f(x)$ is odd
$\therefore$ expand $f(x)$ by a sine series

$$b_n = \frac{ 2 }{ 2 }\int_0^2 x\sin\frac{ nx }{ 2 }xdx$$

$$ = \left. -\frac{ 2 }{ n\pi }x\cos\frac{ n\pi }{ 2 }x \right\vert_0^2 + \frac{ 2 }{ n\pi }\int_0^2\cos\frac{ n\pi }{ 2 }xdx$$

$$ = -\frac{ 2 }{ n\pi }2\cos n\pi + 0 + \left. \frac{ 4 }{ n^2\pi^2 }\sin\frac{ n\pi }{ 2 }x \right\vert_0^2$$

$$ = -\frac{ 4 }{ n\pi }(-1)^n + 0 - 0$$

$$ = \frac{ 4 }{ n\pi }(-1)^{ n + 1 }$$

$$f(x) = \sum_{ n = 1 }^{ \infty } \frac{ 4(-1)^{ n + 1 } }{ n\pi }\sin\frac{ n \pi }{ 2 }x$$

# Half-range Expansion

若 function 只有一邊，如 $f(x) = x^2, \ 0 < x < L$ 只有正的地方有定義，但我們還是想要把它用 fourier series 表示的話可以使用 half-range expansion ，這會假設 $f(x)$ 是一個週期性的函數

> 如果我們沒辦法假設 $f(x)$ 是週期性的函數，就需要其他方法
> [[Fourier Integral]]

## (a) in a cosine series

假設 $f(x) = f(-x) \qquad \text{ for }\  -L < x < 0 \qquad$ (假設 $f(x)$ 是一個 even function)

原本的 [[#Fourier Cosine Series]] 公式

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }a_n\cos\frac{ n\pi }{ p }x$$

$$a_0 = \frac{ 2 }{ p }\int_0^p f(x)dx$$

$$a_n = \frac{ 2 }{ p }\int_0^p f(x)\cos\frac{ n\pi }{ p }xdx$$

將 $p$ 改成 $L$

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }a_n\cos\frac{ n\pi }{ L }x$$

$$a_0 = \frac{ 2 }{ L }\int_0^L f(x)dx$$

$$a_n = \frac{ 2 }{ L }\int_0^L f(x)\cos\frac{ n\pi }{ L }xdx$$

1. interval: $[-L, L]$
2. 所有公式的 $p$ 由 $L$ 取代
3. 結果是 even

## (b) in a sine series

和 [[#a in a cosine series]] 處理方法相似，但是假設 $f(x)$ 是 odd function

$$f(x) = \sum_{ n = 1 }^{ \infty }b_n\sin\frac{ n\pi }{ L }x$$

$$b_n = \frac{ 2 }{ L }\int_0^L f(x)\sin\frac{ n\pi }{ L }xdx$$

1. interval: $[-L, L]$
2. 所有公式的 $p$ 由 $L$ 取代
3. 結果為 odd

## (c) in a fourier series

和 [[#Trigonometric Functions]] 不同的是，週期從 $L$ 改為 $2L$

[[#Fourier Series|原本的公式]]:

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos\frac{ n\pi }{ p }x + b_n\sin\frac{ n\pi }{ p }x \right)$$

$$a_0 = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)dx$$

$$a_n = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)\cos\frac{ n\pi }{ p }xdx$$

$$b_n = \frac{ 1 }{ p }\int_{ -p }^{ p }f(x)\sin\frac{ n\pi }{ p }xdx$$

將 $p$ 由 $\frac{ L }{ 2 }$ 取代:

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos\frac{ 2n\pi }{ L }x + b_n\sin\frac{ 2n\pi }{ L }x \right)$$

$$a_0 = \frac{ 2 }{ L }\int_{ 0 }^{ L }f(x)dx$$

$$a_n = \frac{ 2 }{ L }\int_{ 0 }^{ L }f(x)\cos\frac{ 2n\pi }{ L }xdx$$

$$b_n = \frac{ 2 }{ L }\int_{ 0 }^{ L }f(x)\sin\frac{ 2n\pi }{ L }xdx$$

注意積分的範圍 $0 \sim L$ ，不是 $-\frac{ L }{ 2 } \sim \frac{ L }{ 2 }$

1. interval $[-L, L]$
2. 所有公式的 $p$ 由 $\frac{ L }{ 2 }$ 取代

## 三個結果比較

$$f(x) = x^2,\qquad 0 < x < L$$

### cosine series

![[cosine series half range expansion.png]]

### sine series

![[sine series half range expansion.png]]

### fourier series

![[fourier series half range expansion.png]]

# Solving Particular Solution

我們可以使用 fourier series 來解 [[Differential Equation]] 的 particular solution

$$a_ny^{ (n) }(t) + a_{ n - 1 }y^{ (n - 1) }(t) + \dots + a_1y'(t) + a_0y(t) = f(t)$$

## 限制

$$f(t) = f(t + 2p)$$

## 步驟

- 以下步驟不包含解 homogeneous solution ，若要解的話還是需要 [[Higher Order DE解法]]

### step 1

將 $f(t)$ 表示成 [[#Fourier Series]]

$$f(x) = \frac{ a_0 }{ 2 } + \sum_{ n = 1 }^{ \infty }\left( 
a_n\cos\frac{ n\pi }{ p }t + b_n\sin\frac{ n\pi }{ p }t \right)$$

或 [[#cosine series]] (當 $f(t)$ 為 even)
或 [[#sine series]] (當 $f(t)$ 為 odd)

### step 2

假設 particular solution 的型態為

$$y_p(t) = A_0 + \sum_{ n = 1 }^{ \infty }\left( A_n\cos\frac{ n\pi }{ p }t + B_n\sin\frac{ n\pi }{ p }t \right)$$

### step 3

代回原式，比較係數，將 $A_0, A_n, B_n$ 解出來

若所假設的 particular solution 和 homogeneous solution 有相同的地方，則要乘上 $t$

## 例題

$$\frac{ 1 }{ 16 }\frac{ d^2 x }{ dt^2 } + 4x = f(t)$$

$$f(t) = \pi t \qquad \text{ for } -1 < t < 1$$

$$f(t) = f(t - 2)$$

### step 1

假設 
$$f(t) = \sum_{ n = 1 }^{ \infty } b_n\sin n\pi t$$
(因為 $f(t)$ 是 odd)

$$b_n = 2\int_0^1\pi t\sin(n\pi t)dt$$

$$ = \left. -2\frac{ t }{ n }\cos(n\pi t) \right\vert_0^1 + \int_0^1\frac{ 2 }{ n }\cos(n\pi t)dt$$

$$ = -2\frac{ 1 }{ n }(-1)^n - 0 + \left. \frac{ 2 }{ n^2\pi }\sin(n\pi t)\right\vert_0^1$$

$$ = \frac{ 2 }{ n }(-1)^{ n + 1 }$$

$$f(t) = \sum_{ n = 1 }^\infty \frac{ 2 }{ n }(-1)^{ n + 1 }\sin(n\pi t)$$

### step 2

假設 particular solution 為

$$x_p(t) = \sum_{ n = 1 }^\infty(A_n\cos n\pi t + B_n\sin n\pi t) \qquad (p = 1)$$

### step 3

將 $x_p(t)$ 和 [[#step 1]] 的結果代入

$$\frac{ 1 }{ 16 }\frac{ d^2x }{ dt^2 } + 4x = f(t)$$

$$\implies \sum_{ n = 1 }^{ \infty }\left( -\frac{ 1 }{ 16 }A_n\frac{ n^2\pi^2 }{ 4 }\cos n\pi t - \frac{ 1 }{ 16 }B_n\frac{ n^2\pi }{ p^2 }\sin n\pi t \right) + \sum_{ n = 1 }^\infty (4A_n\cos n\pi t + 4B_n\sin n \pi t) = \sum_{ n = 1 }^\infty\frac{ 2 }{ n }(-1)^{ n + 1 }\sin n\pi t$$

$$\implies \left\{ \begin{array}{l} -\frac{ 1 }{ 16 }A_n\frac{ n^2\pi^2 }{ 4 } & + & 4 A_n & = & 0 \\ -\frac{ 1 }{ 16 }B_n n^2\pi^2 & + & 4B_n & = & \frac{ 2 }{ n }(-1)^{ n + 1 } \end{array}\right.$$

$$\implies \left\{ \begin{array}{l} A_n & = & 0 \\ B_n & = & \frac{ 32(-1)^{ n + 1 } }{ n(64 - n^2\pi^2) } \end{array} \right.$$

$$\implies x_p(t) = \sum_{ n = 1 }^{ \infty }\frac{ 32(-1)^{ n - 1 } }{ 
n(64 - n^2\pi^2) }\sin\frac{ n\pi }{ p }t$$

### General Solution

$$x(t) = c_1 \cos(8t) + c_2\sin(8t) + \sum_{ n = 1 }^\infty \frac{ 32(-1)^{ n - 1 } }{ n(64 - n^2\pi^2) }$$

---

參考資料:

[[微分方程]第25講、Sections 11-2 and 11-3 Fourier Series, Fourier Cosine and Sine Series](https://youtu.be/Yrg5hIHcbn4)
[[微分方程]第26講、Section 11-3 Fourier Cosine and Sine Series](https://youtu.be/l3VGEy4CSms)

---

link:

[[Generalized Fourier Series]]