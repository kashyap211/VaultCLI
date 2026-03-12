# PassVault-CPP 🔐

PassVault-CPP is a command-line password manager written in C++.
It allows users to store, search, update, and manage account credentials using file-based persistence.

The project was built to practice core C++ concepts such as object-oriented design, file handling, STL containers, and modular project structure.

---

## Features

* Add new account credentials
* View all stored accounts
* Search account by site name
* Partial search (search by keyword)
* Update username or password
* Delete stored accounts
* Data persistence using a text file

---

## Project Structure

```
PasswordManager/
│
├── main.cpp        # User interface and program flow
├── storage.h       # Storage class declaration
├── storage.cpp     # Storage logic (file handling and account management)
├── account.h       # Account class declaration
├── account.cpp     # Account class implementation
└── pwd.txt         # Stored credentials (generated at runtime)
```

---

## Architecture

The program follows a simple layered design:

```
Main (UI)
   ↓
Storage (account management + file persistence)
   ↓
Account (data model)
   ↓
pwd.txt (file database)
```

---

## Example Data Format

Accounts are stored in a text file in the format:

```
site|username|password
```

Example:

```
github.com|dev_user|mypassword123
google.com|mail_user|securepass
```

---

## How to Compile and Run

Compile the program:

```
g++ main.cpp storage.cpp account.cpp -o main
```

Run the program:

```
./main
```

---

## Concepts Used

* Object-Oriented Programming (Classes & Encapsulation)
* STL Containers (`unordered_map`)
* File Handling (`ifstream`, `ofstream`)
* String processing
* Iterators and range-based loops
* Modular multi-file C++ projects

---

## Future Improvements

* Password generator
* Master password protection
* Encryption for stored credentials
* Case-insensitive search
* Export/backup functionality

---

## Purpose

This project was created as a learning exercise to build a small but functional system from scratch in C++. It demonstrates how to design a modular program and manage persistent data without external libraries.

---
