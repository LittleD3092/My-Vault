Tag: #computer-graphics 
Previous: [[Shading]]
Link: 

[TOC]

---

This is a simple model that can be computed **rapidly**. This model has 3 **components**:

- [[Ambient Component of Phong Reflection Model|Ambient]].
- [[Diffuse Component of Phong Reflection Model|Diffuse]].
- [[Specular Component of Phong Reflection Model|Specular]].
	- [[Shininess Coefficient of Phong Reflection Model|Shininess Coefficient]]

And it uses 4 **fundamental vectors** to calculate the 3 above components:

- Point to light source $\bf l$.
- Point to viewer $\bf v$.
- Normal direction $\bf n$.
- Point to reflect direction $\bf r$.

![[Pasted image 20231027195252.png|200]]

To summarize, the coefficients that needs to be predetermined are listed below:

- 9 coefficients for each light source: $${\bf l}_{dr}, {\bf l}_{dg}, {\bf l}_{db}, {\bf l}_{sr}, {\bf l}_{sg}, {\bf l}_{sb}, {\bf l}_{ar}, {\bf l}_{ag}, {\bf l}_{ab}$$
- 9 absorption/reflection coefficients: $${\bf k}_{dr}, {\bf k}_{dg}, {\bf k}_{db}, {\bf k}_{sr}, {\bf k}_{sg}, {\bf k}_{sb}, {\bf k}_{ar}, {\bf k}_{ag}, {\bf k}_{ab}$$
- [[Shininess Coefficient of Phong Reflection Model|Shininess coefficient]]: $\alpha$

And we may add 3 components:

$$
\begin{array}{l}
	{\bf l} &=& {\bf l}_\text{ambient} + {\bf l}_\text{diffuse} + {\bf l}_\text{specular} \\
	&=& {\bf K}_a{\bf l}_a + {\bf K}_{d}{\bf l}_{d}({\bf l}\cdot {\bf n}) + {\bf K}_s{\bf l}_s({\bf v} \cdot {\bf r})^\alpha
\end{array}
$$

![[Pasted image 20231027234849.png|300]]

---

# Reference

- 林奕成. “Introduction to Computer Graphics, Ch5 Shading.” NYCU EC114[GF], October 16, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.