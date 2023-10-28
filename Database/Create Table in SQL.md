Tag: #Database 
Previous: [[SQL]]
Link: 

[TOC]

---

The syntax of creating a table:

```sql
CREATE TABLE r (A_1 D_1,
			    A_2 D_2,
			    -- ...
			    A_n D_n);
```

- `r`: Relation.
- `A_i`: Column name (attribute name).
- `D_i`: Data type.

Example:

```sql
CREATE TABLE instructor (ID        char(5),
						 name      varchar(20),
						 dept_name varchar(20),
						 salary    numeric(8, 2));
```

# Integrity Constraints

To add a [[Primary Key|primary key]] or a [[Foreign Key|foreign key]], you can do it like so:

```sql
CREATE TABLE instructor (
	ID        char(5),
	name      varchar(20),
	dept_name varchar(20),
	salary    numeric(8, 2),
	primary key (ID),
	foreign key (dept_name) references department);
```

---

# Reference

- Tseng, Yi-Ju. “Chapter 3: Introduction to SQL.” Asynchronous Online Course, October 15, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.