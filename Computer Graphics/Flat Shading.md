Tag: #computer-graphics 
Previous: [[Polygonal Shading]]
Link: 

[TOC]

---

For a polygon on an object, we assume it has the same color. The light $\bf l$, normal vector $\bf n$, and viewer direction vector $\bf v$ are the same for a polygon. (<u>1</u>)

The rendering result will be like this: (<u>1</u>)

![[Pasted image 20231028162359.png|300]]

Advantages and disadvantages: (<u>2</u>)

- **advantage**: The computation cost is relatively cheap.
- **disadvantage**: The boundary edges of polygons will show up in the render output.

Topics related:

- [[Flat Shading and Fixed Pipeline Acceleration]]

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Ch5 Shading Part 2.” NYCU EC114[GF], October 18, 2023.
2. “017_Shading_in_OpenGL.Pdf.” Accessed November 5, 2023. https://teaching.csse.uwa.edu.au/units/CITS3003/lectures/017_Shading_in_OpenGL.pdf.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.