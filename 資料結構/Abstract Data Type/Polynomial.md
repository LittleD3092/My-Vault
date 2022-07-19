標籤: #DataStructure 

---

[TOC]

---

This is an application of ordered lists.

# Code

```cpp
class Polynomial
{
// p(x) = a_0x^{e_0} + ... + a_nx^{e_n};
// a set of ordered pairs of <e_i, a_i>,
// where a_i is a nonzero float coefficient 
// and e_i is a non-negative integer expenent.
public:
	Polynomial();
	// Construct the polynomial p(x) = 0.

	Polynomial Add(Polynomial poly);
	// Return the sum of the polynomials *this and poly.

	Polynomial Mult(Polynomial poly);
	// Return the product of the polynomials *this and poly.

	float Eval(float f);
	// Evaluate the polynomial *this at f and return the result.
};
```

# Polynomial Representation

This section is about determining the representation of polynomial.

A very reasonable first decision would be to arrange the terms in decresing order of exponent. This will simplify many of the operations.

Based on this principle, we will discuss three representations as follows:

## Representation 1

One way to represent polynomials is to define the private data members of `Polynomial` as follows:

```cpp
private:
	// degree <= MaxDegree
	int degree;
	// coefficient array
	float coef[MaxDegree + 1];
```

## Representation 2

[[#Representation 1]] requires us to know the maximum degree of the polynomials we expect to work with and also is quite wasteful in its use of computer memory. Therefore we may edit the code in [[#Representation 1]] to the following:

```cpp
private:
	int degree;
	float *coef;
```

Then add the following constructor:

```cpp
Polynomial::Polynomial(int d)
{
	degree = d;
	coef = new float[degree + 1]
}
```

## Representation 3

Although we solve the problems mentioned earlier in [[#Representation 2]], it does not yield a desirable representation. If we have $x^{1000} + 1$ as our polynomial, we will ask memory for $2$ non-zero terms and $999$ zero terms. This is a waste of memory since we asked $1001$ of spaces but only $2$ of them are used.

For this purpose, we define the class `term` below:

```cpp
class Term
{
friend Polynomial;
private:
	float coef; // coefficient
	int exp;    // exponent
}
```

The private data members of `Polynomial` are defined as follows:

```cpp
private:
	Term *termArray; // array of nonzero terms
	int capacity;    // size of termArray
	int terms;       // number of nonzero terms
```

# Polynomial Addition

```cpp
Polynomial Polynomial::Add(Polynomial b)
// Return the sum of the polynomials *this and b.
{
	Polynomial c;
	int aPos = 0, bPos = 0;
	while((aPos < terms) && (bPos < b.terms))
		if(termArray[aPos].exp == b.termArray[bPos].exp)
		{
			float t = termArray[aPos].coef + 
					  b.termArray[bPos].coef;
			if(t)
				c.NewTerm(t, termArray[bPos].exp);
			aPos++; bPos++;
		}
		else if(termArray[aPos].exp < b.termArray[bPos].exp)
		{
			c.NewTerm(b.termArray[bPos].coef, 
					  b.termArray[bPos].exp);
			b.Pos++;
		}
		else
		{
			c.NewTerm(termArray[aPos].coef, 
					  termArray[aPos].exp);
			aPos++;
		}
	
	// add in remaining terms of *this
	for(; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, 
				  termArray[aPos].exp);
	
	// add in remaining terms of b(x)
	for(; bPos < b.terms; b++)
		c.NewTerm(b.termArray[bPos].coef, 
				  b.termArray[bPos].exp);
	return c;
}
```

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Array]]