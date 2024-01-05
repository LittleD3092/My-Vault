Tag: #computer-graphics 
Previous: [[Clipping]]
Link: 

[TOC]

---

Cohen-Sutherland algorithm divide the projection plane into 9 regions, and assign each region with an **outcode**:

![[Pasted image 20231021145234.png|300]]

Each bit has its meaning:

| Bit      | Meaning                             |
| -------- | ----------------------------------- |
| $\rm b0$ | if $y > y_{\rm max}$, $0$ otherwise |
| $\rm b1$ | if $y < y_{\rm min}$, $0$ otherwise |
| $\rm b2$ | if $x > x_{\rm max}$, $0$ otherwise |
| $\rm b3$ | if $x < x_{\rm min}$, $0$ otherwise | 

Depending the position of the projected line, there will be 4 cases:

| Case | Description                                                                              | Illustration                         |
| ---- | ---------------------------------------------------------------------------------------- | ------------------------------------ |
| 1    | Both endpoints are in the frame.                                                         | ![[Pasted image 20231021145857.png]] |
| 2    | Both endpoints are outside the frame, and on the same side of the borderline.            | ![[Pasted image 20231021145908.png]] |
| 3    | One endpoint is in the frame, the other one is out.                                      | ![[Pasted image 20231021145920.png]] |
| 4    | Both of the endpoints are outside the frame, but not on the same side of the borderline. | ![[Pasted image 20231021145928.png]] | 

# Cohen-Sutherland Method in 3D

This method, different from the 2D one, uses **6-bit outcodes** to determine whether the line is in the [[Viewing Volume]].

![[Pasted image 20231022171129.png]]

There will generally be 3 cases for each bit in the outcode:

- `outcode(A) == outcode(B) == 0`: Accept the line segment.
- `outcode(A) && outcode(B) != 0`: Reject the line segment.
- Other cases: Calculate intersection, then check the outcode again.

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.