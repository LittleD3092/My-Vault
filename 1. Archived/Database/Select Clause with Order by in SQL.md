Tag: #Database 
Previous: [[Select Clause in SQL]]
Link: 

[TOC]

---

We can order the table output by `SELECT` using `ORDER BY`.

```sql
SELECT DISTINCT name
FROM instructor
ORDER BY name;
```

To specify a descending order, use `DESC`:

```sql
SELECT DISTINCT name
FROM instructor
ORDER BY name DESC;
```

To sort on multiple attributes:

```sql
SELECT DISTINCT name
FROM instructor
ORDER BY dept_name, name;
```

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 3: Introduction to SQL, Part 4.” Asynchronous Online Course, October 31, 2023. https://nycu1.sharepoint.com/sites/112-1IntroductiontoDatabaseSystems/_layouts/15/stream.aspx?id=%2Fsites%2F112%2D1IntroductiontoDatabaseSystems%2FShared%20Documents%2FGeneral%2FOnline%20learning%2FCh3%2FCh3%2D5%2DSet%2Emov&referrer=StreamWebApp%2EWeb&referrerScenario=AddressBarCopied%2Eview.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.