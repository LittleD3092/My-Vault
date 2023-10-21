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

---

# Reference

Computer Graphics Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.