Tag: #network-science 
Previous: [[Network Science]]
Link: 

[TOC]

---

An acyclic network is a graph that has **no graph cycles**.

# Algorithm

To determine acyclic network, we can follow the steps below to **remove end nodes one by one**:

1. Find a node with **no outgoing edges**.
2. If no such node exists, the network is cyclic. Otherwise, **remove the node found**.
3. Repeat step 1 and 2. If all nodes are removed, it is acyclic.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.