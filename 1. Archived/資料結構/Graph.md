標籤: #DataStructure 

---

[TOC]

---

- Degree of a vertex: The number of edges incident to it.

# Eularian

For every graph, there is a walk starting at any vertex, going through each edge exactly once and terminating at the start vertex iff the degree of each vertex is even.

## Proof

> Proof: Graph is Eularian iff all vertices have even degree.

Let's first assume graph $G$ is Eularian, and assume $C$ is an $u-u$ (starting at vertex $u$, ending at vertex $u$) Eularian circuit.

For each vertex $v$ in the path $C$ that is not the starting nor the end point $u$, it has $2k$ edges attached to it. $k$ is a natural number.

> This is true because one must enter and leave the vertex, causing the edges attached to it to be even

For the starting and ending vertex $v$, there is the first edge in the path and the last edge in the path. Therefore the degree of $v$ is

$$\underbrace{1}_{\text{first edge}} + 2j + \underbrace{1}_{\text{last edge}}, \quad j \text{ is an natural number or 0. }$$

Now we prove that if graph is Eularian, all vertices have even degree. After that, we try the other way around. We are trying to prove that if all vertices are even, the graph is Eularian.

---

$G$ is a connected and non-trivial graph that all the degrees of all vertices are even.

We first assume that the trail is not a $u-u$ circuit. Let $T$ be a trail of maximum length in $G$. $T$ is a $u-v$ trail.

Suppose $u \neq v$, $v$ will have an end edge and $2k$ edges for getting in and out of the vertex.

$$degree(v) = \underbrace{1}_{\text{last edge}} + 
\underbrace{2k}_{\text{vertex as middle of the trail}}$$
$$\text{where }k \text{ is natural number or 0}$$

