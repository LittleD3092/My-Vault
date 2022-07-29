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

Knuth-Morris-Pratt algorithm iterates through the string just like [[#Simple Algorithm]]. However, this algorithm employs the observation that when a mismatch occurs, the pattern `pat` itself embodies sufficient informationto determine where the next match could begin, thus bypassing re-examination of previously matched characters.

### Failure Function

This algorithm uses an array to store results of a function called "failure function", `f`. The definition of failure function:

$$f(j) = \left\{
	\begin{array}{}
		\text{ largest } k < j \text{ such that } 
		p_0 \dots p_k = p_{j - k} \dots p_j &
		\text{ if such a } k \geq 0 \text{ exists } \\
		-1 & \text{ otherwise }
	\end{array}	
\right\}$$

For example, a pattern `pat = abcabcacab` will have failure function:

| $j$   | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `pat` | a   | b   | c   | a   | b   | c   | a   | c   | a   | b   |
| $f$   | -1  | -1  | -1  | 0   | 1   | 2   | 3   | -1  | 0   | 1   | 

### Find

From the definition of [[#Failure Function]], we have the following rule for pattern matching: If a partial match is found such that $s_{i - j} \dots s_{i - 1} = p_0 \dots p_{j - 1}$ and $s_i \neq p_j$ then matching may be resumed by comparing $s_i$ and $p_{f(j - 1) + 1}$ if $j \neq 0$. If $j = 0$, then we may continue by comparing $s_{i + 1}$ and $p_0$.

### Code

Pattern-matching with a failure function:

```cpp
int String::FastFind(String pat)
// Determine if pat is a substring of s.
{
	int posP = 0, posS = 0;
	int lengthP = pat.Length(), lengthS = Length();
	while((posP < lengthP) && (posS < lengthS))
		if(pat.str[posP] == str[posS]) // character match
		{
			posP++;
			posS++;
		}
		else
			if(posP == 0)
				posS++;
			else
				posP = pat.f[posP - 1] + 1;
	if(posP < lengthP)
		return -1;
	else
		return posS - lengthP;
}
```

- `f`: an array of failure function

Computing the failure function:

```cpp
void String::FailureFunction()
// Compute the failure function for the pattern *this.
{
	int lengthP = Length();
	f[0] = -1;
	for(int j = 1; j < lengthP; j++) // compute f[j]
	{
		int i = f[j - 1];
		while((*(str + j) != *(str + i + 1)) && (i >= 0))
			i = f[i];
		if(*(str + j) == *(str + i + 1))
			f[j] = i + 1;
		else
			f[j] = -1;
	}
}
```

---

參考資料:

Fundamentals of Data Structures
[getline - cplusplus](https://cplusplus.com/reference/string/string/getline/?kw=getline)

---

link:

