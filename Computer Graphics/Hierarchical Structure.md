Tag: #computer-graphics 
Previous: [[Computer Graphics/Computer Graphics]]
Link: 

[TOC]

---

As seen in [[Computer Graphics/Computer Graphics#Chapter 2 Transformations]], there are many transformations. When animating an object with a lot of **sub-components** (robot arm), deciding the transformation for each component is hard and aberrant.

**Hierarchical structure** can easily model objects with hierarchical sub-components. For example, a lamp:

![[Pasted image 20231015162811.png]]

When we look at each component's transformation, we find that the child inherit parent's transformation:

![[Pasted image 20231015163012.png]]

Using this procedure, we can avoid redundant matrix multiplication, also preventing calculation error.

# OpenGL for the Lamp

The OpenGL code for animating the lamp may look like this:

```cpp
// TODO: Draw the base

MatA = glm::rotate(Mat, theta_a);
// TODO: Pass the MatA
// TODO: Draw the dark blue arm

Mat1 = glm::translate(MatA, d_1);
MatB = glm::rotate(Mat1, theta_b);
// TODO: Pass the MatB
// TODO: Draw the light blue arm

Mat2 = glm::translate(MatB, d_2);
MatC = glm::rotate(Mat2, theta_c);
// TODO: Pass the MatC
// TODO: Draw the lampshade
```

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.