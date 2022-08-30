標籤: #DataStructure 

---

Obtaining exact time formula is an impossible task, the time needed for an addition, subtraction, multiplication, etc. often depends on the actual numbers being added, subtracted, multiplied, etc. Therefore, we use "program steps" to represent time complexity.

We have two ways of to calculate program steps.

First method: we inroduce a new variable `count`

```cpp
float Sum (float* a, const int n)
{
	float s = 0;
	count++;		//count is global
	for (int i = 0; i < n; i++)
	{
		count++;	//for for
		s += a[i];
		count++;	//for assignment
	}
	count++;		//for last time of for
	count++;		//for return
	return s;
}
```

The program above can be simplified as below because we are only interested in `count`

```cpp
void Sum (float* a, const int n)
{
	for (int i = 0; i < n; i++)
		count += 2;
	count += 3;
}
```

Second method: build a table

Consider the program below:

```cpp
/*line*/	float Sum (float* a, const int n)
/*1*/		{
/*2*/			float s = 0;
/*3*/			for (int i = 0; i < n; i++)
/*4*/				s += a[i];
/*5*/			return s;
/*6*/		}
```

We may construct the following chart:

| line | s/e | frequency | total steps |
| ---- | --- | --------- | ----------- |
| 1    | $0$ | $1$       | $0$         |
| 2    | $1$ | $1$       | $1$         |
| 3    | $1$ | $n + 1$   | $n + 1$     |
| 4    | $1$ | $n$       | $n$         |
| 5    | $1$ | $1$       | $1$         |
| 6    | $0$ | $1$       | $0$         |
|      |     |           | $2n + 3$    | 

> s/e is the amount by which count changes as a result of the execution of that statement.

# Asymptotic Notation

![[Asymptotic Notation]]

---

參考資料:

Fundamentals of Data Structures, 2nd edition

---

link:

[[Asymptotic Notation]]