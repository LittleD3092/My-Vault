標籤: #工程數學 

# Limitation

We can express any 1st order DE as
$$M(x, y)dx + N(x, y)dy = 0$$

當下面的式子成立時，可以用 Exact Equations 來解
$$\frac{ \partial }{ \partial y } M(x, y) = 
  \frac{ \partial }{ \partial x } N(x, y)$$

> proof:
> $$\text{If} \quad \frac{ \partial f(x, y) }{ \partial x} = M(x, y) \quad \text{and} \; \frac{ \partial f(x, y) }{ \partial y } = N(x, y),$$
> $$\text{then} \; \frac{ \partial M(x, y)}{ \partial y } = \frac{ \partial }{ \partial y } \frac{ \partial }{ \partial x }f(x, y) = \frac{ \partial }{ \partial x } \frac{ \partial }{ \partial y }f(x, y) = \frac{ \partial N(x, y) }{ \partial x }$$






# Method

## 步驟解

$$\text{Previous Step: Check whether}\; \frac{\partial M(x, y)}{\partial y} = \frac{\partial N(x, y)}{\partial x} \; \text{is satisfied}$$
.
$$\text{Step 1: Solve }\frac{\partial f(x, y)}{\partial x} = M(x, y) \implies f(x,y) = \int M(x, y)dx+g(y)$$
.
$$\text{Step 2: 將 }f(x,y)\text{ 代入 }\frac{\partial f(x,y)}{\partial y} = N(x,y)\text{以解出 }g(y)$$
.
$$\text{Step 3: Substitude }g(y) \text{ into}$$
$$f(x,y) = \int M(x,y)dx + g(y) = c$$
.
$$\text{Step 4: Further computation and obtain the solution}$$
.
$$\text{Extra Steps: (a)Consider the initial value problem}$$

> 這是下面圖解的解法A

## 圖解

解法A

![[螢幕擷取畫面 (219).png]]

解法B

![[螢幕擷取畫面 (221).png]]

> 解法A和B積分的算式分別是M和N，可以看那個比較好積而採用A或B

# 例子

![[螢幕擷取畫面 (220).png]]


# Modified Exact Equation

如果不符合Exact Equation的條件，有可能乘上一個$\mu(y)$或$\mu(x)$就是了

## 原理

$$M(x, y)dx + N(x, y)dy = 0$$

兩邊乘上$\mu(x, y)$

$$\mu(x, y)M(x, y)dx + \mu(x, y)N(x, y)dy = 0$$
$$\text{such that   }\frac{\partial\mu(x, y)M(x, y)}{\partial y} = \frac{\partial\mu(x, y)N(x, y)}{\partial x}$$

進行整理

$$\mu_yM + \mu M_y = \mu_xN + \mu N_x$$
$$\mu_xN - \mu_yM = (M_y - N_x)\mu$$

整理後還是很難找到$\mu$，但是在一些情況下還是可以找得到

(1) When $\quad(M_y - N_x)/M\quad$ is a function of $y$ alone:
$\implies$ We can set $\mu$ to be dependent on $y$ alone
Therefore, 
$$-\mu_yM = (M_y - N_x)\mu$$
$$\frac{d\mu}{dy} = \frac{N_x - M_y}{M}\mu$$
$$\frac{1}{\mu}d\mu = \frac{N_x - M_y}{M}dy$$
$$\ln\mu = \int\frac{N_x - M_y}{M}dy$$
$$\mu(y) = e^{\int \frac{(N_x - M_y)}{M}dy}$$

(2) When $\quad(M_y - N_x)/N\quad$ is a function of $x$ alone:
$\implies$ We can set $\mu$ to be dependent on $x$ alone
Therefore, 
$$\mu_xN = (M_y - N_x)\mu$$
$$\frac{d\mu}{dx} = \frac{M_y - N_x}{N}\mu$$
$$\frac{1}{\mu}d\mu = \frac{M_y - N_x}{N}dx$$
$$\ln\mu = \int\frac{M_y - N_x}{N}dx$$
$$\mu(x) = e^{\int \frac{(M_y - N_x)}{N}dx}$$

## 方法



![[螢幕擷取畫面 (223).png]]
![[螢幕擷取畫面 (225).png]]