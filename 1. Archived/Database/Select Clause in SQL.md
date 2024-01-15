Tag: #Database #sql 
Previous: [[SQL]]
Link: 

[TOC]

---

`SELECT` is a basic syntax for querying in SQL.

To find the `name` in the table `instructor` with a `dept_name`:

```sql
SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.';
```

We can also use `AND` clause to find more specific entities:

```sql
SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.' AND salary > 80000;
```

We can do [[Cartesian Product of Database|Cartesian product]] by stating multiple tables in `FROM`:

```sql
SELECT *
FROM instructor, teaches;
```

- [[Select Clause with Order by in SQL|Order by]]
- [[Select Clause with Where Clause in SQL|Where Clause]]

---

# Reference

- Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 3: Introduction to SQL, Part 2.” Asynchronous Online Course, October 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.