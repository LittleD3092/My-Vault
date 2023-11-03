Tag: #Database 
Previous: [[SQL]]
Link: 

[TOC]

---

# Example

To find courses that ran in Fall 2017 and in Spring 2018:

```sql
(
	SELECT course_id 
	FROM section 
	WHERE sem = 'Fall' AND year = 2017
) INTERSECT (
	SELECT course_id
	FROM section
	WHERE sem = 'Spring' AND year = 2018
)
```

To retain duplicates, use `INTERSECT ALL`:

```sql
(
	SELECT course_id 
	FROM section 
	WHERE sem = 'Fall' AND year = 2017
) INTERSECT ALL (
	SELECT course_id
	FROM section
	WHERE sem = 'Spring' AND year = 2018
)
```

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 3: Introduction to SQL, Part 4.” Asynchronous Online Course, October 31, 2023. https://nycu1.sharepoint.com/sites/112-1IntroductiontoDatabaseSystems/_layouts/15/stream.aspx?id=%2Fsites%2F112%2D1IntroductiontoDatabaseSystems%2FShared%20Documents%2FGeneral%2FOnline%20learning%2FCh3%2FCh3%2D5%2DSet%2Emov&referrer=StreamWebApp%2EWeb&referrerScenario=AddressBarCopied%2Eview.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.