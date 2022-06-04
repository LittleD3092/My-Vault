標籤: #工程數學 

---

這個方法為假設 solution 為 polynomial 的型態
和 [[Taylor Series]] 和 [[Cauchy-Euler Equation]] 的概念相似

$$y(x) = \sum_{n = 0}^{\infty}c_n(x - x_0)^n$$
上式被稱為 [[power series]] centered at $x_0$

# method 1 Solutions about Ordinary Points

假設解為
$$\sum_{n = 0}^{\infty}c_n(x - x_0)^n$$

## 適用情形

1. Linear
$$a_n(x)y^{(n)} + a_{n - 1}(x)y^{(n - 1)} + ... + a_1(x)y' + a_0(x)y = g(x)$$
2. $x_0$ is not a [[singular point]]
3. It is better that $a_0(x)$, $a_1(x)$, ... , $a_n(x)$, $g(x)$ are all polynomials. (or [[Taylor Series]])

## 解法流程

1. 將 $$y(x) = \sum_{n = 0}^{\infty}c_n(x - x_0)^n$$ 代入
2. 對齊（一律變成 $x^k$ ）
3. 合併
4. 比較係數，將 $c_n$ 之間的關係找出來
5. Obtained independent solution and general solution

## 例子

### Example 5
> $$y'' + xy = 0$$

