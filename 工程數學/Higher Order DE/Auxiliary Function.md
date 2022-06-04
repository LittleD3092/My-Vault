標籤: #工程數學

---

可以用來解High Order DE complementary function

# 限制條件

1. Homogeneous
2. Linear
3. Constant Coefficients (常數係數)


# 解法

- 解法核心: Suppose that the solutions has the form of $e^{mx}$

> Example:
> $$y''(x) - 3y'(x) + 2y(x) = 0$$
> $${\rm Set}\; y(x) = e^{mx}, \quad m^2e^{mx} - 3me^{mx} + 2e^{mx} = 0$$
> $$m^2 - 3m + 2 = 0\qquad\qquad {\rm solve}\; m$$
> $$m = 2, 1$$
> $$y_1(x) = e^x \quad y_2(x) = e^{2x}$$

## Three Cases for Roots(2nd Order DE)

### Case 1

$$m_1 \neq m_2, \quad m_1, m_2 \; \text{are real}$$
$$y = c_1e^{m_1x} + c_2e^{m_2x}$$

### Case 2

$$m_1 = m_2 \;(m_1 \, \text{and} \, m_2 \,\text{are of course real})$$
$$y_1 = e^{m_1x}$$
$$y_2(x) = xe^{m_1x}$$
$$y = c_1e^{m_1x} + c_2xe^{m_1x}$$

### Case 3

$$m_1 = \frac{-a_1 + \sqrt{a_1^2 - 4a_2a_0}}{2a_2} = \alpha + j\beta$$
$$m_2 = \alpha - j\beta$$
$$\alpha = -a_1/2a_2,\quad \beta = \sqrt{4a_2a_0 - a_1^2}/2a_2$$

.

$$m_1 \neq m_2 \;(m_1 \, \text{and} \, m_2 \,\text{are conjugate and complex})$$
$$y = C_1e^{\alpha x + j\beta x} + C_2e^{\alpha x - j \beta x}$$
$$y = e^{\alpha x}(c_1 \cos \beta x + c_2 \sin \beta x)$$

> $\alpha$ : m的實部
> $\beta$ : m的虛部


## Three+1 Cases for Roots(Higher Order DE)

### Case 1: 在 $m_q$ 的地方只有一個根

Solution:
$$e^{m_qx}$$

### Case 2: 在 $m_q$ 的地方有 $k$ 個根

Solutions:
$$e^{m_qx}, xe^{m_qx}, x^2e^{m_qx},...,x^{k-1}e^{m_qx}$$

### Case 3: 同時有 $\alpha + j\beta$ 和 $\alpha - j\beta$ 兩個解

Solutions:
$$e^{\alpha x}\cos(\beta x), \; e^{\alpha x}\sin(\beta x)$$

### Case 4: 有 $\alpha + j\beta$ 和 $\alpha - j\beta$ 各 $k$ 個解

Solutions:
$$e^{\alpha x} \cos (\beta x ), x e^{\alpha x}\cos(\beta x), x^2 e^{\alpha x}\cos(\beta x),...,x^{k-1}e^{\alpha x}\cos(\beta x)$$
$$e^{\alpha x} \sin (\beta x ), x e^{\alpha x}\sin(\beta x), x^2 e^{\alpha x}\sin(\beta x),...,x^{k-1}e^{\alpha x}\sin(\beta x)$$

---

[Class 10: Solving the Linear and Constant Coefficient DE](https://youtu.be/4yTXud2Ig88)
[[Higher Order DE解法]]