標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

Also called ==MSS theory==.

> *Yielding begins whenever the maximum shear stress in any element equals or exceeds the maximum shear stress in a tension-test specimen of the same material when that specimen begins to yield.*

As a strip of a ductile material is subjected to tension, slip lines (called Luder lines) form at approximately $45\degree$ with the axis of the strip. 

You can find out the maximum shear appears at $45\degree$ by [[Mohr's Circle]], so this phenominon agrees to the MSS theory.

# Failure Envelope

For a general state of stress ($\sigma_1, \sigma_2,\sigma_3$ represent 3D stress), the maximum-shear-stress theory predicts yielding when

$$
\tau_{\text{max}} = 
\frac{\sigma_1 - \sigma_3}{2} \geq
\frac{S_y}{2} \qquad
\text{or} \qquad
\sigma_1 - \sigma_3\geq S_y
$$

Using [[Principal Stress]] $\sigma_A$ and $\sigma_B$ to represent the above equation, we get 3 cases:

$$
\begin{array}{l}
	\text{Case 1: } &
	\sigma_A \geq \sigma_B \geq 0 & 
	\text{For this case, } \sigma_1 = \sigma_A \text{ and } \sigma_3 = 0. \\
	\text{Case 2: } &
	\sigma_A \geq 0 \geq \sigma_B & 
	\text{For this case, } \sigma_1 = \sigma_A \text{ and } \sigma_3 = \sigma_B. \\
	\text{Case 3: } & 
	0 \geq \sigma_A \geq \sigma_B & 
	\text{For this case, } \sigma_1 = 0 \text{ and } \sigma_3 = \sigma_B.
\end{array}
$$

We may represented the above 3 cases in stress diagram:

![[Pasted image 20221016184022.png]]

---

參考資料:

Mechanical Enginnering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.