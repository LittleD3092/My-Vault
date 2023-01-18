Tag: #slam 
Previous: 
Link: 

---

[TOC]

---

# 群

群 (group) 包含了一種集合和一種運算，並且滿足

1. 封閉性
2. 結合律
3. 單位元
4. 逆

譬如我們有集合 $A$ 和乘法運算 $\cdot$ ，則記作

$$G = (A, \cdot)$$

並且滿足以下條件

1. 封閉性 $$\forall a_1, a_2 \in A,\quad a_1 \cdot a_2 \in A$$
2. 結合律 $$\forall a_1, a_2, a_3\in A, \quad (a_1 \cdot a_2)\cdot a_3 = a_1 \cdot (a_2 \cdot a_3)$$
3. 單位元 $$\exists a_0 \in A, \quad {\rm s.t.} \quad \forall a \in A, \quad a_0 \cdot a = a\cdot a_0 = a$$
4. 逆 $$\forall a \in A, \quad \exists a^{-1} \in A, \quad {\rm s.t.}\quad a \cdot a^{-1} = a_0$$

[[Matrix]] 中常見的群有

- 一般線性群 ${\rm GL}(n)$: $n \times n$ 的可逆矩陣，對矩陣乘法成群
- 特殊正交群 ${\rm SO}(n)$: 旋轉矩陣群
- 特殊歐氏群 ${\rm SE}(n)$: $n$ 維的歐式變換

# 李群

- 李群是指具有連續性質的群
- 整數群 $\mathbb{Z}$ 是離散的，不屬於李群
- 而 ${\rm SO}(n)$ 和 ${\rm SE}(n)$ 在空間上是連續的，屬於李群

# 李代數

## 推導

考慮任意旋轉矩陣 ${\bf R}$:

$${\bf R}{\bf R}^T = {\bf I}$$

對兩邊微分：

$$\dot{\bf R}(t){\bf R}(t)^T + {\bf R}(t)\dot{\bf R}(t)^T = 0$$

整理得到

$$\dot{\bf R}(t){\bf R}(t)^T = -\left(
	\dot{\bf R}(t){\bf R}(t)^T
\right)^T$$

由此可以得到 $\dot{R}(t){\bf R}(t)^T$ 為反對稱矩陣

> 回憶在外積中我們會用符號 $\wedge$ 將向量變成反對稱矩陣
> $${\bf a} \times {\bf b} = {\bf a}^\wedge {\bf b}$$
> 同理，反對稱矩陣也可以轉換為向量，我們以 $\vee$ 表示
> $${\bf a}^\wedge = {\bf A} = \left[ \begin{array}{} 0 & -a_3 & a_2 \\ a_3 & 0 & -a_1 \\ -a_2 & a_1 & 0 \end{array} \right], \quad {\bf A}^\vee = {\bf a}$$

我們定義 ${\phi}(t)$ 為對應 $\dot{\bf R}(t){\bf R}(t)^T$ 的向量

$$\dot{\bf R}(t){\bf R}(t)^T = \phi(t)^\wedge$$

並且我們發現

$$\dot{\bf R}(t) = \phi(t)^\wedge {\bf R}(t)$$

因此若要對旋轉矩陣做微分，只需要前面乘上 $\phi(t)^\wedge$ 即可。其實 $\phi(t)$ 就是 ${\rm SO}(3)$ 的李代數 $\mathfrak{so}(3)$。

## 定義

李代數的定義如下：

李代數由一個集合 $\mathbb{V}$ ，一個數域 $\mathbb{F}$ 和一個二元運算 $[,]$ 組成，並滿足以下性質。我們稱 $(\mathbb{V}, \mathbb{F}, [,])$ 為一個李代數，寫作 $\mathfrak{g}$

1. 封閉性 $$\forall {\bf X}, {\bf Y} \in \mathbb{V}, \quad [{\bf X}, {\bf Y}] \in \mathbb V$$
2. 雙線性 $$\forall {\bf X}, {\bf Y}, {\bf Z}\in \mathbb V, \quad a, b\in \mathbb F$$ 符合 $$[a{\bf X} + b{\bf Y}, {\bf Z}] = a[{\bf X, {\bf Z}}] + b[{\bf Y}, {\bf Z}]$$ $$[{\bf Z}, [a{\bf X} + b{\bf Y}]] = a[{\bf Z}, {\bf X}] + b[{\bf Z}, {\bf Y}]$$
3. 自反性 $$\forall {\bf X}\in \mathbb V, \quad [{\bf X}, {\bf X}] = {\bf 0}$$
4. 雅可比等價 $$\forall {\bf X}, {\bf Y}, {\bf Z}\in \mathbb V, \quad [{\bf X}, [{\bf Y}, {\bf Z}]] + [{\bf Z}, [{\bf X}, {\bf Y}]] + [{\bf Y}, [{\bf Z}, {\bf X}]] = {\bf 0}$$

其中二元運算 $[,]$ 被稱為李括號。舉個例子， $\mathfrak g = (\mathbb R^3, \mathbb R, \times)$ 構成一個李代數。

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.