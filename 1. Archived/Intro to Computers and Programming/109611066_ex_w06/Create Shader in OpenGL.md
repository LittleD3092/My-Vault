Tag: #computer-graphics 
Previous: [[Shader]]
Link: 

[TOC]

---

The method of creating shader is hard, we often write the creating and setting shaders part in functions. The main function part looks like: (<u>1</u>)

```c++
unsigned int vertexShader, fragmentShader, shaderProgram;
vertexShader = createShader("vertexShader.vert", "vert");
fragmentShader = createShader("fragmentShader.frag", "frag");
shaderProgram = createProgram(vertexShader, fragmentShader);
```

- [[Create Shader Function for Creating Shader in OpenGL|Create shader function]]
- [[Create Program Function for Creating Shader in OpenGL|Create program function]]

---

# Reference

1. Introduction to Computer Graphics TAs. “OpenGL Shader & GLSL, HW2 Tutorial.” NYCU EC114[GF], November 13, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.