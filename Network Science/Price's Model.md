Tag: #network-science 
Previous: [[Scale-free Network]]
Link: 

[TOC]

---

Price's model is an analogy to the **citation network**, which papers references other **popular** papers (<u>2</u>). Price's model is the first concept of [[Scale-free Network]] (<u>1</u>).

Price's model is a preferential attachment model, meaning that new papers **tend to reference papers that have been referenced more**. He defined the following rules (<u>2</u>):

- No nodes are taken away.
- Each paper cites **on average** $c$ other papers.
- The network is **acyclic**.

And the **probability** of citing node $i$ is (<u>2</u>):

$$
\begin{array}{}
	p_{\text{cite }i} &=& 
	\displaystyle
	\frac{q_i + a}{\sum_i q_i + a} \\
	&=& 
	\displaystyle
	\frac{q_i + a}{n\langle q \rangle + na}
\end{array}$$

- $q_i$: The degree of node $i$.
- $a$: A modifier constant (for new papers to have a chance to be referenced).
- $\langle q\rangle$: The average of $q_i$.
- $n$: Total number of nodes.

# Difference Between Barabasi-Albert Model

The chart below (<u>2</u>) shows the difference between [[Barabasi-Albert Model|Barabasi-Albert model]] and Price's model.

|           | Barabasi-Albert Model                  | Price's Model                  |
| --------- | -------------------------------------- | ------------------------------ |
| Direction | Undirected                             | Directed                       |
| Add nodes | Exact $c$ connections                  | On average $c$ connections     |
| Degree    | Smallest degree among all nodes is $c$ | Some nodes have degree $k < c$ | 

---

# Reference

1. “Price’s Model.” In Wikipedia, August 27, 2023. https://en.wikipedia.org/w/index.php?title=Price%27s_model&oldid=1172421937.
2. Lou, Yang. “Network Science, Lecture 6: Scale-Free Networks, Part 2.” NYCU ED102[GF], October 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.