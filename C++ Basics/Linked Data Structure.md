標籤: #cpp 

---

# Singly Linked Lists

## Node and Pointer Type Definitions

```cpp
class IntNode
{
public:
	IntNode() {}
	IntNode(int theData, IntNode* theLink)
		: data(theData), link(theLink) {}
	IntNode* getLink() const { return link; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setLink(IntNode* pointer) { link = pointer; }
private:
	int data;
	IntNode *link;
};

typedef IntNode* IntNodePtr;
```

## Function to Add a Node at the Head of a Linked List

![[Adding a Node to the Head of a Linked List.png]]

### Function Declaration

```cpp
void headInsert(IntNodePtr& head, int theData);
// Precondition: The pointer variable head points to
// the head of a linked list.
// Postcondition: A new node containing theData
// has been added at the head of the linked list.
```

### Function Definition

```cpp
void headInsert(IntNodePtr& head, int theData)
{
	head = new IntNode(theData, head);
}
```

## Function to Add a Node in the Middle of a Linked List

![[Inserting in the Middle of a Linked List.png]]

### Function Declaration

```cpp
void insert(IntNodePtr afterMe, int theData);
// Precondition: afterMe points to a node in a linked list.
// Postcondition: A new node containing theData
// has been added after the node pointed to by afterMe.
```

### Function Definition

```cpp
void insert(IntNodePtr afterMe, int theData)
{
	afterMe -> setLink(new IntNode(theData, afterMe -> getLink()));
}
```

## Removing a Node

![[removing a node.png]]

## Function to Locate a Node in a Linked List

![[searching a linked list.png]]

### Function Declaration

```cpp
IntNodePtr search(IntNodePtr head, int target);
// Precondition: The pointer head points to the head of a 
// linked list. The pointer variable in the last node is nullptr.
// If the list is empty, then head is nullptr.
// Returns a pointer that points to the first node that contains the
// target. If no node contains the target, the function returns nullptr.
```

### Function Definition

```cpp
IntNodePtr search(IntNodePtr head, int target)
{
	IntNodePtr here = head;
	
	if(here == nullptr) // if empty list
	{
		return nullptr;
	}
	else
	{
		while(here -> getData() != target && here -> getLink() != nullptr)
			here = here -> getLink();
		
		if(here -> getData() == target)
			return here;
		else
			return nullptr;
	}
}
```

# Doubly Linked Lists

A doubly linked list has one link that is a pointer to the next node and an additional link that is a pointer to the previous node.

![[doubly linked list.png]]

## Node Class

```cpp
class DoublyLinkedIntNode
{
public:
	DoublyLinkedIntNode() {}
	DoublyLinkedIntNode(int theData, 
						DoublyLinkedIntNode* previous, 
						DoublyLinkedIntNode* next) 
	: data(theData), nextLink(next), previousLink(previous)
	{}
	DoublyLinkedIntNode* getNextLink() const 
	{ return nextLink; }
	DoublyLinkedIntNode* getPreviousLink() const 
	{ return previousLink; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setNextLink(DoublyLinkedIntNode* pointer)
	{ nextLink = pointer; }
	void setPreviousLink(DoublyLinkedIntNode* pointer)
	{ previousLink = pointer; }

private:
	int data;
	DoublyLinkedIntNode *nextLink;
	DoublyLinkedIntNode *previousLink;
};
typedef DoublyLinkedIntNode* DoublyLinkedIntNodePtr;
```

---

參考資料:

Absolute C++, 6th edition

---

link:

