Tag: #Database 
Previous: [[SQL]]
Link: 

[TOC]

---

We use `like` syntax to match substring and character. (<u>1</u>)

- `%`: Matches any substring.
- `_`: Matches any character.

For example: (<u>1</u>)

```sql
SELECT name
FROM instructor
WHERE name LIKE '%dar%'
```

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 3: Introduction to SQL, Part 3.” Asynchronous Online Course, October 27, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.