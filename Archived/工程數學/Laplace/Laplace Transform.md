標籤: #工程數學 

---

Laplace Transform of $f(t)$

$$F(s) = \mathcal{L}\{f(t)\} = \int_0^\infty e^{-st}f(t)dt$$

通常用大寫來代表 transform 的結果，也就是上式的 $F(s)$

$s$ 可以是任何複數 $s = \mu + j\omega$

Laplace Transform 是一種 [[Integral Transform]]

# 拉普拉斯轉換表

## 一般式子的轉換

底下這個東西要背起來

| $$f(t)$$      | $$F(s)$$                 | 算法                                   |
| ------------- | ------------------------ | -------------------------------------- |
| $$1$$         | $$\frac{1}{s}$$          | [[#L 1 frac 1 s \| link (1)]]          |
| $$t^n$$       | $$\frac{n!}{s^{n + 1}}$$ | [[#mathcal L t frac 1 s 2\| link (t)]] | 
| $$\exp(at)$$  | $$\frac{1}{s - a}$$      |                                        |
| $$\sin(kt)$$  | $$\frac{k}{s^2 + k^2}$$  |                                        |
| $$\cos(kt)$$  | $$\frac{s}{s^2 + k^2}$$  | see [[Table of Integration]]                                       |
| $$\sinh(kt)$$ | $$\frac{k}{s^2 - k^2}$$  |                                        |
| $$\cosh(kt)$$ | $$\frac{s}{s^2 - k^2}$$  |                                        |

### $\mathcal{L}\{1\} = \frac{1}{s}$

$$L\{1\} = \int_0^\infty e^{-st}dt$$
.
$$= \left. -\frac{e^{-st}}{s} \right\vert_0^\infty$$
.
$$= -\frac{e^{-s\cdot\infty}}{s} - (-\frac{e^{-s\cdot 0}}{s})$$
.
$$= \frac{1}{s}$$

> 這裡假設 $s > 0$, 所以
> $$-\frac{e^{-s\cdot \infty}}{s} = 0$$

### $\mathcal{ L }\{t\} = \frac{1}{s^2}$

$$\mathcal{ L }\{t\} = \int_0^\infty te^{-st}dt \qquad 
\begin{array}{}
	u = t & dv = e^{-st}dt \\
	du = dt & v = -\frac{e^{-st}}{s}
\end{array}$$
.
$$= \left. -\frac{te^{-st}}{s} \right\vert_0^\infty + \int_0^\infty\frac{e^{-st}}{s}dt$$
.
$$= -\frac{\infty\cdot e^{-s\cdot\infty}}{s} + 0 - \left.\frac{e^{-st}}{s^2}\right\vert_0^\infty$$
.
$$= -\frac{e^{-s\cdot \infty}}{s^2} + \frac{e^{-s\cdot 0}}{s^2}$$
.
$$= \frac{1}{s^2}$$

## 七大各種微積分轉換

| input                                                                    | Laplace transform                                                                       |
| ------------------------------------------------------------------------ | --------------------------------------------------------------------------------------- |
| Differentiation $$f^{(n)}(t)$$                                           | $$s^nF(s) - s^{n - 1}f(0) - s^{n - 2}f'(0) - \dots - sf^{(n - 2)}(0) - f^{(n - 1)}(0)$$ |
| [[Derivatives of Transforms\|Multiplication by]] $t$ $$t^nf(t)$$         | $$(-1)^n\frac{d^n}{ds^n}F(s)$$                                                          |
| [[Integration with Laplace\|Integration]] $$\int_0^tf(\tau)d\tau$$       | $$\frac{F(s)}{ds}$$                                                                     |
| Multiplication by exp $$e^{at}f(t)$$                                     | $$F(s - a)$$                                                                            |
| Translation $$f(t - a)u(t - a)$$ $$g(t)u(t - a)$$ $$u(t - a)$$           | $$e^{-as}F(s)$$ $$e^{-as}L\{g(t + a)\}$$ $$\frac{ e^{ as } }{ s }$$                                                |
| [[Convolution Theorem\|Convolution]] $$\int_0^tf(\tau)g(t - \tau)d\tau$$ | $$F(s)G(s)$$                                                                            |
| [[Transform of a Periodic Fuction\|Periodic Input]] $$f(t) = f(t + T)$$  | $$\frac{1}{1 - e^{-st}}\int_0^Te^{-st}f(t)dt$$                                          |

## Properties 補充

| input                                                                                                                                                      | Laplace transform            |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| Scaling $$f(t/a)$$                                                                                                                                         | $$aF(as)$$                   |
| Multiple Integrations $$\int_0^t \int_0^{ \tau_n } \dots \int_0^{ \tau_3 } \int_0^{ \tau_2 } f(\tau_1)d\tau_1 d\tau_2 \dots d\tau_{ n - 1 } d_{ \tau_n }$$ | $$\frac{ F(s) }{ s^n }$$     |
| Integration for $s$ $$f(t) / t$$                                                                                                                           | $$\int_s^\infty F(s_1)ds_1$$ | 

# 特性

## 1. 可以把微分變成乘法

$$\text{可以將}\; \frac{d^k}{dt^k}y(t) \; \text{變成} \; s^kY(s) \underbrace{- s^{k - 1}y(0) - s^{k - 2}y'(0) - ... - sy^{(y - 2)}(0) - y^{(k - 1)}(0)}_{\text{同時考慮 initial conditions}}$$

## 2. 具有 Linear Property (可以乘進括號裡)

拉普拉斯轉換可以直接乘進括號裡

$$\int_0^\infty e^{-st}[\alpha f(t) + \beta g(t)]dt = \alpha \int_0^\infty e^{-st}f(t)dt + \beta\int_0^\infty e^{-st}g(t)dt$$

也就是

$$L\{\alpha f(t) + \beta g(t)\} = \alpha L\{f(t)\} + \beta L\{g(t)\}$$

> 事實上，所有 [[Integral Transform]] 都有這個性質

## 3. 並不是所有情況都可以用 Laplace Transform

> 當以下兩種情況滿足，可以確定 Laplace Transform 存在
> 注意不滿足時，Laplace Transform 不一定存在(但也不一定不存在)
> ### 反例
> $$f(t) = t^{-1/2}$$ 不為 [[piecewise continuous]] ，但是 Laplace Transform 存在
> $$F(s) = s^{-1/2}\sqrt{\pi}$$
> 
> > 算這個會需要用到 [[Gamma Function]]

### constraint 1

對於 $f(t)$ ，必須存在常數 $c$, $M > 0$, $T > 0$ ，滿足下列式子

$$\vert f(t) \vert \leq Me^{ct} \quad \text{for all} \; t > T$$

也就是 $Me^{ct}\; (c > 0)$ 要增加的比 $f(t)$ 快

![[Laplace Transform 存在條件一.png]]

> [[#拉普拉斯轉換表]] 裡面的式子全部滿足 [[#constraint 1]]

#### 不滿足 [[#constraint 1]] 的例子

$$f(t) = \exp(t^2) \quad \text{並不存在}\; c \; \text{使得} \; \vert f(t)\vert \leq Me^{ct} \quad \text{for all } t > T$$

![[不滿足 constraint 1 的例子.png]]

### constraint 2

$f(t)$ 在 $[0, \infty)$ 中必須 [[piecewise continuous]]

# 用 Laplace Transform 解 DE

$$y''(t) - 3y'(t) + 2y(t) = e^{-4t} \qquad \begin{array}{} y(0) = 1 \\ y'(0) = 5 \end{array}$$

## Step 1 auxiliary Laplace

使用 [[Laplace Transform 快速法]]

$$(s^2 - 3s + 2)Y(s) = s + 2 + \frac{1}{s + 4}$$

## Step 2 分解

$$Y(s) = \frac{s + 2}{s^2 - 3s + 2} + \frac{1}{(s^2 - 3s + 2)(s + 4)}$$
$$ = \frac{s + 2}{(s - 1)(s - 2)} + \frac{1}{(s - 1)(s - 2)(s + 4)}$$
$$ = -\frac{3}{s - 1} + \frac{4}{s - 2} - \frac{1}{5}\frac{1}{s - 1} + \frac{1}{6}\frac{1}{s - 2} + \frac{1}{30}\frac{1}{s + 4}$$
$$ = -\frac{16}{5}\frac{1}{s - 1} + \frac{25}{6}\frac{1}{s - 2} + \frac{1}{30}\frac{1}{s + 4}$$

## Step 3 inverse

$$y(t) = -\frac{16}{5}e^t + \frac{25}{6}e^{2t} + \frac{1}{30}e^{-4t}$$

---

參考資料:

[Class 20 - Chapter 7 The Laplace Transform - youtube](https://youtu.be/m60TiMLKzvQ)
[工程數學 class 22 - properties of laplace transform - youtube](https://youtu.be/46CiHQ3EYeY)

[[Laplace Transform 解法]]
[[Inverse Laplace Transform]]
[[Convolution Theorem]]