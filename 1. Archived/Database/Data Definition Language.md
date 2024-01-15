Tag: #Database 
Previous: [[Database]]
Link: 

[TOC]

---

**Data Definition Language** (DDL) is the notation for defining the database schema.

For example, a table for storing data of instructors can be written as follow by DDL:

```sql
create table instructor (
    ID           char(5),
    name         varchar(20),
    dept_name    varchar(20),
    salary       numeric(8, 2)
)
```

A **compiler** is used to compile DDL.

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.