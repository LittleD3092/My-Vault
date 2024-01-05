Tag: #computer-graphics 
Previous: [[Line Drawing Algorithms]]
Link: 

[TOC]

---

Digital differential analyzer uses the differential: (<u>1</u>)

$$\frac{dy}{dx} = m = \frac{\Delta y}{\Delta x} = \frac{y_2 - y_1}{x_2 - x_1}$$

to scan along line. Its pseudo code is shown as below: (<u>1</u>)

```cpp
for(x = x1; x <= x2; x++)
{
	y += m;
	write_pixel(x, round(y), line_color);
}
```

- [[Digital Differential Analyzer with Symmetry]]

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 7: Rasterization.” NYCU EC114[GF], November 8, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.