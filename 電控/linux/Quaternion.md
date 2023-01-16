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

# 旋轉向量的轉換

假設有一旋轉向量

$${\bf n} = [n_x, n_y, n_z]^T$$

並有角度 $\theta$ ，則四元數的表達形式為

$${\bf q} = 
\left[
	\cos\frac{\theta}{2}, 
	n_x\sin\frac{\theta}{2},
	n_y\sin\frac{\theta}{2},
	n_z\sin\frac{\theta}{2}
\right]^T$$

---

反過來，若我們有四元數

$${\bf q} = q_0 + q_1i + q_2 j + q_3 k$$

對應的旋轉向量為

$$\left\{
	\begin{array}{}
		\theta = 2\arccos q_0 \\
		[n_x, n_y, n_z]^T = \displaystyle \frac{[q_1, q_2, q_3]^T}{\sin\frac{\theta}{2}}
	\end{array}
\right.$$

# 運算

## 加減

$${\bf q}_a \pm {\bf q}_b = [s_a \pm s_b, {\bf v}_a \pm {\bf v}_b]$$

## 乘法

乘法可以利用[[#定義]]中的虛數性質推出

$$
\begin{array}{l}
	{\bf q}_a {\bf q}_b & = & s_as_b - x_ax_b - y_ay_b - z_az_b \\
	& + & (s_ax_b + x_as_b + y_az_b - z_ay_b)i \\
	& + & (s_ay_b - x_az_b + y_as_b + z_ax_b)j \\
	& + & (s_az_b + x_a y_b - y_ax_b + z_as_b)k
\end{array}
$$

也可以寫成向量形式

$${\bf q}_a{\bf q}_b = [s_as_b - {\bf v}_a^T {\bf v}_b, s_a{\bf v_b} + s_b {\bf v}_a + {\bf v}_a \times {\bf v}_b]$$

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.