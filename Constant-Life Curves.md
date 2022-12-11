標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

- The [[Fluctuating-Stress Diagram]] only predict it has an infinite life or not.
- Constant-life curves estimate the number of cycles.

![[Pasted image 20221211104830.png]]

# Goodman

- Is very inaccurate for the purpose of estimating an equivalent completely reversed stress.
	- Very conservative.

The equivalent completely reversed stress $\sigma_{ar}$:

$$\sigma_{ar} = \frac{\sigma_a}{1 - \sigma_m / S_{ut}}$$

# Morrow

- Steels: Reasonably accurate with the true fracture strength $\tilde \sigma_f$ or the fatigue strength coefficient $\sigma_f'$.
- Aluminum: Only the true fracture strength is great.

The fatigue strength coefficient for steels ($\text{HB} \leq 500$):

$$\sigma_f' = S_{ut} + 50 \text{ kpsi} \qquad
\text{or} \qquad
\sigma_f' = S_{ut} + 345\text{ MPa}$$

The equivalent completely reversed stress $\sigma_{ar}$:

$$\sigma_{ar} = \frac{\sigma_a}{1 - \sigma_m / \tilde \sigma_f} \qquad
\text{or} \qquad
\sigma_{ar} = \frac{\sigma_a}{1 - \sigma_m / \sigma_f'}$$

# Smith-Watson-Topper

- Good for aluminium and steels.
- Only need the two stress components.

The equivalent completely reversed stress $\sigma_{ar}$:

$$\sigma_{ar} = \sqrt{\sigma_{\max}\sigma_a} = 
\sqrt{(\sigma_m + \sigma_a)\sigma_a}$$

# Walker

- The best to match experimental predictions when the material fitting parameter $\gamma$ is known.

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.