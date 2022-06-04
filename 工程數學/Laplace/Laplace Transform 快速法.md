標籤: #工程數學 

---

$$L\{y''(t) - 3y'(t) + 2y(t)\} = L\{e^{-4t}\} \qquad \begin{array}{l} y(0) = 1 \\ y'(0) = 5 \end{array}$$

> 矩形計算
> $$\begin{array}{rrr} & s & 1 \\ \times 1 \quad & 1 & 5 \\ \times(-3) \quad & & 1 \end{array} = \underline{\begin{array}{rrrr} & s & + & 5 \\ +) & & - & 3\end{array}} = s + 2$$

$$\implies \underbrace{(s^2 - 3s + 2)}_{\text{auxiliary}}Y(s) = \underbrace{s + 2}_{\text{from 矩形計算}} + \underbrace{\frac{1}{s + 4}}_{\text{from} \; L\{ e^{-4t} \}}$$



---

參考資料:

[工數OCW - Class 21 - youtube](https://youtu.be/0sAa2XUDXMs)
[[Auxiliary Function]]
[[Laplace Transform 解法]]