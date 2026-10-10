# Music Store Management System

## Project Information

- **Project Name:** Music Store Management System
- **Course Code:** IU2541230095 – CPP63
- **Language:** C++
- **Application Type:** Console-Based Application

## 1. Introduction

The Music Store Management System is a console-based C++ application designed to manage music store records and sales. It allows users to maintain artist, customer, and album information, process album sales, and generate sales reports.

The project demonstrates object-oriented programming concepts, dynamic memory allocation, file handling, input validation, and exception handling.

## 2. Objectives

- Maintain artist, customer, and album records.
- Search, update, display, and delete records.
- Process album sales and calculate transaction totals.
- Track album stock and validate sales quantities.
- Generate sales reports.
- Save and load records using files.
- Apply object-oriented programming concepts in a practical application.

## 3. Features

1. Add records.
2. Display records.
3. Search records.
4. Update records.
5. Delete records.
6. Process album sales.
7. Generate reports.
8. Save and load data.
9. Exit the application.

## 4. Object-Oriented Programming Concepts

- **Classes and Objects:** Used to represent people, artists, customers, albums, sales, and the store.
- **Encapsulation:** Data members and public member functions organize and control access to data.
- **Inheritance:** `Artist` and `Customer` derive from the `Person` class.
- **Polymorphism:** Virtual functions allow derived classes to provide their own display implementations.
- **Constructors and Destructors:** Used to initialize objects and manage object lifecycles.
- **Dynamic Memory Allocation:** Dynamic arrays store records.
- **File Handling:** Records are saved to and loaded from text files.
- **Exception Handling and Validation:** Used to handle invalid input and data errors where implemented.

## 5. Project Structure

- `main.cpp` — Main menu and program entry point.
- `Person.h`, `Person.cpp` — Base person class.
- `Artist.h`, `Artist.cpp` — Artist class.
- `Customer.h`, `Customer.cpp` — Customer class.
- `Album.h`, `Album.cpp` — Album class.
- `Sale.h`, `Sale.cpp` — Sales and transaction details.
- `MusicStore.h`, `MusicStore.cpp` — Main store management functionality.
- `FileManager.h`, `FileManager.cpp` — File saving and loading utilities.

## 6. Requirements

- Windows operating system or another compatible C++ environment.
- GCC/G++ compiler with C++11 or later support.
- Visual Studio Code or another code editor.

## 7. Compilation and Execution

Open a terminal in the project directory and compile the source files:

```bash
g++ main.cpp MusicStore.cpp Person.cpp Artist.cpp Customer.cpp Album.cpp Sale.cpp FileManager.cpp -o MusicStore.exe
```

Run the application in PowerShell:

```powershell
.\MusicStore.exe
```

The first command compiles the project. The second launches the compiled application.

## 8. Data Storage

The application uses text files to store records. The data files are created or updated when the application saves data. Keep these files in the appropriate working directory so that saved records can be loaded later.

## 9. Testing

The application should be tested for record management, search and update operations, deletion restrictions, sales calculations, stock validation, report generation, and file persistence. Refer to the project's test-case document for detailed test scenarios and results.

## 10. Conclusion

The Music Store Management System demonstrates how C++ and object-oriented programming can be used to build a practical record-management application. It combines record operations, transaction processing, reporting, and file persistence in a single console-based system.
