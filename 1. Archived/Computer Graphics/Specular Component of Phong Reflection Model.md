Tag: #computer-graphics 
Previous: [[Phong Reflection Model]]
Link: 

[TOC]

---

The specular component shows the **reflected light**.

![[Pasted image 20231027232720.png|300]]

![[Pasted image 20231027233045.png|200]]

The formula of specular component is as shown:

$${\bf l}_r = {\bf K}_{s} \cdot
{\bf l}_{s}({\bf v} \cdot {\bf r})^\alpha$$

- ${\bf K}_s$: The coefficient of specular.
- ${\bf l}_s$: Applied light.
- ${\bf v}$: Vector pointed to viewer direction.
- ${\bf r}$: Vector pointed to reflect direction.
- $\alpha$: [[Shininess Coefficient of Phong Reflection Model|Shininess coefficient]].

---

# Reference

- 林奕成. “Introduction to Computer Graphics, Ch5 Shading.” NYCU EC114[GF], October 16, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.