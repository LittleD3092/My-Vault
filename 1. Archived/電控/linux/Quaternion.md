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

# 旋轉矩陣的轉換

假設 ${\bf q} = q_0 + q_1i + q_2j + q_3 k$，則對應的旋轉矩陣 ${\bf R}$ 為

$${\bf R} = 
\left[
	\begin{array}{}
		1 - 2q_2^2 - 2q_3^2 & 2q_1q_2 - 2q_0q_3 & 2q_1q_3 + 2q_0q_2 \\
		2q_1q_2 + 2q_0q_3 & 1 - 2q_1^2 - 2q_3^2 & 2q_2q_3 - 2q_0q_1 \\
		2q_1q_3 - 2q_0q_2 & 2q_2q_3 + 2q_0q_1 & 1 - 2q_1^2 - 2q_2^2
	\end{array}
\right]$$

反過來，假設矩陣為 ${\bf R} = \{m_{ij}\}, \ i, j\in [1, 2, 3]$，則對應的四元數為

$$\left\{
	\begin{array}{}
		q_0 & = & 
		\displaystyle
		\frac{\sqrt{{\rm tr}({\bf R}) + 1}}{2} \\
		q_1 & = & 
		\displaystyle
		\frac{m_{23} - m_{32}}{4q_0} \\
		q_2 & = & 
		\displaystyle
		\frac{m_{31} - m_{13}}{4q_0} \\
		q_3 & = &
		\displaystyle
		\frac{m_{12} - m_{21}}{4q_0}
	\end{array}
\right.$$

- ${\rm tr}({\bf R})$: 矩陣 ${\bf R}$ 的跡 (trace)，也就是主對角線的和

> 除了上述轉換外，也有別的算法

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

> 四元數的乘法不可交換
> $${\bf q}_a {\bf q}_b \neq {\bf q}_b {\bf q}_a$$

## 共軛

共軛是把虛部取負號：

$${\bf q}_a^* = s_a - x_ai - y_aj - z_ak = [s_a, -{\bf v}_a]$$

> ${\bf q}^*$ 與 ${\bf q}$ 相乘會得到一個實四元數：
> $${\bf q}^*{\bf q} = {\bf q}{\bf q}^* = [s_a^2 + {\bf v}^T{\bf v}, {\bf 0}]$$
> 並且實部為 $\vert\vert {\bf q} \vert\vert^2$

## 模長

$$\vert\vert{\bf q}_a\vert\vert = \sqrt{s_a^2 + x_a^2 + y_a^2 + z_a^2}$$

> 從上述結果可以發現
> $$\vert\vert{\bf q}_a{\bf q}_b\vert\vert = \vert\vert{\bf q}_a\vert\vert\ \vert\vert{\bf q}_b\vert\vert$$

## 逆

一個四元數的逆為

$${\bf q}^{-1} = \frac{{\bf q}^*}{\vert\vert{\bf q}\vert\vert^2}$$

乘積的逆有類似矩陣的性質

$$({\bf q}_a{\bf q}_b)^{-1} = {\bf q}_b^{-1}{\bf q}_a^{-1}$$

## 用四元數運算旋轉

題目：假設一個在三維空間中的點 ${\bf p} = [x, y, z] \in {\rm R}^3$，求繞著軸 ${\bf n}$ 旋轉 $\theta$ 角度後的點 ${\bf p}'$

---

首先可以把三維空間用一個虛四元數表達

$${\bf p} = [0, x, y, z] = [0, {\bf v}]$$

參考[[#旋轉向量的轉換]]，旋轉的四元數可以表示為

$${\bf q} = [\cos\frac{\theta}{2}, {\bf n}\sin\frac{\theta}{2}]$$

${\bf p}'$ 即為

$${\bf p}' = {\bf q}{\bf p}{\bf q}^{-1}$$

> 長得有點像 [[Diagonalization]]：
> $$A = XDX^{-1}$$

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.