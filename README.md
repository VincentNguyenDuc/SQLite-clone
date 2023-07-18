# SQLITE-CLONE
Rebuild a simple version of [Sqlite](https://www.sqlite.org/index.html) from scratch using C

## Table of Contents
- [SQLITE-CLONE](#sqlite-clone)
  - [Table of Contents](#table-of-contents)
  - [General Information](#general-information)
  - [Features](#features)
  - [Usage](#usage)
  - [Acknowledgement](#acknowledgement)


## General Information
- The main objective of this project: 
  - Attain a comprehensive understanding of the architecture of SQLite 
  - Strengthen proficiency in the C Programming Language E
  - Employ Test-Driven Development (TDD) using PyTest.


## Features
```bash
# Insert data into the database file (*.db):
$ insert {user_id} {user_name} {user_email}

# Retrieve all the available data within the database:
$ select

# Save and exit the database 
$ .exit

# A simple visualization of B-Tree, which worked as the underlying data structure
$ .btree
```


## Usage
```bash
# Compile everything => create the file: "db.out"
foo@bar:~$ make compile 

# Run test (PyTest)
foo@bar:~$ make test

# Create and connect to a new database / connect to an existing database 
foo@bar:~$ ./db.out {database_name}.db
```


## Acknowledgement
- This project was based on this [tutorial](https://github.com/cstack/db_tutorial)




