Tag: #probability 
Previous: [[Probability]]
Link: 

---

Fubini's theorem states that if $f(t, x)$ is integrable over $S$, then the double integrals can be swapped.

# Some Cases

## 1. Half of first quadrant

$$
\int_{t = 0}^\infty \int_{x=t}^\infty f(t, x) dx dt = 
\int_{x = 0}^\infty \int_{t = 0}^x f(t, x) dt dx
$$

## 2. Half of second quadrant

$$
\int_0^\infty \int_{-\infty}^{-t} f_X(x)dxdt = \int_{-\infty}^0\int_{0}^{-x} f_X(x)dt dx
$$

---

# Reference

1. ChatGPT. “Swapping Integrals Justification.” ChatGPT, November 3, 2024. https://chatgpt.com/share/67272796-b6e8-8004-81d9-83b1aaedc62f.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.