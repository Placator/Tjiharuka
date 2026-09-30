# Municipal Financial Management System (MFMS)

## Course
PAP521S – Programming in Practice

## Project A
Municipal Financial Management System – Foundation System

## Language
ANSI C (C99)

## Development Environment
Visual Studio Code + GCC

## Description
This project is a menu-driven Municipal Financial Management System developed in C. It provides basic employee, budget, supplier, asset and reporting functions as required for Project A.

## Features
- Employee management
- Employee salary calculation
- Employee search
- Budget management and remaining-budget calculation
- Budget status and exceeded-budget identification
- Supplier management and search
- Asset register and search
- Employee, budget, supplier and asset reports
- Input validation for numerical values and empty text fields
- Modular C source and header files

## Project Structure
```text
MFMS/
├── main.c
├── employees.c
├── employees.h
├── budget.c
├── budget.h
├── suppliers.c
├── suppliers.h
├── assets.c
├── assets.h
├── reports.c
├── reports.h
└── README.md
```

## Compilation
Open a terminal in the MFMS folder and run:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## Run
Windows:
```text
mfms.exe
```

Linux/macOS:
```text
./mfms
```

## Individual Implementation
The system is modular so that each module can be understood, tested and explained independently. The implementation covers the foundation requirements of Project A.
