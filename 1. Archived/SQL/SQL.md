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

The following data types are the basic data types that are often used while writing sql.

| Data types      | Description                                                                                                                                                |
| --------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `INT`           | Integer with range -2147483648 to 2147483647                                                                                                               |
| `DECIMAL(M, N)` | Floating point number, `M` is the total number of digits, `N` is the number of digits after point. <br> For example, `3.24` will have `M = 3` and `N = 2`. |
| `VARCHAR(l)`    | A string with maximum length `l`.                                                                                                                          |
| `BLOB`          | Binary large objects, such as pictures and files.                                                                                                          |
| `DATE`          | A date in format `YYYY-MM-DD`.                                                                                                                             |
| `TIMESTAMP`     | A time (with date) in format `YYYY-MM-DD HH:MM:SS`.                                                                                                        |

# Manipulating Tables

## Create Tables

To create table, you need to specify the name of the table, and put the name and [[#Data types]] of columns in parantheses.

```sql
CREATE TABLE [table_name](
    [row_name_1] [data_type_1] PRIMARY KEY,
    [row_name_2] [data_type_2],
    [row_name_3] [data_type_3],
    ...
);
```

For example, we create a table with name `student` and has data `student_id`, `name`, and `major`:

```sql
CREATE TABLE student(
    student_id INT PRIMARY KEY,
    name       VARCHAR(20),
	major      VARCHAR(20)
);
```

Note that we can also specify `PRIMARY KEY` like this:

```sql
CREATE TABLE student(
    student_id INT PRIMARY KEY,
    name       VARCHAR(20),
    major      VARCHAR(20),
    PRIMARY KEY(student_id)
);
```

## Show Information of a Table

Sometimes it is useful to show the information of a table because we may forget what format it is. The following line will print a description of a table, including the name and [[#Data types]] of all columns.

```sql
DESCRIBE [table_name];
```

## Delete Table

You can delete table using the following line:

```sql
DROP TABLE [table_name];
```

## Add or Delete Column

Sometimes we need to add or delete a column from our table. In this case, we use `ALTER TABLE [table_name]`, and specify the action after this.

```sql
ALTER TABLE [table_name] ADD [column_name] [data_type];
ALTER TABLE [table_name] DROP COLUMN [column_name];
```

---

參考資料:

[SQL tutorial - youtube](https://youtu.be/HXV3zeQKqGY)

---

link:

