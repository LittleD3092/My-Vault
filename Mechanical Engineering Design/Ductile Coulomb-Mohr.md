標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

Not all materials have compressive strengths equal to their corresponding tensile values. Therefore, Coulomb-Mohr assumes that the material have different compressive and tensile strength.

The idea of Mohr is based on three "simple" tests:

1. Tension
2. Compression
3. Shear

Based on these tests, you may construct [[Mohr's Circle]]:

![[Pasted image 20221028204115.png]]

By applying similar trangles to the right figure and simplify, we get

$$\frac{\sigma_1}{S_t} - \frac{\sigma_3}{S_c} = 1$$

For plane stress, when the two nonzero principal stresses are $\sigma_A \geq \sigma_B$, we have a situation similar to the three cases given for the [[Maximum Shear Stress]] theory. That is, the failure conditions are

- Case 1: $\sigma_A \geq \sigma_B \geq 0$. For this case, $\sigma_1 = \sigma_A$ and $\sigma_3 = 0$.
$$\implies \sigma_A \geq S_t$$
- Case 2: $\sigma_A \geq 0 \geq \sigma_B$. Here, $\sigma_1 = \sigma_A$ and $\sigma_3 = \sigma_B$.
$$\implies \frac{\sigma_A}{S_t} - \frac{\sigma_B}{S_c} \geq 1$$
- Case 3: $0 \geq \sigma_A \geq \sigma_B$. For this case, $\sigma_1 = 0$ and $\sigma_3 = \sigma_B$.
$$\implies \sigma_B \leq -S_c$$

Based on these cases above, we can plot the failure envilope:

![[Pasted image 20221028205641.png]]

For design equations, incorporating the [[Factor of Safety(FoS)]] $n$, divide all strengths by $n$. One of the equation above well be

$$\frac{\sigma_1}{S_t} - \frac{\sigma_3}{S_c} = \frac 1 n$$

Since for the Coulomb-Mohr theory we do not need the torsional shear strength circle we can deduce it from one of the equation above

$$\frac{\sigma_1}{S_t} - \frac{\sigma_3}{S_c} = 1$$

For pure shear $\tau$, $\sigma_1 = -\sigma_3$

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.