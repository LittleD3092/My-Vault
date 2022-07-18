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
}
```

# Polynomial Representation

This section is about determining the representation of polynomial.

A very reasonable first decision would be to arrange the terms in decre

---

參考資料:

Fundamentals of Data Structures in C++, 2nd edition

---

link:

[[Array]]