標籤: #sql 

---

[TOC]

---

SQL is both [[Data Manipulating Language|data manipulating language]] and [[Data Definition Language|data definition language]].

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

- [[Select Clause in SQL]]

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

# Useful Commands

The following commands are useful commands that may come in handy.

## Check Active

The mysql server should be active on your computer so that you can send request to it. To check whether mysql server is active, use the following command.

```bash
sudo service mysql status
```

## Enter mysql Console

The following command shows how to enter mysql with root user. If you need to log in using other user's account, simply change the `root` to the user name you chose.

```bash
sudo mysql -u root -p
```

- `-u [user]`: This option specified the username.
- `-p`: This option enables password log in. If the account need a password but you didn't pass this option, an error will occur.

## Run Script

You can write all the code in mysql console, but you may write all queries beforehand as a script. The script should be saved with file extension `[file_name].sql`.

The following command will import the `[script_name].sql` file, and execute the script in database `[database_name]`.

```bash
sudo mysql -u root -p [database_name] < [script_name].sql
```

## Show Databases

To see all database, you need to enter the following line in sql console.

```sql
SHOW DATABASES
```

# Data types

- [[Domain Types of SQL]]

# Manipulating Tables

- [[Create Table in SQL]]
- [[Show Information of a Table in SQL]]
- [[Update Table in SQL]]
- [[Delete Table in SQL]]
- [[Select Clause in SQL]]
- [[Rename Operation in SQL]]
- [[String Operation in SQL]]

---

參考資料:

- [SQL tutorial - youtube](https://youtu.be/HXV3zeQKqGY)
- Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 3: Introduction to SQL, Part 2.” Asynchronous Online Course, October 22, 2023.

---

link:

