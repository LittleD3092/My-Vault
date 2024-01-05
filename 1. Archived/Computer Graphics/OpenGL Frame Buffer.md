Tag: #computer-graphics 
Previous: [[Screen Buffer]]
Link: 

[TOC]

---

The opengl frame buffer has a depth of 4:

- **Front buffer**: The color buffer currently displaying.
- **Back buffer**: The color buffer that will be flipped to the front buffer on the next frame.
- **Depth buffer**: The depth of each pixel. Can be used in [[Hidden Surface Removal|hidden surface removal]].
- **Stencil buffer**: A mask for where to draw and where not to draw.

![[Pasted image 20231224142622.png|300]]

---

# Reference

1. 林奕成, “Introduction to Computer Graphics, Chapter 9: Buffers and Mapping Techniques,” NYCU EC114[GF], Nov. 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.