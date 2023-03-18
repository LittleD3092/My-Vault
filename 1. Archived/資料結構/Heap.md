標籤: #DataStructure #algorithm 

---

[TOC]

---

- Heaps are frequently used to implement [[#Priority Queues]].
- Heaps are usually implemented using array starting at index 1.
	- The parent of a node will be $\lfloor i / 2 \rfloor$.
	- The left child of a node will be $2i$.
	- The right child of a node will be $2i + 1$.
- A ==height== of a node in a heap is the number of edges on the longest simple downward path from the node to a leaf.
- The height of a heap is the height of the root.

# Priority Queues

Priority queues are a specific kind of queue. In this kind of queue, the element to be deleted is the one with highest (or lowest) priority.

Example of a max priority queue:

```cpp
teamplate<class T>
class MaxPQ
{
public:
	// virtual destructor
	virtual ~MaxPQ(){}

	// return true iff the priority queue is empty
	virtual bool IsEmpty() const = 0;

	// return reference to max element
	virtual const T& Top() const = 0;

	// add an element to the priority queue
	virtual void Push(const T&) = 0;

	// delete element with max priority
	virtual void Pop() = 0;
};
```

# Definition

We use the special forms of complete binary [[Tree]], "max tree" and "min tree". A max tree is a tree in which the key value in each node is no smaller than the key values in its children.

- A max heap is a complete binary tree that is also a max tree.
- A min heap is a complete binary tree that is also a min tree.

An example of max heap:

![[example of max heap - heap.png]]

An example of min heap:

![[example of min heap - heap.png]]

## Data Type

The basic operations are the same as those for a max priority queue. The private data members of class `MaxHeap` are given below.

```cpp
private:
	// element array
	T* heap;

	// number of elements in heap
	int heapSize;

	// size of the array heap
	int capacity;
```

## Constructor

The constructor of class `MaxHeap` is given below:

```cpp
template<class T>
MaxHeap<T>::MaxHeap(int theCapacity = 10)
{
	if(theCapacity < 1)
		throw "Capacity must be >= 1.";
	capacity = theCapacity;
	heapSize = 0;
	heap = new T[capacity + 1]; // heap[0] is not used
}
```

## Insertion

First, we insert the element at the next position that forms complete binary tree. Then, we compare the inserted element with its parent and swap them if the elelement's key is greater than its parent's key (for max heap). We keep comparing and "bubble up" until we have a max heap sorted. This process is called "bubbling up" process.

```cpp
template<class T>
void MaxHeap<T>::Push(const T& e)
// Insert e into the max heap.
{
	if(heapSize == capacity)
	// double the capacity
	{
		ChangeSize1D(heap, capacity, 2 * capacity);
		capacity *= 2;
	}
	int currentNode = ++heapSize;
	while(currentNode != 1 && heap[currentNode / 2] < e)
	// bubble up
	{
		// move parent down
		heap[currentNode] = heap[currentNode / 2];

		currentNode / 2;
	}
	heap[currentNode] = e;
}
```

## Deletion

When an element is to be deleted from a max heap, it is taken from the root of the heap. After the root element is taken, we removed the element that has the largest index and attempt to insert it at the root position. Then we compare the element and its child and "trickle down" until we get a sorted heap.

The following code block implements the deletion function `Pop()`.

```cpp
template<class T>
void MaxHeap<T>::Pop()
// Delete max element.
{
	if(IsEmpty())
		throw "Heap is empty. Cannot delete.";
	heap[1].~T(); // delete max element

	// remove last element from heap
	T lastE = heap[heapSize--];

	// trickle down
	int currentNode = 1; // root
	int child = 2;       // a child of currentNode
	while(child <= heapSize)
	{
		// set child to larger child of currentNode
		if(child < heapSize && heap[child] < heap[child + 1])
			child++;

		// can we put lastE in currentNode?
		if(lastE >= heap[child])
			break; // yes

		// no
		heap[currentNode] = heap[child]; // move child up
		currentNode = child; child *= 2; // move down a level
	}
	heap[currentNode] = lastE;
}
```

---

參考資料:

Fundamentals of Data Structure, 2nd edition

---

link:

[[Tree]]
[[Heap Sort]]