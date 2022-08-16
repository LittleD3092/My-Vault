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

1. [[#Adjacency Matrices]]
2. [[#Adjacency Lists]]
3. [[#Adjacency Multilists]]

## Adjacency Matrices

- This representation uses a matrix to represent graph. 
- Assume the graph $G = (V, E)$ has $n$ vertices, $n \geq 1$. The adjacency matrix is a two dimentional $n \times n$ array $a$. $a[i][j] = 1$ iff the edge $(i, j)$ or $<i, j>$ is in $E(G)$. $a[i][j] = 0$ if no such edge exists.
- The matrix $a$ is symmetry for undirected graph, but may not be symmetry for directed graph.
- It takes $O(n^2)$ time to answer non-trivial questions, such as how many edges are there in $G$?

## Adjacency Lists

- Because the [[#Adjacency Matrices]] have some spaces unused, in some cases it would be a waste of space if we implement graph using [[#Adjacency Matrices]]. So we may use an array of lists, which each list stores only the edges linked.
- Below is the representation for the example graphs.

![[example graph g1 - graph.jpeg|200]]
![[example graph g3 - graph.jpeg|100]]
![[example graph g4 - graph.jpeg|300]]
![[adjacent lists example - graph.jpeg|400]]

### Sequential Array

We can also store a [[#Adjacency Lists]] in a sequential array. The figure below shows the sequential representation of graph $G_4$:

![[example graph g4 - graph.jpeg|300]]

![[sqeuqntial representation of example graph g4 - graph.jpeg|600]]

`nodes[0:8]` act as a "index" of where the [[#Adjacency Lists]] begin. For example, `nodes[9]` and `nodes[10]` is the edge of vertex `0`.

### Inverse Adjacency Lists

If we need to keep track of the in-degree more than the out-degree, we use inverse adjacency lists, shown below.

![[example graph g3 - graph.jpeg|100]]

![[inverse adjacency lists for g3 - graph.jpeg|500]]

## Adjacency Multilists

In this list, each edge will be exactly one node, shared by two vertices. The node is like the following:

| `m` | `vertex1` | `vertex2` | `link1` | `link2` | 
| --- | --------- | --------- | ------- | ------- |

- `m`: A boolean field to indicate whether this edge has been examined.
- `vertex1`, `vertex2`: The vertices of the edge
- `link1`: The `*next` pointer for `vertex1`
- `link2`: The `*next` pointer for `vertex2`

Below is an example of graph $G_1$:

![[example graph g1 - graph.jpeg|200]]

![[adjacency multilists for g1 - graph.jpeg|600]]

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

- [[#Depth-First Search]]
- [[#Breadth-First Search]]

## Depth-First Search

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

## Breadth-First Search

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

# Spanning Trees

When doing a [[#Depth-First Search]] or a [[#Breadth-First Search]], not all the edges will be traversed. The edges being traversed form a tree, which is a spanning tree.


![[a spanning tree example - graph.jpeg|500]]

- A spanning tree constructed using a [[#Depth-First Search]] is called a depth-first spanning tree.
- A spanning tree constructed using a [[#Breadth-First Search]] is called a broad-first spanning tree.
- If any nontree edge $(v, w)$ is added on a spanning tree, a cycle is formed. The cycle contains the edge $(v, w)$ and the path from $v$ to $w$ in the spanning tree.

# Biconneced Components

- A vertex $v$ of $G$ is an ==articulation point== iff the deletion of $v$, together with the deletion of all edges incident to $v$, leaves behind a graph that has at least two connected components.
- A ==biconnected graph== is a connected graph that has no articulation points.
- A ==biconnected component== of a connected graph $G$ is a maximal biconnected subgraph $H$ of $G$.

![[biconnected components example - graph.jpeg|400]]

- The number that represent the sequence in which the vertices are visited during the [[#Depth-First Search]] is called ==depth-first number==. The graph $(b)$ below shows the depth-first number of each vertex.

![[depth-first spanning tree with depth-first number - graph.jpeg|500]]

- The broken lines are non-tree edges. Edges like this are called ==back edge.== A back edge $(u, v)$ is non-tree edge, and either $u$ is $v$'s ancestor or $v$ is $u$'s ancestor.
- A non-tree edge that is not a back edge is called a ==cross edge==.

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition

---

link:

