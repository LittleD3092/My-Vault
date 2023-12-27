Tag: #computer-graphics 
Previous: [[Opacity]]
Link: 

[TOC]

---

We use blending equation to blend two colors and create a translucent effect: (<u>1</u>)

$$
\text{color} = {\bf b} \cdot {\bf S} + {\bf c} \cdot {\bf D}
$$

- $\bf b$: Source blending factor. ${\bf b} = [b_r, b_g, b_b, b_\alpha]$.
- $\bf c$: Destination blending factor. ${\bf c} = [c_r, c_g, c_b, c_\alpha]$.
- $\bf S$: Source blending color. ${\bf S} = [s_r, s_g, s_b, s_\alpha]$.
- $\bf D$: Destination blending color. ${\bf D} = [d_r, d_g, d_b, d_\alpha]$.

To enable blending in opengl, use the following function: (<u>1</u>)

```c++
glEnable(GL_BLEND);
glBlendFunc(source_factor, destination_factor);
```

In the function `glBlendFunc`, only certain factors are supported: (<u>1</u>)

- `GL_ZERO`
- `GL_ONE`
- `GL_SRC_ALPHA`
- `GL_ONE_MINUS_SRC_ALPHA`
- `GL_DST_ALPHA`
- `GL_ONE_MINUS_DST_ALPHA`

---

# Reference

1. 林奕成, “Introduction to Computer Graphics, Chapter 9: Buffers and Mapping Techniques, part 3,” NYCU EC114[GF], Dec. 04, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.