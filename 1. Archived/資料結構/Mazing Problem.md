標籤: #DataStructure 

---

[TOC]

---

The maze is a two-dimentional array, `maze[i][j]`, where $1 \leq i \leq m$ and $1 \leq j \leq p$. We assume that the rat starts at `maze[1][1]`, and the exit is at `maze[m][p]`.

An example maze:

![[example maze.png|500]]

`1` means wall, and `0` means path. The mouse can choose eight directions, `N`, `NE`, `E`, `SE`, `S`, `SW`, `W`, and `NW` as long as the surrounding square is a `0` in that direction.

- To avoid checking for board conditions, we surround the maze by a border of ones. The array will therefore be declared as `maze[m + 2][p + 2]`.
- We may predefine the possible directions to move in a table `move`, as in the figure below. ![[allowable moves.png|500]]

# Data Types

We need the following data types:

```cpp
struct offsets
{
	int a, b;
};

enum directions{N, NE, E, SE, S, SW, W, NW};
offsets move[8];
```

If we are at position `[i][j]` in the maze and we wish to find the position `[g][h]` that is southwest of us, then we set

```cpp
g = i + move[SW].a;
h = j + move[SW].b;
```

# Algorithm

- We will encounter a situation that multiple directions are available. Not knowing which one to choose, we pick one but save our current position and the direction of the last move in a list. This way, if we have taken a false path, we can return and try another direction.
- With each new location, we will examine the possibilities, starting from the north and looking clockwise.
- In order to prevent us from going down the same path twice, we use another array `mark[m + 2][p + 2]`, which is initially zero. `mark[i][j]` is set to `1` once we arrive at that position.

```cpp
initialize list to the maze entrance coordinates and direction east;
while(list is not empty)
{
	(i, j, dir) = coordinates and direction from end of list;
	delete last element of list;
	while(there are more moves from (i, j))
	{
		(g, h) = coordinates of next move;
		if((g == m) && (h == p))
			success;
		if((!maze[g][h]) // legal move
		    && (!mark[g][h])) // haven't been here before
		{
			mark[g][h] = 1;
			dir = next direction to try;
			add(i, j, dir) to end of list;
			(i, j, dir) = (g, h, N);
		}
	}
}
cout << "No path in maze." << endl;
```

# Implementation

Finding a path through a maze:

```cpp
void Path(const int m, const int p)
// Output a path (if any) in the maze; maze[0][i] = maze[m + 1][i] = 
{
	// start at (1, 1)
	mark[1][1] = 1;
	Stack<Items> stack(m * p);
	Items temp(1, 1, E); // set temp.x, temp.y, and temp.dir
	stack.Push(temp);

	while(!stack.IsEmpty())
	// stack not empty
	{
		temp = stack.Top();
		stack.Pop(); // unstack
		int i = temp.x; int j = temp.y; int d = temp.dir;
		while(d < 8) // move forward
		{
			int g = i + move[d].a; int h = j + move[d].b;
			if((g == m) && (h == p))
			// reached exit
			{
				// output path
				cout << stack;
				cout << i << " " << j << endl; // last two squares on 
											   // the path
				cout << m << " " << p << endl;
				return;
			}
			if((!maze[g][h]) && (!mark[g][h]))
			// new position
			{
				mark[g][h] = 1;
				temp.x = i; temp.y = j; temp.dir = d + 1;
				stack.Push(temp);    // stack it
				i = g; j = h; d = N; // move to (g, h)
			}
			else
				d++; // try next direction
		}
	}
	cout << "No path in maze." << endl;
}
```

```cpp
template<class T>
ostream& operator<<(ostream& os, Stack<T>& s)
{
	os << "top = " << s.top << endl;
	for(int i = 0; i <= s.top; i++)
		os << i << ":" << s.stack[i] << endl;
	return os;
}

ostream& operator<<(ostream& os, Items& item)
{
	return os << item.x << "," << item.y << "," << item.dir;
}
```

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