$$\text{Set }y(x) = \sum_{n = 0}^{\infty}c_nx^n \; \text{since } P(x) = 0 \text{ and } Q(x) = x \text{ are analytic at 0 }$$
.
Step 1
$$y'' + xy = \sum_{n = 2}^{\infty}c_nn(n - 1)x^{n - 2} + x\sum_{n = 0}^{\infty}c_nx^n = 0$$
注意從 $n = 2$ 開始的原因是因為 $n = 0$ 和 $n = 1$ 在微分後都會直接消失
.
Step 2 對齊
$$\sum_{k = 0}^{\infty}c_{k + 2}(k + 2)(k + 1)x^k + \sum_{k = 1}^{\infty}c_{k - 1}x^k = 0$$
.
Step 3 合併
$$2c_2 + \sum_{k = 1}^{\infty}[c_{k + 2}(k + 2)(k + 1) + c_{k - 1}]x^k = 0$$
.
Step 4 比較係數
$$\left\{\begin{array}{l}
2c_2 = 0 \\
c_{k + 2}(k + 2)(k + 1) + c_{k - 1} = 0
\end{array}\right.$$
.
$$\left\{\begin{array}{l}
c_2 = 0 \\
c_{k + 2} = \frac{-c_{k - 1}}{(k + 2)(k + 1)}
\end{array}\right.$$
.
$c_0$, $c_1$ 給定之後
$$k = 1 \qquad c_3 = -\frac{c_0}{2\cdot 3}$$
$$k = 2 \qquad c_4 = -\frac{c_1}{3\cdot 4}$$
$$k = 3 \qquad c_5 = -\frac{c_2}{4\cdot 5} = 0$$
$$\vdots$$
以此類推，所有的 $c_n$ 值都可以算出來(並可以用 $c_0$ 或 $c_1$ 表示)
.
Step 5 求得解
$$y(x) = \sum_{k = 1}^{\infty}c_nx^n = c_0\left[1 - \frac{x^3}{2\cdot 3} + \frac{x^6}{2\cdot 3\cdot 5\cdot 6} - \frac{x^9}{2\cdot 3\cdot 5\cdot 6\cdot 8\cdot 9} + ...\right] + c_1\left[ x - \frac{x^4}{3\cdot 4} + \frac{x^7}{3\cdot 4\cdot 6\cdot 7} - \frac{x^{10}}{3 \cdot 4 \cdot 6 \cdot 7\cdot 9\cdot 10} + ... \right]$$
$$y(x) = c_0y_1(x) + c_1y_2(x)$$
.
$$y_1(x) = 1 + \sum_{k = 1}^{\infty}\frac{(-1)^k}{2\cdot 3 ...(3k - 1)(3k)}x^{3k}$$
$$y_2(x) = 1 + \sum_{k = 1}^{\infty}\frac{(-1)^k}{3\cdot 4 ... (3k)(3k + 1)}x^{3k + 1}$$

# method 2 Solutions about Singular Points

和上面的方法差不多，除了多了 $r$ 次方

$$y^{(n)} + P_{n - 1}(x)y^{(n - 1)} + ... + P_1(x)y' + P_0(x)y = 0$$

假設解為
$$y(x) = \sum_{n = 0}^{\infty}c_n(x - x_0)^{n + r}$$

## 適用情形

1. Linear
2. $(x - x_0)P_{n - 1}(x)$, $(x - x_0)^2P_{n - 2}(x)$, ... , $(x - x_0)^{n - 1}P_1(x)$, $(x - x_0)^nP_0(x)$ analytic at $x_0$
3. Better if $P_0(x)$, $P_1(x)$, ... , $P_{n - 1}(x)$ are polynomials

> 如果第二項條件滿足，那 $x_0$ 就叫做 regular [[singular point]] ，如果不滿足則叫做 irregular [[singular point]]

> ### Frobenius' Theorem
> 若 $x_0$ 是 linear DE 中的一個 regular [[singular point]] 則這個 linear DE 至少有一個解是 $y(x) = \sum_{n = 0}^{\infty} c_n(x - x_0)^{n + r}$ 的型態

## 步驟

### step 1
將 $y(x) = \sum_{n = 0}^{\infty}c_n(x - x_0)^{n + r}$ 代入

### step 2
power 對齊

### step 3
合併

### step 4
算出 r

### step 5
比較係數，將 $c_n$ 之間的關係找出來

### step 6
將 step 4 得出的 $r$ 代入 step 5

### step 7
當
   1. 有重根 或
   2. $r$ 的根之間的差為整數，且從 step 6 得出來的解不為 independent 時

用 $$y_2(x) = y_1(x)\int\frac{e^{-\int P(x)dx}}{{y_1}^2(x)}dx$$ 和長除法找出 $y_2(x)$

## Example 1
題目:
$$3xy'' + y' - y = 0$$
.
Step 1 將 $y(x) = \sum_{n = 0}^{\infty} c_nx^{n + r}$ 代入
$$3\sum_{n = 0}^{\infty}c_n(n + r)(n + r - 1)x^{n + r - 1} + \sum_{n = 0}^{\infty}c_n(n + r)x^{n + r - 1} - \sum_{n = 0}^{\infty}c_nx^{n + r} = 0$$
.
Step 2 Power 對齊
$$3\sum_{k = 0}^{\infty}c_k(k + r)(k + r - 1)x^{k + r - 1} + \sum_{k = 0}^{\infty}c_k(k + r)x^{k + r - 1} - \sum_{k = 1}^{\infty}c_{k - 1}x^{k + r - 1} = 0$$
.
Step 3 合併
$$[3c_0r(r - 1) + c_0r]x^{r - 1} + \sum_{k = 1}^{\infty}[3c_k(k + r)(k + r - 1) + c_k(k + r) - c_{k - 1}]x^{k + r - 1} = 0$$
.
Step 4 算出 r
$$3r(r - 1) + r = 0$$
.
$$3r^2 - 2r = 0$$
.
$$r(3r - 2) = 0$$
.
$$\left\{ \begin{array}{l} r = 0 \quad \text{or} \\ r = 3 \end{array} \right.$$
.
Step 5
$$3c_k(k + r)(k + r - 1) + c_k(k + r) - c_{k - 1} = 0$$
.
$$c_k = \frac{1}{(k + r)(3k + 3r - 2)}c_{k - 1}$$
.
Step 6
$$\text{當} \; r = 0 \qquad c_k = \frac{c_{k - 1}}{k(3k - 2)}$$
$$c_1 = \frac{c_0}{1\cdot 1}$$
$$c_2 = \frac{c_1}{2\cdot 4} = \frac{c_1}{2!1\cdot 4}$$
$$c_3 = \frac{c_2}{3\cdot 7} = \frac{c_0}{3!1\cdot 4\cdot 7}$$
$$c_4 = \frac{c_3}{4\cdot 10} = \frac{c_0}{4!1\cdot 4\cdot 7\cdot 10}$$
$$\vdots$$
$$c_n = \frac{c_0}{n!1\cdot 4\cdot 7 \dots (3n - 2)}$$
.
$$\text{當}\; r = \frac{2}{3} \qquad c_k = \frac{1}{(3k + 2)k}c_{k - 1}$$
$$c_1 = \frac{c_0}{5\cdot 1}$$
$$c_2 = \frac{c_1}{8\cdot 2} = \frac{c_0}{2!5\cdot 8}$$
$$c_3 = \frac{c_2}{11\cdot 3} = \frac{c_0}{3!5\cdot 8\cdot 11}$$
$$c_4 = \frac{c_3}{14\cdot 4} = \frac{c_0}{4!5\cdot 8\cdot 11\cdot 14}$$
$$\vdots$$
$$c_n = \frac{c_0}{n!5\cdot 8\cdot 11\dots(3n + 2)}$$
.
$$\text{Solution:}$$
$$y = c_1y_1 + c_2y_2$$
$$y_1(x) = x^0\left[1 + \sum_{n = 1}^{\infty}\frac{1}{n!1\cdot 4\cdot 7 \dots (3n - 2)}x^n\right]$$
$$y_2(x) = x^{\frac{2}{3}}\left[ 1 + \sum_{n = 1}^{\infty} \frac{1}{n!5\cdot 8\cdot 11\dots (3n + 2)}x^n \right]$$
$$x\in (0, \infty) \qquad \text{(別忘了寫出}\;x\;\text{的範圍)}$$

## Example 2
題目:
$$xy'' + y = 0$$
.
Step 1: 將 $$y(x)=\sum_{n=0}^{\infty}c_nx^{n+r}$$ 代入
$$\sum_{n = 0}^{\infty}c_n(n + r)(n + r - 1)x^{n + r - 1} + \sum_{n = 0}^{\infty}c_nx^{n + r}$$
.
Step 2: 對齊
$$\sum_{n = 0}^{\infty}c_k(k + r)(k + r - 1)x^{k + r - 1} + \sum_{k = 1}^{\infty}c_{k - 1}x^{k + r - 1} = 0$$
.
Step 3: 合併
$$c_0r(r - 1)x^{r - 1} + \sum_{k = 1}^{\infty}[c_k(k + r)(k + r - 1) + c_{k - 1}]x^{k + r - 1}$$
.
Step 4:
$$r(r - 1) = 0$$
$$r = 0 \;\text{or}\; 1$$
.
Step 5:
$$c_k = -\frac{c_{k - 1}}{(k + r)(k + r - 1)}$$
.
Step 6:
$$\text{當}\; r = 1 \qquad c_k = -\frac{c_{k - 1}}{(k + 1)k}$$
$$c_n = (-1)^n\frac{c_0}{(n + 1)!n!}$$
$$y_1(x) = x[1 + \sum_{n = 1}^{\infty}\frac{(-1)^n}{n!(n + 1)!}x^n]$$
$$=x[\sum_{n = 0}^{\infty}\frac{(-1)^n}{n!(n + 1)!}x^n]$$
$$=\sum_{n = 0}^{\infty}\frac{(-1)^n}{n!(n + 1)!}x^{n + 1}$$
.
$$\text{當}\; r = 0\qquad c_k = -\frac{c_{k - 1}}{k(k - 1)}$$
> $k - 1$ 時不能算
> 此時，應該根據 step 3 ，由
> $$c_k(k + r)(k + r - 1) + c_{k - 1} = c_1\cdot 0 + c_0 = 0$$
> ($k = 1$, $r = 0$ 代入)
> $c_0$ 必須 $= 0$, $c_1$ 可為任意值

$$c_2 = -\frac{c_1}{1\cdot 2}$$
$$c_3 = -\frac{c_2}{2\cdot 3} = \frac{c_1}{1\cdot 2\cdot 2\cdot 3}$$
$$\vdots$$
$$c_n = \frac{(-1)^{n - 1}c_1}{(n - 1)!}$$
.
$$y_2(x) = x^0[x + \sum_{n = 2}^{\infty}\frac{(-1)^{n - 1}}{(n - 1)!n!}x^n]$$
.
$$ = \sum_{n = 1}^{\infty}\frac{(-1)^{n - 1}}{(n - 1)!n!}x^n$$
.
$$ = \sum_{m = 0}^{\infty}\frac{(-1)^m}{m!(m + 1)!}x^{m + 1} \qquad (m = n - 1)$$
上面這個解和 $r = 0$ 的解一樣，所以實際上只有解出一個，另一個未知 (not linearly independent)
-> 因此要用 reduction of order 算另一個解
.
$$y_2(x) = y_1(x)\int\frac{e^{-\int P(x)dx}}{{y_1}^2(x)}dx$$
.
$$ = y_1(x)\int \frac{e^{-\int 0dx}}{{y_1}^2(x)}dx$$
.
$$ = y_1(x)\int\frac{dx}{[x - \frac{1}{2}x^2 + \frac{1}{12}x^3 - \frac{1}{144}x^4 + \dots]^2}$$
.
$$ = y_1(x)\int\frac{dx}{[x^2 - x^3 + \frac{5}{12}x^4 - \frac{7}{72}x^5 + \dots]}$$
> by long division
> $$\frac{1}{x^2 - x^3 + \frac{5}{12}x^4 - \frac{7}{72}x^5 + \dots}$$
> .
> $$\begin{array}{lr}
> & 1x^{-2}\ \ 1x^{-1}\ \ \frac{7}{12}x^0\ \ \frac{19}{72}x^1 \ \ \dots\\
> 1 \ \ -1\ \ \frac{5}{12}\ \ -\frac{7}{72} & \overline{)1\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \! } \\
> &\underline{ 1\ \!\ \ \ -1\ \!\ \ \ \ \ \ \ \ \frac{5}{12}\ -\frac{7}{72} \ \ \ \ \ \ \dots }\\
> & 1\ \ \ \!\ -\frac{5}{12} \ \ \ \ \ \ \frac{7}{72}\ \ \ \ \ \ \dots \\
> & \underline{1\ \ \ \ \ -1\ \ \ \ \ \ \ \ \!\!\!\ \frac{5}{12} \ \ \ \ \ \ \dots} \\
> & \frac{7}{12} \ -\frac{23}{12} \ \ \ \ \ \ \dots \\
> & \underline{\frac{7}{12} \ -\frac{7}{12} \ \ \ \ \ \ \dots} \\
> & \frac{19}{72} \ \ \ \ \ \ \dots
> \end{array}$$

$$ = y_1(x)\int \left[ \frac{1}{x^2} + \frac{1}{x} + \frac{7}{12} + \frac{19}{72}x + \dots \right]dx$$
.
$$ = y_1(x)\left[-\frac{1}{x} + \ln x + \frac{7}{12}x + \frac{19}{144}x^2 + \dots\right]$$
.
$$ = y_1(x)\ln x + y_1(x)\left[-\frac{1}{x} + \frac{7}{12}x + \frac{19}{144}x^2 + \dots\right]$$
.
$$ = y_1(x)\ln x + \left[-1 - \frac{1}{2}x + \frac{1}{2}x^2 + \dots\right]$$

---

參考資料:

[Series Solution of Linear Equation - youtube](https://youtu.be/2ARH7cnl2vk)
[Solution about Ordinary Points](https://youtu.be/CLeQRM83n9Y)
[Solution about Singular Points](https://youtu.be/Nw39CK6x5VE)

---

link:

[[Higher Order DE解法]]