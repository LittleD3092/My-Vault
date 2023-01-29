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
- $P'$ 為 $P$ 的成像點，座標為 $[X', Y', Z']^T$
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

# 像素座標系

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



---

參考資料:

視覺SLAM十四講 從理論到實踐

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.