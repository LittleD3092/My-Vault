Tag: #linear-algebra 
Previous: 
Link: [[Special Euclidian Group]] [[Determinant]]

---

[TOC]

---

旋轉矩陣必定為 [[Orthogonal Matrix]] ，所有三維旋轉矩陣可以構成三維的特殊正交群 (special orthogonal group):

$${\rm SO}(3) = \{
	{\bf R}\in \mathbb{R}^{3 \times 3} \vert
	{\bf R}{\bf R}^T = {\bf I}, \det({\bf R}) = 1
\}$$

# 李代數

> [[Lie Algebra]]:
> 李代數是一個向量 $\phi$ ，並且其外積符號 $\phi^\wedge$
> $$\phi^\wedge = \left[\begin{array}{}0 & -\phi_3 & \phi_2 \\ \phi_3 & 0 & -\phi_1 \\	-\phi_2 & \phi_1 & 0 \end{array} \right]$$
> 可以用來微分旋轉矩陣：
> $$\dot{\bf R}(t) = \phi(t)^\wedge {\bf R}(t)$$

> 在此定義下，兩個向量 $\phi_1, \phi_2$ 的李括號為
> $$[\phi_1, \phi_2] = (\Phi_1\Phi_2 - \Phi_2\Phi_1)^\vee$$
> - $\Phi_1 = \phi_1^\wedge$
> - $\Phi_2 = \phi_2^\wedge$

我們在 [[Lie Algebra#推導]] 中的結果 $\phi$ 其實就是特殊正交群的 [[Lie Algebra|李代數]] $\mathfrak{so}(3)$：

$$\mathfrak{so}(3) = \{\phi \in \mathbb R^3, \Phi = \phi^\wedge \in \mathbb R^{3 \times 3}\}$$



---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.