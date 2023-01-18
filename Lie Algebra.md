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



---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.