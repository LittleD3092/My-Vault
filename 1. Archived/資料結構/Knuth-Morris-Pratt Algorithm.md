Tag: #DataStructure 
Previous: [[String]]
Link: 

[TOC]

---

Also known as "KMP Algorithm".

Knuth-Morris-Pratt algorithm iterates through the string just like [[String#Simple Algorithm|simple algorithm]]. However, this algorithm employs the observation that when a mismatch occurs, the pattern `pat` itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

# Failure Function

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

# Find

From the definition of [[#Failure Function]], we have the following rule for pattern matching: If a partial match is found such that $s_{i - j} \dots s_{i - 1} = p_0 \dots p_{j - 1}$ and $s_i \neq p_j$ then matching may be resumed by comparing $s_i$ and $p_{f(j - 1) + 1}$ if $j \neq 0$. If $j = 0$, then we may continue by comparing $s_{i + 1}$ and $p_0$.

# Code

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

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.