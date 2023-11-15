Tag: #computer-graphics 
Previous: [[Computer Graphics/Computer Graphics]]
Link: 

[TOC]

---

![[Pasted image 20230918183916.png|200]]

We use 4D vector to represent points:

$$
\begin{array}{}
	\bf p &=& [x & y & z & 1]^T \\
	\bf p' &=& [x' & y' & z' & 1]^T \\
	\bf d &=& [d_x & d_y & d_z & 0]^T
\end{array}
$$

We can find the relationship:

$${\bf p}' = {\bf p} + {\bf d}$$

We can also express translation using $4 \times 4$ matrix:

$$
\begin{array}{}
	{\bf T} &=& {\bf T} (d_x, d_y, d_z) \\
	&=& \left[
		\begin{array}{}
			1 & 0 & 0 & d_x \\
			0 & 1 & 0 & d_y \\
			0 & 0 & 1 & d_z \\
			0 & 0 & 0 & 1
		\end{array}
	\right]
\end{array}
$$

Therefore, the relationship can also be represented by:

$${\bf p}' = {\bf T}{\bf p}$$

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.