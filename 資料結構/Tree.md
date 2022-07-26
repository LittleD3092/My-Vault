標籤: #DataStructure 

---

[TOC]

---

A tree structure means that the data are organized in a hierarchical manner. It is a finite set of one or more nodes such that

1. There is a specially designated node called the "root".
2. The remaining nodes are partitioned into $n \geq 0$ disjoint sets $T_1, \dots, T_n$, where each of these sets is a tree. $T_1, \dots, T_n$ are called the "subtrees" of the root

There are two types of genealogical charts that are used to present such data:

- [[#Pedigree Chart]]
- [[#Lineal Chart]]

# Pedigree Chart

- normally two-way branching
- not allow for inbreeding
- show ancestors

An example of pedigree chart, shows the ancesters relationship:

![[pedigree chart - tree.png]]

In this case, Brandy and Honey Bear are Dusty's parents.

# Lineal Chart

- show decendents
- each item can produce several others

An example of lineal chart, it shows the descendents of European language:

![[lineal chart - tree.png]]

# Terms

## Degree

The number of subtrees of a node is called its "degree". For example, in the example in [[#Lineal Chart]], "Proto Indo-European" has a degree of 3.

## Leaf

Nodes that have [[#Degree]] 0 are called "leaf" or "terminal" nodes.

## Nonterminal

Nodes that are not [[#leaf]] are called "nonterminals".

## Children

The roots of the subtrees of a node $X$ are called "the children of $X$".

For example, the nodes $B, C, D$ are the children of the node $A$:

![[sample tree - tree.png]]

## Parent

Node $X$ is the "parent" of its children.

For example, the node $A$ is the parent of the children $B, C, D$.

![[sample tree - tree.png]]

## Siblings

[[#Children]] of the same parent are said to be "siblings".

## Degree of a Tree

The "degree of a tree" is the maximum of the [[#Degree]] of the nodes in the tree.

## Ancestor

The "ancestors" of a node are all the nodes along the path from the root to that node.

## Level

The "level" of a node is defined by letting the root be at level one. If a node is at level $l$, then its children are at level $l + 1$.

## Height or Depth of a Tree

The "height" or "depth" of a tree is defined to be the maximum level of any node in the tree.

# Representation

## List Representation

The following tree

![[sample tree - tree.png]]

can be represented by the following list

$$(A(B(E(K, L), F), C(G), D(H(M), I, J)))$$

Since the degree of each node may be different, we may be tempted to use memory nodes with a varying number of pointer fields. However, as it is often easier to write algorithms for a data representation when the node size is fixed, in practice one uses only nodes of a fixed size to represent tree nodes. This node structure is very wasteful of space.

## Left Child-Right Sibling Representation

The node structure will look like this:

![[node structure of the left child-right sibling node - tree.png|350]]

And the tree will be represented like this:

![[the tree representation of the left child-right sibling representation - tree.png]]

## Degree-Two Tree Representation

- To obtain the degree-two tree representation, we simply rotate the sibling link of [[#Left Child-Right Sibling Representation]] by $45\degree$.
- Note that the right child of the root node of the tree is empty. This is always true because the root of the tree can never have a sibling.
- This is also known "binary trees".

![[degree-two tree representation - tree.png|300]]

---

參考資料:

Fundamental of Data Structure in C++, 2nd edition

---

link:

