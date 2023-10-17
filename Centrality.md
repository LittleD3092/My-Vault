Tag: #network-science 
Previous: [[Network Science]]
Link: 

[TOC]

---

Centrality of a node in a network shows how "center" or "important" this node is.

Centrality isn't a specific formula, there are different ways of calculating it, each having its meaning.

| Centrality                 | Meaning                                                                                                                                         | Application                                                                     |
| -------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| [[Degree Centrality]]      | The **number of edges** connected to a node.                                                                                                    | Identifying nodes with most direct connections.                                 |
| [[Closeness Centrality]]   | The **average shortest path** from a node to other nodes.                                                                                       | Identifying nodes that can quickly interact with other nodes.                   |
| [[Betweenness Centrality]] | The **number of shortest path passing** a node.                                                                                                 | Identifying nodes that are connectors.                                          |
| [[Eigenvector Centrality]] | It measures the **influence** of a node. A node is influential if connected to other influential nodes.                                         | Identifying nodes that has other high influential neighbors.                    | 
| [[PageRank]]               | Similar to [[Eigenvector Centrality]], but includes **damping factor** to account for some random transactions. Made by google.                 | Ranking web pages based on the structure and quality.                           |
| [[Katz Centrality]]        | Similar to [[Eigenvector Centrality]], but account for **all paths** instead of shortest ones, and a **damping factor** to penalize long paths. | Identifying influential nodes considering both direct and indirect connections. |

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.