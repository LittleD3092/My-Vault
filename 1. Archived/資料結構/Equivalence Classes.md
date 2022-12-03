標籤: #DataStructure 

---

[TOC]

---

# Problem

The equivalence classes problem is like a "grouping problem". For example, we have 12 polygons numbered 0 through 11, and we have the following overlap pairs defined:

$$0 \equiv 4, \ 3 \equiv 1, \ 6 \equiv 10, \ 8 \equiv 9, \ 
7 \equiv 4, \ 6 \equiv 8 , \ 3 \equiv 5, \ 2 \equiv 11, \ 
\text{and}\ 11 \equiv 0$$

Then, we may group these polygons into three equivalence classes like this:

$$\{0, 2, 4, 7, 11\}; 
\{1, 3, 5\};
\{6, 8, 9, 10\}$$

We need to develop an algorithm to group these numbers from the overlap pair list.

# Algorithm

We may use a one dimensional array `first[]` that stores linked lists to process our data. First, we read in next pair of overlap pairs `pair(i, j)`. Then, we put `i` on `first[j]` and `j` on `first[i]`. For the example in the [[#Problem]] above, we will have a data structure like this:

![[Equivalence Classes - Lists after pairs have been input.png]]

After we have the lists, we may iterate through `first[]` and output the numbers. Note that we use a stack to store the data to be searched. For example, when we output `first[0]`, we put `11` and `4` on stack, marked them to be searched. Therefore after we output `0 11 4`, we search `first[11]` and `first[4]` then output the data that is under these indexes after `0 11 4`. In this case, we will find all the numbers associated to `0`.

The algorithm can be expressed in the following:

```cpp
void Equivalence()
{
	read n; // read in number of objects
	initialize first[0:n - 1] to 0 and out[0:n - 1] to false;
	while(more pairs) // input pairs
	{
		read the next pair(i, j);
		put j on the chain first[i];
		put i on the chain first[j];
	}
	for(i = 0; i < n; i++)
		if(!out[i])
		{
			out[i] = true;
			output the equivalence class that contains object i;
		}
}
```

# Code

```cpp
class ENode
{
friend void Equivalence();
public:
	ENode(int d = 0) // constructor
	{ data = d; link = 0; }
private:
	int data;
	ENode *link;
};

void Equivalence()
// Input the equivalence pairs and output the equivalence classes.
{
	ifstream inFile("equiv.in", ios::in); // "equiv.in" is the input 
										  // file
	if(!inFile) throw "Cannot open input file.";
	int i, j, n;
	inFile >> n; // read number of objects
	// initialize first and out
	ENode **first = new ENode* [n];
	bool *out = new bool [n];
	// use STL function fill to initialize
	fill(first, first + n, 0);
	fill(out, out + n, false);

	// Phase 1: input equivalence pairs
	inFile >> i >> j;
	while(inFile.good()) // check end of file
	{
		first[i] = new ENode(j, first[i]);
		first[j] = new ENode(i, first[j]);
		inFile >> i >> j;
	}

	// Phase 2: output equivalence classes
	for(i = 0; i < n; i++)
		if(!out[i]) // needs to be output
		{
			cout << endl << "A new class: " << i;
			out[i] = true;
			ENode *x = first[i]; ENode *top = 0; // initialize stack
			while(true)
			// find rest of class
			{
				while(x)
				// process the list
				{
					j = x -> data;
					if(!out[j])
					{
						cout << ", " << j;
						out[j] = true;
						ENode *y = x -> link;
						x -> link = top;
						top = x;
						x = y;
					}
					else
						x = x -> link;
				} // end of while(x)
				if(!top)
					break;
				x = first[top -> data];
				top = top -> link; // unstack
			} // end of while(true)
		} // end of if(!out[i])
	for(i = 0; i < n; i++)
		while(first[i])
		{
			ENode *delnode = first[i];
			first[i] = delnode -> link;
			delete delnode;
		}
	delete [] first;
	delete [] out;
}
```

---

參考資料:

Fundamental of Data Structures, 2nd edition

---

link:

[[Linked List]]
[[Linked List#Singly Linked Lists]]