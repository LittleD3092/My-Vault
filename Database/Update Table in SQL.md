Tag: #Database 
Previous: [[SQL]]
Link: 

[TOC]

---

To add column `A` with domain `D` in table `r`:

```sql
ALTER TABLE r ADD A D;
```

To delete column `A` from table `r`:

```sql
ALTER TABLE r DROP A
```

> The operation above is not supported by many databases. Use with caution.

To insert a new row with data `d_i` in table `r`:

```sql
INSERT INTO r VALUES(d_1, d_2, ... d_n)
```

---

# Reference

- Tseng, Yi-Ju. “Chapter 3: Introduction to SQL.” Asynchronous Online Course, October 15, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.