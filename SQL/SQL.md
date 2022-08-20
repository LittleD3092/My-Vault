標籤: #sql

---

[TOC]

---

# C.R.U.D

CRUD stands for the main four operations of SQL:

- Create
- Read
- Update
- Delete

# Types of Database

There are two types of database:

- Relational Databases (SQL)
	- This kind of databases are stored in tables
	- The database has a unique key identifies each row
- Non-Relational (noSQL/not just SQL)
	- All other types that is not SQL
	- JSON, BLOB, XML
	- [[Graph]]
	- Key-Value Hash

# Basics

SQL stands for "Standard Query Language". This language is used to interact with management systems. Although there are many different kinds of management systems, such as "mySQL", most of them use standard query language to operate.

## Query

A query is a request to the management systems, telling them to create, read, update or delete something. 

The idea of a query is to get the essential information from a bunch of data, only get you want.

## Key

There are different kind of keys:

- [[#Primary Key]]: use only one column
- [[#Foreign Key]]: link to the other table's row
- [[#Composite Key]]: use multiple columns to represent a key

### Primary Key

| id  | Name  |
| --- | ----- |
| 1   | Name1 |
| 2   | Name2 |
| 3   | Name3 | 

The `id` column of the above table is a primary key. We can use primary key to access a particular row, and two keys are never the same.

There are two types of primary key:

1. surrogate key: The key means nothing in real world, it is just a number.
2. natural key: The key has mapping to real world. For example, social security number is a natural key.

### Foreign Key

A foreign key is a link to other table's row. For example:

| id  | Name  | School_id |
| --- | ----- | --------- |
| 1   | Name1 | 1         |
| 2   | Name2 | 2         |
| 3   | Name3 | 2         |

| School_id | School Name |
| --------- | ----------- |
| 1         | NYCU        |
| 2         | NTU         | 

The `School_id` column has links to the second table, which has two schools. A foreign key is the way of implementing a relationship between two tables.

### Composite Key

A composite key is a [[#Primary Key]], but it uses two column to represent one key. In the following example, we use two columns `Class` and `Seat_Number` to represent a key.

| Class | Seat_Number | Name  |
| ----- | ----------- | ----- |
| 1     | 1           | Name1 |
| 1     | 2           | Name2 |
| 1     | 3           | Name3 |
| 2     | 1           | Name4 |
| 2     | 2           | Name5 |
| 2     | 3           | Name6 |

As you can see, any one of the two columns can't represent any particular row. In this case, a composite key is used.

---

參考資料:

[SQL tutorial - youtube](https://youtu.be/HXV3zeQKqGY)

---

link:

