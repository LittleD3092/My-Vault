Tag: #Database
Previous: 
Link: 

[TOC]

---

# Chapter 1: Basics

## Architecture of Database System

![[Pasted image 20230914195151.png]]

The figure above shows an abstract architecture of database.

For a database to work, the following 3 things must be implemented:

- [[Database Engine]]
- [[Storage Manager]]
- [[Query Processor]]

## Data Models

Data models are the tools that describe

- The data.
- The relationships between data.
- Data semantics.
- Data constraints.

The most commonly used model is [[Relational Model|relational model]].

## Schemas and Instances

- [[Schema]]: type of data.
- [[Instance]]: variable.

In the following example, `int` is the [[Schema|schema]], and `a` is the [[Instance|instance]].

```
int a;
```

## Data Definition Language

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

## Data Manipulating Language

**Data Manipulating Language** (DML) is the language for accessing and updating the data stored.

> Note that:
> - DDL is for defining the data type (creating an empty table).
> - DML is for updating the data stored (modify the content in a table).

There are **two types** of DML, depending on whether user specifies the procedure of getting data:

- **Procedural DML**: Users specify what data is needed and how to get the data.
- **Declarative DML**: Users specify what data is needed. The way of getting data is automatically determined.

## SQL

SQL is a language that is **DDL** and also **Declarative DML**.

# Chapter 2: Relational Model

- [[Relational Model]]
- [[Relational Database]]
	- [[Attribute]]
	- [[Tuple]]
	- [[Keys]]
- [[Schema Diagram]]
- [[Relational Algebra]]
	- [[Select Operation]] $\sigma$
	- [[Project Operation]] $\Pi$
	- [[Cartesian Product of Database]] $\times$
	- [[Join Operation]] $\bowtie$
	- [[Union Operation]] $\cup$
	- [[Intersect Operation]] $\cap$
	- [[Set Difference Operation]] $-$
	- [[Assignment Operation]] $\leftarrow$
	- [[Rename Operation]] $\rho$

# Chapter 3: Introduction to SQL

- [[SQL]]
	- [[Domain Types of SQL]]
	- [[Create Table in SQL]]
	- [[Update Table in SQL]]
	- [[Delete Table in SQL]]
	- [[Select Clause in SQL]]

# Chapter 6: Entity-Relational Model

- [[Entity-Relational Model]]
	- [[Entity Set]]
	- [[Relationship Set]]
	- [[Attribute]]
- [[Mapping Cardinality Constraint]]

---

# Reference

- Tseng, Yi-Ju. “Chapter 2: Introduction to Relational Model.” NYCU ED117[GF], October 12, 2023.
- Tseng, Yi-Ju. “Chapter 6: Entity-Relational Model.” NYCU ED117[GF], October 12, 2023.
- Tseng, Yi-Ju. “Chapter 3: Introduction to SQL.” Asynchronous Online Course, October 15, 2023.
- Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 3: Introduction to SQL, Part 2.” Asynchronous Online Course, October 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.