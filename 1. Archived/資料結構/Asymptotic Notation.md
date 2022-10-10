標籤: #DataStructure #algorithm 

---

[TOC]

---

In [[Time Complexity]], we used steps to determine the run time of programs. However, determining the exact step count is a difficult task and expending effort to determine exact steps is not worth, since the notion of a step is itself inexact. Therefore we use "Big-O Notation".

Big-O Notation 會考慮最糟糕的情況大約會需要多長時間執行程式

| [[#Big-O Notation]]        | [[#Big-Theta Notation]]                   | [[#Big-Omega Notation]] |
| -------------------------- | ----------------------------------------- | ----------------------- |
| Focus on upper bound       | Focus on both upper bound and lower bound | Focus on lower bound    |
| $$0 \leq f(n) \leq cg(n)$$ | $$0 \leq c_1g(n) \leq f(n)\leq c_2g(n)$$  | $$0 \leq cg(n) \leq f(n)$$                        |

# Big-O Notation

## Definition

For
- $f(n)$: the steps of algorithm
- $g(n)$: some simple function

If and only if there exist positive constants $c$ and $n_0$ such that 

$$f(n) < cg(n), \qquad n \geq n_0$$

Then we can say

$$f(n) = O(g(n))$$

.

## Example

For example, for an algorithm $f(n)$, we know its number of steps is 

$$f(n) = 3n + 2$$

Then we get $g(n)$ being the upper boundary because $3n + 2 \leq 4n$ if $n_0 \geq 2$

$$4g(n) = 4n$$

Therefore we obtain the big-o notation of $f(n)$:

$$f(n) = O(n)$$

## Chart

We can use the definition to construct the chart:

n: The size of the input

| Time              | Big-O Notation   |
| ----------------- | ---------------- |
| Constant Time     | $O(1)$           |
| Logarithmic Time  | $O(\log(n))$     |
| Linear Time       | $O(n)$           |
| Linearithmic Time | $O(n\log(n))$    |
| Quadric Time      | $O(n^2)$         |
| Cubic Time        | $O(n^3)$         |
| Exponential Time  | $O(b^n),\ b > 1$ |
| Factorial Time    | $O(n!)$          | 

## Properties

$$O(n + c) = O(n)$$

$$O(cn) = O(n), \quad c > 0$$

- 因為 $n$ 是趨近無限大的數，因此可以忽略常數

如果 $f$ 是表達執行時間的 function ， $n$ 是輸入的大小

$$f(n) = 7\log(n)^3 + 15n^2 + 2n^3 + 8$$

$$O(f(n)) = O(n^3)$$

# Big-Theta Notation

## Definition

For
- $f(n)$: the steps of algorithm
- $g(n)$: some simple function

If and only if:

$$\Theta(g(n)) = \left\{
\begin{array}{}
f(n): \text{ there exist natural number } c_1, c_2, n_0 \\ \text{ that satisfy } 0 \leq c_1g(n) \leq f(n) \leq c_2g(n)
\end{array}
\right\}$$

> The definition above means that $g(n)$ can be both the lower bound $c_1g(n)$ and upper bound $c_2g(n)$ of $f(n)$.

$$\implies f(n) = \Theta(g(n))$$

## Example

$f(n) = 6n + 4$, we can find $g(n) = 2n$ or $g(n) = 5n$.

![[f2.jpg]]

Both these $g(n)$ satisfy, therefore we use simplest $g(n) = n$, and we get big-theta notation $f(n) = \Theta(n)$

# Big-Omega Notation

$$
\Omega(g(n)) = \left\{
\begin{array}{}
	f(n): \text{ there exist natural number } c, n_0 \\ \text{ and all } n \geq n_0 \text{ satisfy } 0 \leq cg(n) \leq f(n)
\end{array}
\right\}
$$

# [[Recursion#Asymptotic Notation of Recursion Function|Recursion]]

![[Recursion#Asymptotic Notation of Recursion Functions]]

# Little o Notation

We use $o$-notation to denote an upper bound that is not asymptotically tight.

$$o(g(n)) = \left\{
	\begin{array}{l}
		f(n): & \text{for any positive constant }c > 0, \\
		& \text{there exitsts a constant } n_0 > 0 \\
		& \text{such that } 0 \leq f(n) < cg(n) \\
		& \text{for all } n \geq n_0.
	\end{array}
\right\}$$

For example, $2n = o(n^2)$, but $2n^2 \neq o(n^2)$. The relation $f(n) = o(g(n))$ implies that

$$\lim_{n \rightarrow \infty}\frac{f(n)}{g(n)} = 0$$

# Little omega Notation

We use $\omega$-notation to denote a lower bound that is not asymptotically tight.

$$\omega(g(n)) = \left\{
	\begin{array}{l}
		f(n) : & \text{for any positive constant } c > 0, \\
		& \text{there exists a constant } n_0 > 0 \\
		& \text{such that } 0 \leq cg(n) < f(n) \\
		& \text{for all } n \geq n_0.
	\end{array}
\right\}$$

For example, $n^2 / 2 = \omega(n)$, but $n^2 / 2 \neq \omega(n^2)$. The relation $f(n) = \omega(g(n))$ implies that

$$\lim_{n \rightarrow \infty}\frac{f(n)}{g(n)} = \infty$$

# Comparing Notations

There are some relational properties that helps with comparing asymptotic notations:

- [[#Transistivity]]
- [[#Reflexivity]]
- [[#Symmetry]]
- [[#Transpose Symmetry]]

Because the above properties hold, we can use two real numbers $a$ and $b$ to represent the properties since they are similar.

$$
\begin{array}{}
	f(n) = O(g(n)) & \text{is like} & a \leq b. \\
	f(n) = \Omega(g(n)) & \text{is like} & a \geq b. \\
	f(n) = \Theta(g(n)) & \text{is like} & a = b. \\
	f(n) = o(g(n)) & \text{is like} & a < b. \\
	f(n) = \omega(g(n)) & \text{is like} & a > b.
\end{array}
$$

## Transistivity

$$
\begin{array}{}
	f(n) = \Theta(g(n)) & \text{and} & g(n) = \Theta(h(n)) & \text{imply} & f(n) = \Theta(h(n)), \\
	f(n) = O(g(n)) & \text{and} & g(n) = O(h(n)) & \text{imply} & f(n) = O(h(n)), \\
	f(n) = \Omega(g(n)) & \text{and} & g(n) = \Omega(h(n)) & \text{imply} & f(n) = \Omega(h(n)), \\
	f(n) = o(g(n)) & \text{and} & g(n) = o(h(n)) & \text{imply} & f(n) = o(h(n)), \\
	f(n) = \omega(g(n)) & \text{and} & g(n) = \omega(h(n)) & \text{imply} & f(n) = \omega(h(n)).
\end{array}
$$

## Reflexivity

$$
\begin{array}{}
	f(n) = \Theta(f(n)), \\
	f(n) = O(f(n)), \\
	f(n) = \Omega(f(n)).
\end{array}
$$

## Symmetry

$$
\begin{array}{}
	f(n) = \Theta(g(n)) & \text{if and only if} & g(n) = \Theta(f(n)).
\end{array}
$$

## Transpose Symmetry

$$
\begin{array}{}
	f(n) = O(g(n)) & \text{if and only if} & g(n) = \Omega(f(n)), \\
	f(n) = o(g(n)) & \text{if and only if} & g(n) = \omega(f(n))
\end{array}
$$

---

參考資料:

[Data Structures Easy to Advanced Course](https://youtu.be/RBSGKlAvoiM)
[Asymptotic Notation - github blog](https://alrightchiu.github.io/SecondRound/complexityasymptotic-notationjian-jin-fu-hao.html)

---

link:

