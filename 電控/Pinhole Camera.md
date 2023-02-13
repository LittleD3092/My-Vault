Tag: #slam 
Previous: [[Camera]]
Link: 

---

[TOC]

---

![[Pasted image 20230129160853.png]]

- $O-x-y-z$ 為相機座標系
	- $z$ 指向相機前方
	- $x$ 向右
	- $y$ 向下
- $O$ 為光心，也就是針孔
- $P$ 為現實世界的任意空間點，座標為 $[X, Y, Z]^T$
這- $P'$ 為 $P$ 的成像點，座標為 $[X', Y', Z']^T$
- 成像平面到小孔的距離為焦距 $f$

# 投影

根據三角形相似關係，

$$\frac{Z}{f} = \frac{X}{X'} = \frac{Y}{Y'}$$

整理可得到

$$
\left\{
	\begin{array}{}
		X' & = & 
		\displaystyle 
		f\frac X Z \\
		Y' & = & 
		\displaystyle
		f\frac Y Z
	\end{array}
\right.
$$

## 像素座標系

- 在相機中，我們獲得的是一點一點的像素
- 因此我們架一個像素平面 $o-u-v$
- $P'$ 的像素座標為 $[u, v]^T$

像素座標系通常的定義：

- 原點 $o'$ 位於圖像左上角
- $u$ 軸與 $x$ 軸平行
- $v$ 軸與 $y$ 軸平行
- 像素座標系與成像平面之間會相差一個縮放與一個原點的平移
	- 在 $u$ 軸上縮放 $\alpha$ 倍
	- 在 $v$ 軸上縮放 $\beta$ 倍
	- 原點平移 $[c_x, c_y]^T$

從以上定義可以得到

$$
\left\{
	\begin{array}{}
		u & = & \alpha X' + c_x \\
		v & = & \beta Y' + c_y
	\end{array}
\right.
$$

利用 [[#投影]] 中的結果代入

$$
\left\{
	\begin{array}{}
		u & = & 
		\displaystyle
		f_x \frac X Z + c_x \\
		v & = & 
		\displaystyle
		f_y \frac Y Z + c_y
	\end{array}
\right.
$$

利用齊次座標寫成矩陣

$$
Z
\left(
	\begin{array}{}
		u \\
		v \\
		1
	\end{array}
\right) = 
\left(
	\begin{array}{}
		f_x & 0 & c_x \\
		0 & f_y & c_y \\
		0 & 0 & 1
	\end{array}
\right)
\left(
	\begin{array}{}
		X \\
		Y \\
		Z
	\end{array}
\right) 
\overset \Delta =
{\bf KP}
$$

- 中間的矩陣稱為相機的**內參數矩陣**（Camera Intrinsics）

## 加入旋轉與平移

> 這裡我們加入了 [[Rigid Transformation]] 中的概念

上面提到的 ${\bf P}$ 是指相機座標系下的座標，這裡我們轉換為世界座標 ${\bf P}_w$ ，並且利用旋轉矩陣 ${\bf R}$ 與平移向量 ${\bf t}$ 來表示相機的位姿。

$$
Z{\bf P}_{uv} = Z 
\left[
	\begin{array}{}
		u \\
		v \\
		1
	\end{array}
\right] = 
{\bf K}({\bf R}{\bf P}_{w} + {\bf t}) = {\bf K}{\bf T}{\bf P}_w
$$

- 相機的位姿 ${\bf R}, {\bf t}$ 右稱為相機的**外參數**（Camera Extrinsics）。

因為齊次座標乘上非零常數後表達同樣的含意，所以可以把 $Z$ 去掉：

$${\bf P}_{uv} = {\bf K}{\bf T}{\bf P}_w$$

> 這樣寫相差了一個非零常數，代表齊次座標下相等。通常比較會用傳統的式子表示。

---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.