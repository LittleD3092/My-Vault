Tag: #slam 
Previous: 
Link: 

---

[TOC]

---

- 用三維向量表達旋轉必定有奇異性
- 因此有人提出四元數，用來表達旋轉

# 定義

假設四元數為 ${\bf q}$:

$${\bf q} = q_0 + q_1 i + q_2 j + q_3 k$$

- $q_0, q_1, q_2, q_3$ 為常數
- $i, j, k$ 為虛數

其中虛數滿足：

$$\left\{
	\begin{array}{l}
		i^2 = j^2 = k^2 = -1 \\
		ij = k, \quad ji = -k \\
		jk = i, \quad kj =-i \\
		ki = j, \quad ik = -j
	\end{array}
\right.$$

也有人用一個常數與一個向量表達：

$${\bf q} = [s, {\bf v}], \quad s = q_0 \in {\rm R}, \quad {\bf v} = [q_1, q_2, q_3]^T \in {\rm R}^3$$

- $s$ 稱為實部
- ${\bf v}$ 稱為虛部
- 若 ${\bf v} = 0$ ，${\bf q}$ 稱為實四元數
- 若 $s = 0$ ，${\bf q}$ 稱為虛四元數

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.