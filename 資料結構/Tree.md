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

## Degree-Two Tree Representation (Binary Tree)

- To obtain the degree-two tree representation, we simply rotate the sibling link of [[#Left Child-Right Sibling Representation]] by $45\degree$.
- Note that the right child of the root node of the tree is empty. This is always true because the root of the tree can never have a sibling.
- This is also known "binary trees".

![[degree-two tree representation - tree.png|300]]

### Abstract Data Type

This specification defines only a minimal set of operations on binary trees.

```cpp
template <class T>
class BinaryTree
// objects: A finite set of nodes either empty or consisting of a 
// root node, left BinaryTree and right BinaryTree.
{
public:
	BinaryTree();
	// creates an empty binary tree

	bool IsEmpty();
	// return true iff the binary tree is empty

	BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);
	// creates a binary tree whose left subtree is bt1, 
	// whose right subtree is bt2, 
	// and whose root node contains item

	BinaryTree<T> LeftSubtree();
	// return the left subtree of *this

	BinaryTree<T> RightSubtree();
	// return the right subtree of *this

	T RootData();
	// return the data in the root node of *this
};
```

### Skewed Binary Trees

Skewed binary trees are like lists, they look like a straight line. The following is a skewed tree that skewed to the left:

![[skewed binary tree - tree.png|300]]

Of course there are a corresponding skewed tree that skewed to the right.

### Complete Binary Trees

![[complete binary tree - tree.png|500]]

### Representations

#### Array Representation

We may use an ordinary 1D array to represent the tree. We use `a[n + 1]` for array declaration, with $n$ nodes starting from `a[1]` to `a[n]`.

To navigate through the tree, we should define where "parent", "left child" and "right child" are. The following are the definition of the three relative nodes. $i$ is the node index.

1. `parent(i)` is at $\lfloor i / 2 \rfloor$ if $i \neq 1$. If $i = 1$, $i$ is at the root and has no parent.
2. `leftChild(i)` is at $2i$ if $2i \leq n$. If $2i > n$, then $i$ has no left child.
3. `rightChild(i)` is at $2i + 1$ if $2i + 1 \leq n$. If $2i + 1 > n$, then $i$ has no right child.

In this representation, there is one flaw. If the trees we are representing are [[#Skewed Binary Trees]] or something similar, there will be a lot of memory waste. Therefore this representation is only good for [[#Complete Binary Trees]].

#### Linked Representation

Although the array representation is good for complete binary trees, it is wasteful for many other binary trees. Also, insertion and deletion of the nodes require a lot of time.

These problems can be solved by using "linked representation".

```cpp
template <class T> class Tree; // forward declaration

template <class T>
class TreeNode
{
friend class Tree<T>;
private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

template <class T>
class Tree
{
public:
	// Tree operations
private:
	TreeNode<T> *root;
};
```

### Traversal

If we let $L, V, R$ stand for moving left, visiting the node, and moving right when at a node, then there are six possible combinations of traversal:

$$LVR, LRV, VLR, VRL, RVL, RLV$$

If we adopt the convention that we traverse left before right, then only three traversals remain:

$$LVR, LRV, VLR$$

To these we assign the names:

1. $LVR$: "inorder"
2. $LRV$: "postorder"
3. $VLR$: "preorder"

In the following subsections, we will use the following binary tree as an example:

![[binary tree with arithmetic expression - tree.png|500]]

#### Inorder

Inorder traversal calls for moving down the tree toward the left until you can go no farther. Then you "visit" the node, move one node to the right and continue.

```cpp
template<class T>
void Tree<T>::Inorder()
// Driver calls workhorse for traversal of entire tree.
// The driver is declared as a public member function of Tree.
{
	Inorder(root);
}

template<class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode)
// Workhorse traverses the subtree rooted at currentNode.
// The workhorse is declared as a private member function of Tree.
{
	if(currentNode)
	{
		Inorder(currentNode -> leftChild);
		Visit(currentNode);
		Inorder(currentNode -> rightChild);
	}
}
```

The elements of the example binary tree get output in the following order:

$$A / B * C * D + E$$

#### Preorder

```cpp
template<class T>
void Tree<T>::Preorder()
// Driver
{
	Preorder(root);
}

template<class T>
void Tree<T>::Preorder(TreeNode<T> *currentNode)
// Workhorse.
{
	if(currentNode)
	{
		Visit(currentNode);
		Preorder(currentNode -> leftChild);
		Preorder(currentNode -> rightChild);
	}
}
```

The elements of the example binary tree get output in the following order:

$$+**/ABCDE$$

Which is prefix form of the expression.

#### Postorder

```cpp
template<class T>
void Tree<T>::Postorder()
// Driver.
{
	Postorder(root);
}
```

The elements of the example binary tree get output in the following order:

$$AB/C*D*E+$$

Which is postfix form of the expression.

#### Iterative Inorder Traversal

Since we want to iterate through all the elements in the tree one by one, we first need to implement the inorder traversal method without using recursion.

```cpp
template<class T>
void Tree<T>::NonrecInorder()
// Nonrecursive inorder traversal using a stack.
{
	Stack<TreeNode<T>*> s; // declare and initialize stack
	TreeNode<T> *currentNode = root;
	while(1)
	{
		while(currentNode)
		// move down leftChild fields
		{
			s.Push(currentNode); // add to stack
			currentNode = currentNode -> leftChild;
		}
		if(s.IsEmpty())
			return;
		currentNode = s.Top();
		s.Pop(); // delete from stack
		Visit(currentNode);
		currentNode = currentNode -> rightChild;
	}
}
```

We can now use the function `NonrecInorder` to obtain an inorder iterator for a tree. The class `InorderIterator` is a nested class (and a friend) of `Tree`.

```cpp
class InorderIterator
{
public:
	InorderIterator(){ currentNode = root };
	T* Next();
private:
	Stack<TreeNode<T>*> s;
	TreeNode<T> *currentNode;
};
```

```cpp
T* InorderIterator::Next()
{
	while(currentNode)
	{
		s.Push(currentNode);
		currentNode = currentNode -> leftChild;
	}
	if(s.IsEmpty())
		return 0;
	currentNode = s.Top();
	s.Pop();
	T& temp = currentNode -> data;
	currentNode = currentNode -> rightChild;
	return &temp;
}
```

#### Level-Order Traversal

Whether written iteratively or recursively, the [[#Inorder]], [[#Preorder]], and [[#Postorder]] traversals all require a stack. We now turn to a traversal that requires a queue.

This traversal visits the nodes level by level and left to right.

```cpp
template<class T>
void Tree<T>::LevelOrder()
// Traverse the binary tree in level order.
{
	Queue<TreeNode<T>*> q;
	TreeNode<T> *currentNode = root;
	while(currentNode)
	{
		Visit(currentNode);
		if(currentNode -> leftChild)
			q.Push(currentNode -> leftChild);
		if(currentNode -> rightChild)
			q.Push(currentNode -> rightChild);
		if(q.IsEmpty())
			return;
		currentNode = q.Front();
		q.Pop();
	}
}
```

---

參考資料:

Fundamental of Data Structure in C++, 2nd edition

---

link:

[[Linked List]]
[[Linked Data Structure]]
[[Evaluation of Expressions]]