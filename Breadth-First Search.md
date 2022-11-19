標籤: #DataStructure #algorithm 

---

[TOC]

---

# Pseudocode

The pseudocode uses three colors to represent the status of each vertex:

- Black: Discovered and removed from queue.
- Gray: Discovered, but pushed into queue for later $\text{DFS}$.
- White: Not discovered.

The identifiers used in the pseudocode:

- $G$: The graph.
	- $G.V$: The vertex set in the graph $G$.
- $s$: The root we wish to start $\text{BFS}$
- $u$: An arbitrary vertex.
	- $u.color$: The color representing the status of the vertex.
	- $u.d$: The distance between $s$ and $u$.
	- $u.\pi$: The predecessor of $u$.

$$
\begin{array}{rl}
	& \text{BFS}(G, s) \\
	1 & \textbf{for } \text{each vertex } u \in G.V - \{s\} \\
	2 & \qquad u.\textit{color} = \text{WHITE} \\
	3 & \qquad u.d = \infty \\
	4 & \qquad u.\pi = \text{NIL} \\
	5 & s.color = \text{GRAY} \\
	6 & s.d = 0 \\
	7 & s.\pi = \text{NIL} \\
	8 & Q = \varnothing \\
	9 & \text{Enqueue}(Q, s) \\
	10 & \textbf{while } Q \neq \varnothing \\
	11 & \qquad u = \text{Dequeue}(Q) \\
	12 & \qquad \textbf{for } \text{each } v \in G.Adj[u] \\
	13 & \qquad \qquad \textbf{if } v.color == \text{WHITE} \\
	14 & \qquad \qquad \qquad v.color = \text{GRAY} \\
	15 & \qquad \qquad \qquad v.d = u.d + 1 \\
	16 & \qquad \qquad \qquad v.\pi = u \\
	17 & \qquad \qquad \qquad \text{Enqueue} (Q, v) \\
	18 & \qquad u.color = \text{BLACK}
\end{array}
$$

# Analysis

The total time devoted to queue operations is $O(V)$, because each vertex goes in and out of the queue exactly once.

$$\text{time of queue operations} = O(V)$$

The procedure scans the adjacency list of each vertex only when the vertex is dequeued, so it scans each adjacency list at most once.

$$\text{total time spent in scanning list} = O(E)$$

$$\implies \text{ the total running time } = O(V + E)$$

# Implementation

```cpp
virtual void Graph::BFS(int v)
// A breadth first search of the graph is carried out beginning at vertex v.
// visited[i] is set to true when v is visited. The function uses a queue
{
	visited = new bool [n];
	fill(visited, visited + n, false);
	visited[v] = true;
	Queue<int> q;
	q.Push(v);
	while(!q.IsEmpty())
	{
		v = q.Front();
		q.Pop();
		for(all vertices w adjacent to v) // actual code uses an iterator
		{
			if(!visited[w])
			{
				q.Push(w);
				visited[w] = true;
			}
		} // end of for loop
	} // end of while loop
	delete [] visited;
}
```

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition
Introduction to Algorithms, 3rd edition

---

link:

[[Pseudocode]]
[[Depth-First Search]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.