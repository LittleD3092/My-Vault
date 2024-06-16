Tag: #network-science 
Previous: [[Power Law Distribution]]
Link: 

[TOC]

---

The cumulative distribution function **adds the previous data points** together, and plot the result on a graph (<u>1</u>).

The figure below is a simple demonstration. We first order the vertex by its degree, and give each one a **rank**. Based on the rank, we can give each vertex a **probability (cumulatively)** (<u>1</u>).

![[Pasted image 20231029175308.png]]

Plotting a **larger network** will look like the figure below (<u>1</u>). The figure below also shows the result of plotting [[Probability Distribution Function|probability distribution function]].

![[Pasted image 20231029175602.png]]

Of course, this method has a **disadvantage**. Because it is cumulative, the plotting points are not independent. This will cause **an error in the data accumulates to the points afterwards** (<u>1</u>).

---

# Reference

1. Lou, Yang. “Network Science, Lecture 6: Scale-Free Networks, Part 2.” NYCU ED102[GF], October 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.