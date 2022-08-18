標籤: #電工學 

---

用來分析電路

- 有 $N - 1$ 個 current law
- 有 $L$ 個 voltage law

# Node(Voltage Node)

A connected wire or plate shared the same voltage

# Arc

A one port element which has two terminals

# 用文字表示電路

![[Kirchhoff's Law Example.png]]

| Arc | Node 1 | Node 2 | Value |
| --- | ------ | ------ | ----- |
| V   | 1      | 0      | 48    |
| R   | 1      | 2      | 9     |
| I   | 2      | 0      | 7     |
| R   | 2      | 0      | 5     |
| R   | 0      | 3      | $R_L$ |
| R   | 2      | 3      | 2     | 

- Node 1 與 Node 2 代表電流的方向
- 在 power source 的情況下，電流從 Node 2 流向 Node 1
- 在 element 的情況下，電流從 Node 1 流向 Node 2

# Euler Formula

$$L + N - 1 = A$$

$L$: loops (只計最小的 node)
$N$: node 的數量
$A$: arc 的數量

# Kirchhoff Law

- Kirchhoff Current Law: The total current entering a "node" is zero
- Kirchhoff Voltage Law: The sum of all voltages on the individual "elements" on a "loop" is zero

## Open Circuit

![[Open Circuit.png]]

$$R_L = \underbrace{ \infty }_{ \text{ Light Load 輕載 } } \text{ : open circuit }$$

$$\implies i_L = 0$$

$$v_L = v_{ oc }$$

$v_{ oc }$ is called open circuit voltage

## Short Circuit

$$R_L = \underbrace{ 0 }_{ \text{ Heavy Load 重載 } } \text{ : short circuit }$$

$i_L$ to be solved, known to the short circuit current

# Ways of Analysis

## Classic Kirchhoff

use [[#Kirchhoff Law]] ，標每個 arc 的電流

## Branch Current Method

![[Branch Current Method.png]]

One current for each individual loop

$$
\begin{array}{l}
1. & 7 = i_1 + i_2 \\
2. & 11 - i_1 \cdot 9 - v_7 = 0 \\
3. & v_7 + i_2 \cdot 4 = 0
\end{array}
$$

$1.\ , \ 2.$ 是 $\text{ KVL }$

## Nodal Voltage Method

![[Nodal Voltage Method.png]]

$$N = 4$$

$$2 \text{ KCL equations are needed }$$

$$
\begin{array}{}
\text{ Node } e_1 \text{ : } & \frac{ v - e_1 }{ x } = \frac{ e_1 }{ 4 } + \frac{ e_1 - e_2 }{ 6 } \\
\text{ Node } e_2 \text{ : } & \frac{ v - e_2 }{ 10 } + \frac{ e_1 - e_2 }{ 6 } = \frac{ e_2 }{ 2 }
\end{array}
$$

$$\implies 
\left[
\begin{array}{}
5x + 12 & -2x \\
-5 & 23
\end{array}
\right]
\left[
\begin{array}{}
e_1 \\
e_2
\end{array}
\right]
=
\left[
12v \\
3v
\right]
$$

$$e_1 = \frac{ 276 + 6x }{ 105x + 276 }v$$

$$e_2 = \frac{ 96 + 15x }{ 105x + 276 }v$$

$$i = \frac{ 39 + 3x }{ 92 + 35x }v$$

### e.g.

![[Example of Nodal Voltage Method.png]]

$$
\left\{
\begin{array}{}
\frac{ 10 - e_1 }{ 2 } = \frac{ e_1 }{ 4 } + \frac{ e_1 - e_2 }{ 2.5 } \\
\frac{ e_1 - e_2 }{ 2.5 } = \frac{ e_2 }{ 5 } + \frac{ e_2 - 4 }{ 1 }
\end{array}
\right.
$$

$$
\left[
\begin{array}{}
23 & -8 \\
-2 & 8
\end{array}
\right]
\left[
\begin{array}{}
e_1 \\
e_2
\end{array}
\right]
=
\left[
\begin{array}{}
100 \\
20
\end{array}
\right]
$$

$$e_1 = \frac{ 960 }{ 168 }$$

$$e_2 = \frac{ 660 }{ 168 }$$

## Thevenin/Norton-Equivalent-Circuit Analysis

1. Perform two of these:
	1. Determine the open-circuit voltage $V_t = v_{ oc }$
	2. Determine the short-circuit current $I_n = i_{ sc }$
	3. Zero the independent sources and find the Thevenin resistance $R_t$ looking back into the terminals. Do not zero dependent sources
2. Use the equation $V_t = R_t I_n$ to compute the remaining value
3. The Thevenin equivalent consists of a voltage source $V_t$ in series with $R_t$
4. The Norton equivalent consists of a current source $I_n$ in parallel with $R_t$

## Superposition Principle

1. For each source, zero other sources and calculate current or voltage ($i_n$ or $v_n$)
2. Add them together ($i_T = \sum_{ n } i_n$)

---

參考資料:

電工學上課 2022-02-17
電工學上課 2022-02-24
電工學上課 2022-03-03

---

link:

[[Cramer's Rule]]
[[Thevenin Circuit]]