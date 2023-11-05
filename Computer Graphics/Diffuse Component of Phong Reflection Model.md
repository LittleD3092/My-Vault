Tag: #computer-graphics 
Previous: [[Phong Reflection Model]]
Link: 

[TOC]

---

Diffuse component animates the light that is **scattered equally** in all directions. The reflected intensities vary with the direction of light, as the below figure shown: (<u>1</u>)

![[Pasted image 20231027232153.png]]

The formula of diffuse component: (<u>1</u>)

$${\bf l}_\text{diffuse} = {\bf K}_d \cdot {\bf l}_d({\bf n}\cdot {\bf l})$$

- ${\bf K}_d$: Diffuse coefficient.
- ${\bf l}_d$: Incoming light.
- $\bf n$: The normal vector, normalized to length equals 1.
- $\bf l$: Incoming light, but normalized to 1.

---

# Reference

- 林奕成. “Introduction to Computer Graphics, Ch5 Shading.” NYCU EC114[GF], October 16, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.