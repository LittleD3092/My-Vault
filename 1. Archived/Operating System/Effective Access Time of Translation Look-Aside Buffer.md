Tag: #operating-system 
Previous: [[Translation Look-Aside Buffer for Paging]]
Link: 

[TOC]

---

The effective access time $EAT$ can be calculated by the formula below:

$$EAT = (\varepsilon_{\rm mem} + \varepsilon_{\rm tlb})\alpha + (2\varepsilon_{\rm mem} + \varepsilon_{\rm tlb})(1 - \alpha)$$

- $\varepsilon_{\rm mem}$: Memory cycle time.
- $\varepsilon_{\rm tlb}$: Associative lookup time.
- $\alpha$: Hit ratio, the percentage of time that a page number is found in the associative registers.

# Example

Let the TLB hit ratio $\alpha$ be $98\%$. It takes $20\rm\  ns$ to lookup the TLB, and $100 \ \rm ns$ to access the memory. Calculate the effective access time.

---

$$\begin{array}{l}
	EAT &=& (100 + 20) \cdot 0.98 + (2\cdot 100 + 20)(1 - 0.98) \\
	&=& 0.98 \cdot 120 + 0.02 \cdot 220 \\
	&=& 122 \text{ (ns)}
\end{array}$$

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management.” Asynchronous Online Course, November 8, 2023. https://drive.google.com/drive/folders/1b9_faOAujMVFTuq1hZDs0wBWwdN5JTj3.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.