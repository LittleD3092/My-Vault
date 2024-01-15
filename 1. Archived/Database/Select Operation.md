Tag: #Database 
Previous: [[Relational Algebra]]
Link: 

[TOC]

---

Select operation $\sigma$ is an operation of relational algebra. It selects rows that satisfy a rule.

$$\sigma_p(r)$$

- $p$: Selection predicate (rule).
- $r$: Relation (table).

Ex:

$$\sigma_{\rm dept\_name = 'Physics'}(\rm Instructor)$$

In selection predicate $p$, we allow comparisons and connectives:

- $>$: Greater than.
- $<$: Less than.
- $\geq$: Greater or equal.
- $\leq$: Less or equal.
- $=$: Equal.
- $\neq$: Not equal.
- $\cap$: [[Intersect Operation]].
- $\cup$: [[Union Operation]].
- $\neg$: Not.

---

# Reference

Database Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.