This is odd number, which does not agree with our statement of $G$ ($G$'s vertices are even). Therefore, $u = v$. 

Therefore we have proven that $T = C$ is a circuit with maximum length. Next we prove that $C$ does contain every edge.

Assume $C$ doesn't contain every edge, and the edge not contained is $(x, y)$:

![[prove of Eularian - graph.jpeg|400]]

Note that $(x, y)$ should connect to $C$, otherwise $G$ is not connected.

Vertex $x$ has $2k + 1$ edges, which does not satisfy that every vertex has even edges. Therefore $C$ contains every edge, and $C$ is Eularian.

Now we have proven the two statements:

1. If graph is Eularian, all vertices have even degree.
2. If all vertices have even degree, the graph must be Eularian

Therefore we found out that "graph is Eularian iff all vertices have even degree".

# Basics

- Graph consists of two sets, $V$ and $E$.
	- $V$ is a set of vertices.
	- $E$ is a set of pairs of vertices, which is called edges.
	- Example: $V(G) = \{0, 1, 2, 3\}$; $E(G) = \{(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)\}$ is a graph as shown:

![[example graph 1 - graph.jpeg|300]]

- The number of distinct unordered pairs $(u, v)$ with $u \neq v$ in a graph with $n$ vertices is $n(n-1)/2$
- An $n$-vertex, undirected graph with exactly $n(n-1) / 2$ edges is said to be ==complete==.
- If $(u, v)$ is an edge in $E(G)$, then we say $u$ and $v$ are ==adjacent== and that the edge $(u, v)$ is ==incident== on vertices $u$ and $v$.
- A ==path== from vertex $u$ to vertex $v$ is a sequence of vertices, where any adjacent vertices in the sequence has an edge between them.
- A ==simple path== is a path that has no repeated edge.
- A ==cycle== is a simple path that the first and the last vertices are the same.
- Vertices $u$ and $v$ are ==connected== iff there is a path in graph $G$ from $u$ to $v$ and $G$ is undirected.
- A ==component== is a maximum connected subgraph. The graph below has two components.

![[component example - graph.jpeg|600]]

- A directed graph $G$ is said to be ==strongly connected== iff for every pair of distinct vertices $u$ and $v$, there is a direct path from $u$ to $v$ and also from $v$ to $u$.
- For a directed graph $G$, the ==in-degree== of a vertex $v$ is the number of edges pointed to $v$.
- For a directed graph $G$, the ==out-degree== of a vertex $v$ is the number of edges which their tails are $v$.

# Abstract Data Type

```cpp
class Graph
// objects: A nonempty set of vertices and a set of undirected edges, 
//          where each edge is a pair of vertices.
{
public:
	// virtual destructor
	virtual ~Graph(){}

	// return true iff graph has no vertices
	bool isEmpty() const { return n == 0; }

	// return number of vertices in the graph
	int NumberOfVertices() const { return n; }

	// return number of edges in the graph
	int NumberOfEdges() const { return e; }

	// return number of edges incident to vertex u
	virtual int Degree(int u) const = 0;

	// return true iff graph has the edge (u, v)
	virtual bool ExistEdge(int u, int v) const = 0;

	// insert vertex v into graph; v has no incident edges
	virtual void InsertVertex(int v) = 0;

	// insert edge(u, v) into graph
	virtual void InsertEdge(int u, int v) = 0;

	// delete v and all edges incident to it
	virtual void DeleteVertex(int v) = 0;

	// delete edge(u, v) from the graph
	virtual void DeleteEdge(int u, int v) = 0;

private:
	int n; // number of vertices
	int e; // number of edges
};
```

# Graph Representations

To implement graph, we have three ways:

1. [[Adjacency Matrices]]
2. [[Adjacency Lists]]
3. [[Adjacency Multilists]]

# C++ Implementation

There are two graph types

- undirected
- directed

and two weighing options

- weighted
- unweighted

and may be imported in four methods:

- [[#Adjacency Matrices]]
- [[#Adjacency Lists]]
- [[#Sequential Array]]
- [[#Adjacency Multilists]]

This leaves to us 16 kinds of implementation. We often use class hierarchy for our graph classes. Like below:

```mermaid
flowchart TD

Graph --- MatrixWDigraph
Graph --- LinkedWDigraph
Graph --- LinkedDigraph

MatrixWDigraph --- MatrixWGraph
MatrixWDigraph --- MatrixDigraph

LinkedWDigraph --- LinkedWGraph

LinkedDigraph --- LinkedGraph

MatrixWGraph --- MatrixGraph
```

Note that only [[#Adjacency Matrices]] and [[#Adjacency Lists]] is shown in the graph.

# Elementary Operations

Given a graph $G = (V, E)$, we wish to visit all vertices is $G$ that are reachable from a vertex $v$. We have two ways of doing it:

- [[Depth-First Search]]
- [[Breadth-First Search]]

## Conected Components

To find all components in the undirected graph $G$, we use the code:

```cpp
virtual void Graph::Components()
// Determine the connected components of the graph.
{
	// visited is assumed to be declared as a bool* data member of Graph
	visited = new bool [n];
	fill(visited, visited + n, false);
	for(i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			DFS(i); // find a component
			OutputNewComponent();
		}
	}
	delete [] visited;
}
```

## Strongly Connected Components

A strongly connected cmoponent of a directed graph $G = (V, E)$ is a maximal set of vertices $C$ that for every pair of vertices $u$ and $v$ in $C$, we have both paths $u \rightarrow v$ and $v \rightarrow u$.

# Topological Sort

[[Topological Sort]]

# Spanning Trees

When doing a [[#Depth-First Search]] or a [[#Breadth-First Search]], not all the edges will be traversed. The edges being traversed form a tree, which is a spanning tree.


![[a spanning tree example - graph.jpeg|500]]

- A spanning tree constructed using a [[#Depth-First Search]] is called a depth-first spanning tree.
- A spanning tree constructed using a [[#Breadth-First Search]] is called a broad-first spanning tree.
- If any nontree edge $(v, w)$ is added on a spanning tree, a cycle is formed. The cycle contains the edge $(v, w)$ and the path from $v$ to $w$ in the spanning tree.

## Minimum Cost Spanning Tree

> [[Minimum Cost Spanning Tree]]

# Biconneced Components

- A vertex $v$ of $G$ is an ==articulation point== iff the deletion of $v$, together with the deletion of all edges incident to $v$, leaves behind a graph that has at least two connected components.
- A ==biconnected graph== is a connected graph that has no articulation points.
- A ==biconnected component== of a connected graph $G$ is a maximal biconnected subgraph $H$ of $G$.

![[biconnected components example - graph.jpeg|400]]

- The number that represent the sequence in which the vertices are visited during the [[#Depth-First Search]] is called ==depth-first number==. The graph $(b)$ below shows the depth-first number of each vertex.

![[depth-first spanning tree with depth-first number - graph.jpeg|500]]

- The broken lines are non-tree edges. Edges like this are called ==back edge.== A back edge $(u, v)$ is non-tree edge, and either $u$ is $v$'s ancestor or $v$ is $u$'s ancestor.
- A non-tree edge that is not a back edge is called a ==cross edge==.

## Finding Articulation Points

![[depth-first spanning tree with depth-first number - graph.jpeg|500]]

To find articulation points, we first need to construct two array, the depth-first number `dfn[]` and the lowest depth-first number `low[]`.

We already know how to generate `dfn[]`, so let's see how to generate `low[]`. We look for its children and find the maximum `dfn[]`. But, we can use the cross edge, marked in dot lines in the figure above.

1. node `3`: It has the lowest `dfn`, which is `1`. `low[3] = 1`.
2. node `4`: Going down and using the cross edge, `4 -> 2 -> 1 -> 3`, we have `low[4] = dfn[3] = 1`.
3. node `2` and node `1` also use the cross edge, `low[2] = low[1] = dfn[3]`
4. ...

Continuing this process, we have the following table:

| vertex  | `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8`  | `9` |
| ------- | --- | --- | --- | --- | --- | --- | --- | --- | ---- | --- |
| `dfs[]` | `5` | `4` | `3` | `1` | `2` | `6` | `7` | `8` | `10` | `9` |
| `low[]` | `5` | `1` | `1` | `1` | `1` | `6` | `6` | `6` | `10` | `9` | 

Then we determine the articulation point using the following condition:

- For every edge in spanning tree, if `low[child] >= dfs[parent]`, the parent vertex is articulation point.

# Shortest Path

In a directed weighed graph, we wish to find a shortest path from a vertex (we call it ==source==) to another vertex (we call it ==destination==). We have three algorithms to do this:

1. [[Dijkstra Algorithm]]: Can only solve positive weighed graph. Use a table.
2. [[Bellman-Ford Algorithm]]: Can solve negative weighed graph. Use a table and a list of edges.
3. [[Floyd-Warshall Algorithm]]: Can solve negative weighed graph and calculate all pairs of starting and ending point at the same time. Use matrices.

Before we jump into the algorithms, we must know what ==relaxation== means. Relaxation compares the current recoded distance with the new possible distance, and choose the smaller one. Like this:

```cpp
// d[] is the current distance in record
// c(u, v) is the weight of the edge (u, v)

if(d[u] + c(u, v) < d[v])
	d[v] = d[u] + c(u, v) // update distance
```

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition
[Articulation Point and Biconnected Components - youtube](https://youtu.be/jFZsDDB0-vo)
[Dijkstra Algorithm - youtube](https://youtu.be/XB4MIexjvY0)
[Bellman-Ford Algorithm - youtube](https://youtu.be/FtN3BYH2Zes)
[Floyd-Warchall Algorithm - youtube](https://youtu.be/oNI0rf2P9gE)

---

link:

[[Greedy Algorithm]]