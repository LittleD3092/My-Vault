標籤: #algorithm #DataStructure 

---

[TOC]

---

When building spanning trees, we can sum all the weights of the edges. This is the ==cost== of the spanning tree. We have three ways of finding the minimum-cost spanning tree:

1. [[#Kruskal's Algorithm]]
2. [[#Prim's Algorithm]]
3. [[#Sollin's Algorithm]]

The three algorithms above are ==greedy methods==. This means that they choose their best choice, and never change the choice after decision.

# Kruskal's Algorithm

Kruskal's algorithm simultaneously choose the minimum weight edge that do not form a cycle. We finish when the edge used is exactly $n - 1$.

![[Kruskal's algorithm example - graph.jpeg|500]]

## Determine Cycle

To verify whether the cycle is formed, we place the component into multiple sets. Assume we have a graph like the above one, and we are going to find out whether edge $(3, 6)$ form a cycle. We go through the following steps:

1. Group the graph by component using depth first search. In this case, we have the following sets:
	- $\{0, 5\}$
	- $\{1, 2, 3, 6\}$
	- $\{4\}$
2. We look for the edge, see whether it is in the same set or not. If the edge is in the same set, it forms a cycle. In this case, edge $(3, 6)$ is in the same set $\{1, 2, 3, 6\}$, therefore forms a cycle and should be discarded.

## [[Pseudocode]]

The [[Pseudocode]] of Kruskals's algorithm is demonstrated in the code block below.

```cpp
T = {};
while((T contains less than n - 1 edges) && (E not empty))
{
	choose an edge (v, w) from E of lowest cost;
	delete (v, w) from E;
	if((v, w) does not create a cycle in T)
		add (v, w) to T;
	else
		discard (v, w);
}

if(T contains fewer than n - 1 edges)
	cout << "no spanning tree" << endl;
```

# Prim's Algorithm

The [[#Kruskal's Algorithm]] forms a forest. Prim's algorithm is like growing a tree. We first choose a vertex, `0` in the example below. We choose the edge that has least weight and is adjacent to the tree.

![[Prim's algorithm example - graph.jpeg|500]]

## [[Pseudocode]]

The [[Pseudocode]] of this algorithm is as shown:

```cpp
// Assume that G has at least one vertex
TV = {0}; // start with vertex 0 and no edges
for(T = {}; T contains fewer than n - 1 edges; add (u, v) to T)
{
	Let (u, v) be a least-cost edge such that u is in TV and v is not in TV;
	if(there is no such edge) break;
	add v to TV;
}
if(T contains fewer than n - 1 edges)
	cout << "no spanning tree" << endl;
```

# Sollin's Algorithm

This algorithm is like merging subtrees. At first, each vertex is a subtree. At each stage, each subtree "grow" an edge to connect to other vertex. The subtree may "grow" the same edge.

The example below has two stages:

![[Sollin's algorithm example - graph.jpeg|500]]

---

參考資料:

Introduction to Algorithms, 3rd edition
Fundamental of Data Structures in C++, 2nd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.