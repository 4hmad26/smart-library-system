# Library Management System (C++)
## About This Project

This is a simple console-based Library Management System written in C++.
It helps manage books in a library using basic file handling and object-oriented programming concepts.

The system allows you to:

* Add new books
* View all books
* Search books by ID
* Issue books
* Return books

All data is stored permanently in a file (`library.dat`), so records are not lost after the program closes.

# Features

* Uses **OOP concepts** (Classes & Objects)
* Uses **Binary File Handling**
* Menu-driven program (easy to use)
* Automatically loads saved data on startup

##  How It Works

* `Book` class stores book details (ID, title, author, copies)
* `Library` class manages all operations
* Data is saved in `library.dat` file
* Program loads data automatically when it starts

## How to Run

1. Make sure you have a C++ compiler (GCC / MinGW)
2. Compile the program:

```
g++ library.cpp -o library
```

3. Run the program:

```
./library
```

## Menu Options

```
1. Add Book
2. Display All Books
3. Search Book
4. Issue Book
5. Return Book
0. Exit
```

##  File Used

* `library.dat` → Stores all book records in binary format


##  Author
Mohd Ahmad
(BCA Student)

✨ Simple • Clean • Beginner Friendly
