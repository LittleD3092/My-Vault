標籤: #DataStructure #algorithm 

---

[TOC]

---

# Implementation

```cpp
virtual void Graph::DFS() // Driver
{
	// visited is declared as a bool* data member of Graph
	visited = new bool [n];
	fill(visited, visited + n, false);
	DFS(0); // start search at vertex 0
	delete [] visited;
}

virtual void Graph::DFS(const int v) // Workhorse
// Visit all previously unvisited vertices that are reachable from vertex v.
{
	visited[v] = true;
	for(each vertex w adjacent to v) // actual code uses an iterator
		if(!visited[w])    DFS(w);
}
```

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition
Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.