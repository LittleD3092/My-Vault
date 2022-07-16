標籤: #cpp 

---

# Iterators

## Constant and Mutable Iterators

- Constant Iterators: The dereferencing operator `*` produces a read-only version of the element. Does not allow you to change the element at its location.

```cpp
std::vector<char>::const_iterator p = container.begin();
```

- Mutable Iterators: `*p` can be assigned a value, which will change the corresponding element in the container.

```cpp
std::vector<char>::iterator p = container.begin()
```

## Reverse Iterators

A reverse iterator can be used to cycle through all elements of a container with bidirectional iterators. The elements are visited in reverse order.

```cpp
STL_container<datatype>::reverse_iterator rp;
for(rp = c.rbegin(); rp != c.rend(); rp++)
	Process_At_Location p;
```

The object `c` is a container class with bidirectional iterators.

When using `reverse_iterator`, you need to have some sort of `using` declaration or something equivalent. For example, if `c` is a `vector<int>`, the following will suffice:

```cpp
vector<int>::reverse_iterator rp;
```

# Containers

## Sequential Containers

A sequential container arranges the data into a list so that there is a first element, a next element, and so forth, up to a last element. Some common sequential container template class include the following:

- `slist`
- `list`
- `vector`
- `deque`

The following is the two classes of STL named `slist` and `list`:

![[two kinds of lists.png]]

- `slist` is not standard, and most programmers think of class `list` rather than `slist` when implementing linked lists.
- `list` is the same as `vector` except one feature. The `vector` class has random-access iterators, while `list` class doesn't.

### STL Basic Containers

| Template Class Name                                | Iterator Type Names                                                                                                                | Kind of Iterators                                                                                                        | Library Header File                                             |
| -------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------- |
| `slist` (Warning: `slist` is not part of the STL.) | `slist<T>::iterator` <br>  `slist<T>::const_iterator`                                                                              | <ul> <li> Mutable forward <li> Constant forward </ul>                                                                   | `<slist>` (Depends on implementation and may not be available.) |
| `list`                                             | `list<T>::iterator` <br> `list<T>::const_iterator` <br> `list<T>::reverse_iterator` <br> `list<T>::const_reverse_iterator`         | <ul> <li> Mutable bidirectional <li> Constant bidirectional <li> Mutable bidirectional <li> Constant bidirectional </ul> | `<list>`                                                        |
| `vector`                                           | `vector<T>::iterator` <br> `vector<T>::const_iterator` <br> `vector<T>::reverse_iterator` <br> `vector<T>::const_reverse_iterator` | <ul> <li> Mutable random access <li> Constant random access <li> Mutable random access <li> Constant random access </ul> | `<vector>`                                                      |
| `deque`                                            | `deque<T>::iterator` <br> `deque<T>::const_iterator` <br> `deque<T>::reverse_iterator` <br> `deque<T>::const_reverse_iterator`     | <ul> <li> Mutable random access <li> Constant random access <li> Mutable random access <li> Constant random access </ul>                 | `<deque>`                                                       |

#### Example

`list` Template Class Example:

```cpp
// Program to demonstrate the STL template class list.
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

int main()
{
	list<int> listObject;
	
	for(int i = 1; i <= 3; i++)
		listObject.push_back(i);
	
	cout << "List contains:\n";
	list<int>::iterator iter;
	for(iter = listObject.begin(); 
		iter != listObject.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Setting all entries to 0:\n";
	for(iter = listObject.begin(); 
		iter != listObject.end(); iter++)
		*iter = 0;
	cout << "List now contains:\n";
	for(iter = listObject.begin(); 
		iter != listObject.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```

Sample Dialogue:

```
List contains:
1 2 3
Setting all entries to 0:
List now contains:
0 0 0
```

### Useful Member Functions

| Member Function (`c` is a container object) | Meaning                                                                                                                                                  |
| ------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `c.size()`                                  | Returns the number of elements in the container.                                                                                                         |
| `c.begin()`                                 | Returns an iterator located at the first element in the container.                                                                                       |
| `c.end()`                                   | Returns an iterator located one beyond the last element in the container.                                                                                |
| `c.rbegin()`                                | Returns an iterator located at the last element in the container. Used with `reverse_iterator`. Not a member of `slist`.                                 |
| `c.rend()`                                  | Returns an iterator located one beyond the first element in the container. Used with `reverse_iterator`. Not a member of `slist`.                        |
| `c.push_back(Element)`                      | Inserts the `Element` at the end of the sequence. Not a member of `slist`.                                                                               |
| `c.push_front(Element)`                     | Inserts the `Element` at the front of the sequence. Not a member of `vector`.                                                                            |
| `c.insert(Iterator, Element)`               | Inserts a copy of Element before the location of Iterator.                                                                                               |
| `c.erase(Iterator)`                         | Removes the element at location `Iterator`. Returns an iterator at the location immediately following. Returns `c.end()` if the last element is removed. |
| `c.clear()`                                 | A `void` function that removes all the elements in the container.                                                                                        |
| `c.front()`                                 | Returns a reference to the element in the front of the sequence. Equivalent to `*(c.begin())`.                                                           |
| `c1 == c2`                                  | True if `c1.size() == c2.size()` and each element of `c1` is equal to the corresponding element of `c2`.                                                 |
| `c1 != c2`                                  | `!(c1 == c2)`                                                                                                                                            |

