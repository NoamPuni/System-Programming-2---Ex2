# System Programming 2 — Exercise 2: Square Matrices

This project implements a C++ class `SquareMat` for handling square matrices of `double` values.  
It provides a comprehensive set of features including arithmetic operations, matrix exponentiation, comparison operators, and more.

## Project Structure

The project includes the following files:

- `SquareMat.hpp` — Header file defining the `SquareMat` class.
- `SquareMat.cpp` — Implementation of the class methods.
- `main.cpp` — Demonstration program showcasing basic matrix usage.
- `test.cpp` — Unit tests using the **doctest** framework.
- `Makefile` — Simplifies the build and testing process.
- `.vscode/` — VS Code configuration files (optional).
- `doctest.h` — Embedded testing framework.

---

## Compilation Instructions

Make sure you have `g++` and `make` installed. Then, follow these steps:

1. Clone or download the repository.
2. Open a terminal in the project directory.
3. Run the following commands:

```bash
# Compile and run the main demo
make run

# Compile and run the test suite
make test

# Compile with debugging symbols (for Valgrind)
make valgrind

# Clean build files
make clean
```

---

## Usage Example

After running `make run`, the output will look something like this:

```
Matrix 1:
M_2x2_:(R)
[ 1 2 ]
[ 3 4 ]

Matrix 2:
M_2x2_:(R)
[ 5 6 ]
[ 7 8 ]

Matrix 1 + Matrix 2:
M_2x2_:(R)
[ 6 8 ]
[ 10 12 ]

Matrix 2 - Matrix 1:
M_2x2_:(R)
[ 4 4 ]
[ 4 4 ]

-Matrix 1:
M_2x2_:(R)
[ -1 -2 ]
[ -3 -4 ]

Error: Matrices must have the same size for addition.
```

The program demonstrates:
- Matrix initialization and display
- Addition, subtraction, and unary negation
- Error handling for size mismatches

---

## Test Suite

The test suite in `test.cpp` uses the [doctest](https://github.com/doctest/doctest) framework and verifies:

- **Constructors and Basic Access**
  - Matrix creation
  - Copy constructor
  - Assignment operator
  - Element access via `[]` and `get/set`
  
- **Arithmetic Operations**
  - Matrix +, -, * (with matrix and scalar)
  - Element-wise multiplication
  - Division, modulo, exponentiation

- **Increment / Decrement**
  - Pre- and post- increment/decrement

- **Transpose Operation**

- **Comparison Operators**
  - `==`, `!=`, `<`, `>`, `<=`, `>=` (based on matrix sum)

- **Determinant**
  - For 1x1, 2x2, and 3x3 matrices

- **Compound Assignment**
  - `+=`, `-=`, `*=`, `/=`, `%=`

- **Output Formatting**
  - Operator `<<` for matrix printing

### To run tests:

```bash
make test
```

---

## About

This project was developed as part of the **System Programming 2** course.  
It demonstrates advanced C++ concepts including:

- Class design and encapsulation  
- Operator overloading  
- Memory management  
- Unit testing  
- Exception handling

---
