# System-Programming-2---Ex2

## Project Description
This project implements a C++ class `SquareMat` for handling square matrices of double-precision floating-point numbers. The class provides a robust set of functionalities, including matrix arithmetic operations (addition, subtraction, multiplication, etc.), comparison operations, matrix exponentiation, transpose, determinant calculation, and more. The implementation is encapsulated within the `matrix` namespace and includes comprehensive error handling for invalid operations (e.g., mismatched matrix sizes, division by zero). The project also includes a test suite using the **doctest** framework to verify the correctness of the implementation.

The main components of the project are:
- `SquareMat.hpp`: Header file defining the `SquareMat` class and its interface.
- `SquareMat.cpp`: Implementation of the `SquareMat` class methods.
- `main.cpp`: A demonstration program showcasing basic matrix operations.
- `test.cpp`: Unit tests using the doctest framework to validate the class functionality.
---
## Compilation Instructions
The project includes a `Makefile` for easy compilation. To compile the project, follow these steps:

1. Ensure you have `g++` and `make` installed on your system.
2. Clone or download the project repository.
3. Navigate to the project directory in the terminal.
4. Run the following commands:

   ```
   # Compile the main program 
   make run

   # Compile and run the tests 
   make test

   # Compile the program with debugging symbols (already included in the Makefile with -g)
    make valgrind

   # Clean up generated files 
   make clean

## Usage Examples
The main.cpp file provides a simple demonstration of the SquareMat class. After compiling with `make run`, run the program and this will output:

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
##
The program demonstrates:
- Creating and initializing 2x2 matrices.
- Performing addition, subtraction, and unary negation.
- Handling errors (e.g., attempting to add matrices of different sizes).
---
## Test Suite Description
The project includes a comprehensive test suite in test.cpp, built using the doctest framework. The tests cover the following aspects of the SquareMat class:
Constructor and Basic Operations: Verifies matrix creation, copy constructor, assignment operator, and element access (get/set).

- Arithmetic Operations: Tests addition, subtraction, matrix multiplication, scalar multiplication, element-wise multiplication, scalar modulo, scalar division, and matrix exponentiation.
- Increment/Decrement: Validates pre- and post-increment/decrement operators.
- Transpose: Checks the matrix transpose operation.
- Comparison Operators: Tests equality, inequality, and comparison based on the sum of elements.
- Determinant: Verifies determinant calculation for 1x1, 2x2, and 3x3 matrices.
- Compound Assignment: Tests +=, -=, *=, /=, and %= operators.
- Output Stream: Ensures the output stream operator (<<) formats matrices correctly.

To run the tests:
`make test`
##
The test suite will report any failures or errors, ensuring the reliability of the SquareMat class.

---
This project was developed as part of the System Programming 2 course to demonstrate proficiency in C++ class design, operator overloading, memory management, and unit testing.



