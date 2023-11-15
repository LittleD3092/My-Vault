Tag: #computer-graphics 
Previous: [[Computer Graphics/Computer Graphics]]
Link: 

[TOC]

---

For the transformations in [[Computer Graphics/Computer Graphics#Chapter 2 Transformations]], the corresponding inverse transformation can be written as:

| Transformation  | Inverse                                                                                                                                        |
| --------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| [[Translation]] | $${\bf T}^{-1}(d_x, d_y, d_z) = {\bf T}(-d_x, -d_y, -d_z)$$                                                                                   |
| [[Rotation]]    | $${\bf R}^{-1}(q) = {\bf R}(-q)$$ Since $\cos(-\theta) = \cos(\theta)$ and $\sin(-\theta) = -\sin(\theta)$, $${\bf R}^{-1}(q) = {\bf R}^T(q)$$ |
| [[Scaling]]     | $${\bf S}^{-1}(s_x, s_y, s_z) = {\bf S}(1/s_x, 1/s_y, 1/s_z)$$                                                                                 | 

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.