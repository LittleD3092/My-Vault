Tag: #computer-graphics 
Previous: [[BSP Tree]]
Link: 

[TOC]

---

Back-to-front render is a way to solve [[Hidden Surface Removal|hidden surface removal]]. It requires the BSP tree of all polygons.

```
render(node, view)
{
	if node is a leaf
	{
		draw this node to the screen
	}
	else if the view point is in back of the dividing line
	{
		render(front subnode)
		draw node to screen
		render(back subnode)
	}
	else // the view point is in front of the dividing line
	{
		render(back subnode)
		draw node to screen
		render(front subnode)
	}
}
```

---

# Reference

1. 林奕成, “Introduction to Computer Graphics, Chapter 8: Hidden Surface, part 2,” NYCU EC114[GF], Dec. 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.