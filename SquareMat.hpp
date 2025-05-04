#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <stdexcept>
#include <iostream>

namespace matrix {

/**
 * @brief Represents a square matrix of double-precision floating-point numbers.
 */
class SquareMat {
private:
    int size;
    double** data;
    /**
     * @brief Helper function to calculate the sum of all elements in the matrix.
     */
    double sum() const;
    /**
     * @brief Creates a sub-matrix by excluding a given row and column.
     */
    SquareMat getSubMatrix(int rowToRemove, int colToRemove) const;

    /**
     * @brief Recursively calculates the determinant of the matrix.
     */
    double determinant() const;

public:
/**
 * @brief Constructor for the SquareMat class.
 */
SquareMat(int size);

/**
 * @brief Copy constructor for the SquareMat class.
 */
SquareMat(const SquareMat& other);

/**
 * @brief Assignment operator for the SquareMat class.
 */
SquareMat& operator=(const SquareMat& other);

/**
 * @brief Destructor for the SquareMat class.
 */
~SquareMat();

/**
 * @brief Gets the value of the element at the specified row and column.
 */
double get(int row, int col) const;

/**
 * @brief Sets the value of the element at the specified row and column.
 */
void set(int row, int col, double value);

/**
 * @brief Gets the size (dimension) of the square matrix.
 */
int getSize() const;

/**
 * @brief Prints the matrix elements to the standard output.
 */
void print() const;

/**
 * @brief Overloads the addition operator (+) for matrix addition.
 */
SquareMat operator+(const SquareMat& other) const;

/**
 * @brief Overloads the subtraction operator (-) for matrix subtraction.
 */
SquareMat operator-(const SquareMat& other) const;

/**
 * @brief Overloads the unary minus operator (-) for negation.
 */
SquareMat operator-() const;

/**
 * @brief Overloads the subscript operator [] for accessing rows (non-const version).
 */
double* operator[](int row);

/**
 * @brief Overloads the subscript operator [] for accessing rows (const version).
 */
const double* operator[](int row) const;
/**
 * @brief Overloads the equality operator (==) for comparing two matrices.
 */
bool operator==(const SquareMat& other) const;

/**
 * @brief Overloads the inequality operator (!=) for comparing two matrices.
 */
bool operator!=(const SquareMat& other) const;

/**
 * @brief Overloads the multiplication operator (*) for matrix multiplication.
 */
SquareMat operator*(const SquareMat& other) const;

/**
 * @brief Overloads the multiplication operator (*) for scalar multiplication (matrix * scalar).
 */
SquareMat operator*(double scalar) const;

friend /**
 * @brief Overloads the multiplication operator (*) for scalar multiplication (scalar * matrix).
 */
SquareMat operator*(double scalar, const SquareMat& matrix);

/**
 * @brief Overloads the modulo operator (%) for element-wise matrix multiplication.
 */
SquareMat operator%(const SquareMat& other) const;

/**
 * @brief Overloads the modulo operator (%) for scalar modulo (matrix % scalar).
 */
SquareMat operator%(double scalar) const;

/**
 * @brief Overloads the division operator (/) for scalar division (matrix / scalar).
 */
SquareMat operator/(double scalar) const;

/**
 * @brief Overloads the bitwise XOR operator (^) for matrix exponentiation (simple implementation).
 */
SquareMat operator^(int exponent) const;

/**
 * @brief Overloads the pre-increment operator (++mat).
 */
SquareMat& operator++();

/**
 * @brief Overloads the pre-decrement operator (--mat).
 */
SquareMat& operator--();

/**
 * @brief Overloads the post-increment operator (mat++).
 */
SquareMat operator++(int);

/**
 * @brief Overloads the post-decrement operator (mat--).
 */
SquareMat operator--(int);

/**
 * @brief Overloads the bitwise NOT operator (~) for matrix transpose.
 */
SquareMat operator~() const;

/**
 * @brief Overloads the less than operator (<) to compare the sum of elements of two matrices.
 */
bool operator<(const SquareMat& other) const;

/**
 * @brief Overloads the greater than operator (>) to compare the sum of elements of two matrices.
 */
bool operator>(const SquareMat& other) const;

/**
 * @brief Overloads the less than or equal to operator (<=) to compare the sum of elements of two matrices.
 */
bool operator<=(const SquareMat& other) const;

/**
 * @brief Overloads the greater than or equal to operator (>=) to compare the sum of elements of two matrices.
 */
bool operator>=(const SquareMat& other) const;

/**
 * @brief Overloads the logical NOT operator (!) to calculate the determinant of the matrix.
 */
double operator!() const;

/**
 * @brief Overloads the compound addition assignment operator (+=).
 */
SquareMat& operator+=(const SquareMat& other);

/**
 * @brief Overloads the compound subtraction assignment operator (-=).
 */
SquareMat& operator-=(const SquareMat& other);

/**
 * @brief Overloads the compound multiplication assignment operator (*=) for matrix multiplication.
 */
SquareMat& operator*=(const SquareMat& other);

/**
 * @brief Overloads the compound division assignment operator (/=) for scalar division.
 */
SquareMat& operator/=(double scalar);

/**
 * @brief Overloads the compound modulo assignment operator (%=) for scalar modulo.
 */
 SquareMat& operator%=(double scalar);

friend std::ostream& operator<<(std::ostream& os, const SquareMat& matrix);
};
} // namespace matrix

#endif // SQUARE_MAT_HPP