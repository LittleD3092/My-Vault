標籤: #algorithm 

---

[TOC]

---

A ==matroid== is an ordered pair $M = (S, \mathcal I)$ satisfying:

1. $S$ is a finite set.
2. $\mathcal  I$ is a nonempty family of subsets of $S$, called the ==independent== subsets of $S$, such that if $B \in \mathcal I$ and $A\subseteq B$, then $A \in \mathcal I$. We say that $\mathcal I$ is ==hereditary== if it satisfies this property. Note that the empty set $\varnothing$ is necessarily a member of $\mathcal I$.
3. If $A \in \mathcal I$, $B \in \mathcal I$, and $\vert A \vert < \vert B \vert$, then there exists some element $x \in B - A$ such that $A\cup \{x\} \in \mathcal I$. We say that matroid $M$ satisfies the ==exchange property==.

# Graph

A ==graphical matroid== $M_G = (S_G, \mathcal I_G)$ is defined in terms of a given undirected [[Graph]] $G = (V, E)$:

1. The set $S_G$ is defined to be $E$, the set of edges of $G$.
2. If $A$ is a subset of $E$, then $A \in \mathcal I_G$ if and only if $A$ is acyclic. That is, a set of edges $A$ is independent if and only if the subgraph $G_A = (V, A)$ forms a forest.

---

參考資料:

Introduction to Algorithm, 3rd edition

---

link:

[[Graph]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.