標籤: #DataStructure 

---

[TOC]

---

# String C++ Class

## getline

C++98:

```cpp
istream& getline(istream& is, string& str, char delim);
istream& getline(istream& is, string& str);
```

C++11:

```cpp
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str);
```

`getline` is a function that extracts characters from `is` is and store them into `str`. If used with the `delim`, it stops extracting characters when `delim` is found. If used without the `delim`, it stops when `\n` is found.

No matter you use `delim` or not, `getline` stops when found `eof`.

> If you used `cin` before you use `getline`, remember to clear the `\n` after your last `cin`.

### Example

```cpp
// extract to string
#include <iostream>
#include <string>

int main()
{
	std::string name;
	
	std::cout << "Please, enter your full name: ";
	std::getline(std::cin, name);
	std::cout << "Hello, " << name << "!\n";

	return 0;
}
```

## substr

This is a member function of `string` object. Takes two parameters `pos` and `len`, return a string object that is a sub string of an original one.

- `pos`: Indicates the starting position.
- `len`: The length of the sub string. If the original string is shorter, as many characters as possible are used.

```cpp
// this example assigns a sub string of str that starts at position 3 and has length 5 to string str2.
string str2 = str.substr(3, 5)
```

# String Pattern Matching

## Simple Algorithm

This algorithm simply iterates through the string and find the pattern.

```cpp
int String::Find(String pat)
// Return -1 if pat does not occur in *this;
// otherwise return the first position in *this,
// where pat begins.
{
	for(int start = 0; start <= Length() - pat.Length(); start++)
	// check for match beginning at str[start]
	{
		int j;
		for(j = 0; j < pat.Length() && str[start + j] == pat.str[j];
			j++);
		if(j == pat.Length())
			return start; // match found
		// no match at position start
	}
	return -1; // pat is empty or does not occur in s
}
```

## The Knuth-Morris-Pratt Algorithm

- [[Knuth-Morris-Pratt Algorithm]]

---

參考資料:

Fundamentals of Data Structures
[getline - cplusplus](https://cplusplus.com/reference/string/string/getline/?kw=getline)

---

link:



---

keywords:

- KMP algorithm
- text finding algorithm
- text searching algorithm