### Stack Class

- Type name: `stack<T>` or `stack<T, Sequence_Type>` for a stack of elements of type `T`.
- Library header: `<stack>`, which places the definition in the `std` namespace.
- Defined types: `value_type`, `size_type`.
- There are no iterators.

| Member Function (`s` is a stack object) | Meaning                                                                                                             |
| --------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| `s.size()`                              | Returns the number of elements in the stack.                                                                        |
| `s.empty()`                             | Returns `true` if the stack is empty; otherwise, returns `false`.                                                   |
| `s.top()`                               | Returns a mutable reference to the top member of the stack.                                                         |
| `s.push(Element)`                       | Inserts a copy of Element at the top of the stack.                                                                  |
| `s.pop()`                               | Removes the top element of the stack. Note that `pop` is a `void` function. It does not return the element removed. |
| `s1 == s2`                              | `True` if `s1.size() == s2.size()` and each element of `s1` is equal to the corresponding element of `s2`; otherwise, returns `false`.                                                                                                                 |

#### Example

Program using the `stack` template class:

```cpp
// Program to demonstrate use of the stack template
// class from the STL.
#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main()
{
	stack<char> s;
	cout << "Enter a line of text:\n";
	char next;
	cin.get(next);
	while(next != '\n')
	{
		s.push(next);
		cin.get(next);
	}

	cout << "Written backward that is:\n";
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
	
	return 0;
}
```

Sample dialogue:

```
Enter a line of text:
straw
Writtenbackward that is:
warts
```

### Queue Class

| Member Function (`q` is a queue object) | Meaning                                                                                                                                |
| --------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| `q.size()`                              | Returns the number of elements in the queue.                                                                                           |
| `q.empty()`                             | Returns `true` if the queue is empty; otherwise, returns `false`.                                                                      |
| `q.front()`                             | Returns a mutable reference to the front member of the queue.                                                                          |
| `q.back()`                              | Returns a mutable reference to the last member of the queue.                                                                           |
| `q.push(Element)`                       | Adds `Element` to the back of the queue.                                                                                               |
| `q.pop()`                               | Removes the front element of the queue. Note that `pop` is a `void` function. It does not return the element removed.                  |
| `q1 == q2`                              | `True` if `q1.size() == q2.size()` and each element of `q1` is equal to the corresponding element of `q2`; otherwise, returns `false`. | 

### Set Class

- Type name: `set<T>` or `set<T, Ordering>` for a set of elements of type `T`. The `Ordering` is used to sort elements for storage. If no `Ordering` is given, the ordering used is the binary operator, `<`.
- Library header: `<set>`, which places the definition in the `std` namespace.
- Iterators: 
	- `iterator`
	- `const_iterator`
	- `reverse_iterator`
	- `const_reverse_iterator`
	- All iterators are bidirectional and those not including `const_` are mutable. 
	- Following member functions that returns an iterator have the expected behavior.
		- `begin()`
		- `end()`
		- `rbegin()`
		- `rend()`
	- Adding or deleting elements does not affect iterators, except for an iterator located at the element removed.

| Member Function (`s` is a set object) | Meaning                                                                                                                 |
| ------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| `s.insert(Element)`                   | Inserts a copy of `Element` in the set. If `Element` is already in the set, this has no effect.                         |
| `s.erase(Element)`                    | Removes `Element` from the set. If `Element` is not in the set, this has no effect.                                     |
| `s.find(Element)`                     | Returns an iterator located at the copy of `Element` in the set. If `Element` is not in the set, `s.end()` is returned. |
| `s.erase(Iterator)`                   | Erases the element at the location of the `Iterator`.                                                                   |
| `s.empty()`                           | Returns `true` if the set is empty; otherwise, returns `false`.                                                         |
| `s1 == s2`                            | Returns `true` if the sets contain the same elements; otherwise, returns `false`.                                       | 

#### Example

Program using the `set` template class:

```cpp
// Program to demonstrate use of the set template 
// class.
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

int main()
{
	set<char> s;

	s.insert('A');
	// No matter how many times you add an element to a
	// set, the set contains only one copy of that 
	// element.
	s.insert('D');
	s.insert('D');
	s.insert('C');
	s.insert('C');
	s.insert('B');

	cout << "The set contains:\n";
	set<char>::const_iterator p;
	for(p = s.begin(); p != s.end(); p++)
		cout << *p << " ";
	cout << endl;

	cout << "Set contains 'C': ";
	if(s.find('C') == s.end())
		cout << " no " << endl;
	else
		cout << " yes " << endl;

	cout << "Removing C.\n";
	s.erase('C');
	for(p = s.begin(); p != s.end(); p++)
		cout << *p << " ";
	cout << endl;

	cout << "Set contains 'C': ";
	if(s.find('C') == s.end())
		cout << " no " << endl;
	else
		cout << " yes " << endl;

	return 0;
}
```

Sample dialogue:

```
The set contains:
A B C D
Set contains 'C': yes
Removing C.
A B D
Set contains 'C': no
```

### Map Class

- Type name: 

---

參考資料:

Absolute C++, 6th edition

---

link:

[[Class]]
[[Linked List]]
[[Linked Data Structure]]