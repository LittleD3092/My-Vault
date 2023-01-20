Tag: #linear-algebra 
Previous: 
Link: [[Special Orthogonal Group]]

---

[TOC]

---

> 三維的旋轉矩陣可以構成特殊正交群 ([[Special Orthogonal Group]])：
> $${\rm SO}(3) = \{{\bf R}\in \mathbb{R}^{3 \times 3} \vert	{\bf R}{\bf R}^T = {\bf I}, \det({\bf R}) = 1\}$$

而變換矩陣（旋轉矩陣加上平移）可以構成特殊歐氏群 (special euclidian group)：

$${\rm SE}(3) = 
\left\{
	\left.
	{\bf T} = \left[
		\begin{array}{}
			{\bf R} & {\bf t} \\
			{\bf 0}^T & 1
		\end{array}
	\right] \in
	\mathbb R^{4 \times 4} 
	\right\vert
	{\bf R} \in {\rm SO}(3), {\bf t} \in \mathbb R^3
\right\}$$

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.