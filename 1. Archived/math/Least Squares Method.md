標籤: #math 

---

擬合出一條線的方法

# Example

> 有四個數據點
> $$(x, y): (1, 6), (2, 5), (3, 7), (4, 10)$$
> 找出最小平方法的直線

假設直線的方程式為

$$y = mx + b$$

這四個點帶進去會得到

$$
\begin{array}{}
	m & + & b & = & 6 \\
	2m & + & b & = & 5 \\
	3m & + & b & = & 7 \\
	4m & + & b & = & 10
\end{array}
$$

我們希望等號左右兩邊相差值的平方最小，也就是找出以下函數的最小值

$$S(m, b) = [6 - (m + b)]^2 +
[5 - (2m + b)]^2 +
[7 - (3m + b)]^2 +
[10 - (4m + b)]^2$$

於是我們對函式偏微分，求偏微分等於 0 的 $(m, b)$

<br>

$$\frac{ \partial S }{ \partial m } = 0 = 2[6 - (m + b)] \cdot (-1) +$$
$$2[5 - (2m + b)] \cdot (-2) +$$ 
$$2[7 - (3m + b)] \cdot (-3) +$$
$$2[10 - (4m + b)] \cdot (-4)$$

<br>

$$\implies \frac{\partial S}{\partial m} = -154 + 60m + 20b = 0$$

$$\implies \underline{30m + 10b = 77}$$

<br>

$$\frac{ \partial S }{ \partial b } = 0 = 2[6 - (m + b)] \cdot (-1) +$$
$$2[5 - (2m + b)] \cdot (-1) +$$ 
$$2[7 - (3m + b)] \cdot (-1) +$$
$$2[10 - (4m + b)] \cdot (-1)$$

<br>

$$\implies \frac{\partial S}{\partial b} = -56 + 20m + 8b = 0$$

$$\implies \underline{5m + 2b = 14}$$

把上面的兩個方程式解二元一次

$$\implies
\left\{
	\begin{array}{}
		30m & + & 10b & = & 77 \\
		5m & + & 2b & = & 14
	\end{array}
\right.$$

$$\implies 
\left\{
	\begin{array}{}
		m & = & \frac 7 5 \\
		b & = & \frac 7 2
	\end{array}
\right.$$

---

參考資料:

[最小平方法 - wikipedia](https://zh.wikipedia.org/zh-tw/%E6%9C%80%E5%B0%8F%E4%BA%8C%E4%B9%98%E6%B3%95)

---

link:

