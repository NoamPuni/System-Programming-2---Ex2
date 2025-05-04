#include "SquareMat.hpp"
#include <iostream>
#include <cmath> // For std::pow

namespace matrix {

// Private helper function to calculate the sum of all elements.
double matrix::SquareMat::sum() const {
    double totalSum = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            totalSum += data[i][j];
        }
    }
    return totalSum;
}

// Private helper function to recursively calculate the determinant.
double matrix::SquareMat::determinant() const {
    if (size == 1) {
        return (*this)[0][0];
    }
    if (size == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }
    double det = 0.0;
    for (int j = 0; j < size; ++j) {
        SquareMat sub = getSubMatrix(0, j);
        det += (*this)[0][j] * std::pow(-1, j) * sub.determinant();
    }
    return det;
}

// Constructor that initializes a square matrix of the given size with zeros.
SquareMat::SquareMat(int size) : size(size), data(nullptr) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size must be a positive integer.");
    }
    // Allocate memory for the array of row pointers
    data = new double*[size];
    
    // Allocate memory for each row (array of doubles) and initialize to zero
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        if (!data[i]) {
            // If allocation fails in the middle, release previously allocated memory
            for (int j = 0; j < i; ++j) {
                delete[] data[j];
            }
            delete[] data;
            throw std::bad_alloc();
        }
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0.0;
        }
    }
}

// Copy constructor
SquareMat::SquareMat(const SquareMat& other) : size(other.size), data(nullptr) {
    // Allocate memory for the new matrix
    data = new double*[size];

    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        if (!data[i]) {
            for (int j = 0; j < i; ++j) {
                delete[] data[j];
            }
            delete[] data;
            throw std::bad_alloc();
        }
        // Copy values from the other matrix
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Assignment operator
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) {
        return *this; // Handle self-assignment (mat = mat;)
    }
    // If the sizes are different, need to deallocate current memory and allocate new
    if (size != other.size) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
        size = other.size;
        data = new double*[size];

        for (int i = 0; i < size; ++i) {
            data[i] = new double[size];
            if (!data[i]) {
                for (int j = 0; j < i; ++j) {
                    delete[] data[j];
                }
                delete[] data;
                throw std::bad_alloc();
            }
        }
    }
    // Copy values from the other matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

// Destructor
SquareMat::~SquareMat() {
    if (data) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
        size = 0;
    }
}
// Method to get the value of a matrix element
double SquareMat::get(int row, int col) const {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
    return data[row][col];
}
// Method to set the value of a matrix element
void SquareMat::set(int row, int col, double value) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
    data[row][col] = value;
}

// Method to get the size of the matrix
int SquareMat::getSize() const {
    return size;
}

// Method to print the matrix
void SquareMat::print() const {
    std::cout << "M_" << size << "x" << size << "_:(R)" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < size; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << " ]" << std::endl;
    }
}

// Overloads the addition operator (+) for matrix addition.
matrix::SquareMat matrix::SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for addition.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Overloads the subtraction operator (-) for matrix subtraction.
matrix::SquareMat matrix::SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for subtraction.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Overloads the unary minus operator (-) for negation.
matrix::SquareMat matrix::SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = -(this->data[i][j]);
        }
    }
    return result;
}
// Overloads the subscript operator [] for accessing rows (non-const version).
double* matrix::SquareMat::operator[](int row) {
    if (row < 0 || row >= size) {
        throw std::out_of_range("Row index out of bounds.");
    }
    return data[row];
}

// Overloads the subscript operator [] for accessing rows (const version).
const double* matrix::SquareMat::operator[](int row) const {
    if (row < 0 || row >= size) {
        throw std::out_of_range("Row index out of bounds.");
    }
    return data[row];
}

// Overloads the equality operator (==) to compare two matrices based on the sum of their elements.
bool matrix::SquareMat::operator==(const SquareMat& other) const {
    return this->sum() == other.sum();
}

// Overloads the inequality operator (!=) for comparing two matrices.
bool matrix::SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

// Overloads the multiplication operator (*) for matrix multiplication.
matrix::SquareMat matrix::SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for multiplication.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double sum = 0.0;
            for (int k = 0; k < size; ++k) {
                sum += (*this)[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

// Overloads the multiplication operator (*) for scalar multiplication (matrix * scalar).
matrix::SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = (*this)[i][j] * scalar;
        }
    }
    return result;
}

// Overloads the multiplication operator (*) for scalar multiplication (scalar * matrix).
matrix::SquareMat operator*(double scalar, const SquareMat& matrix) {
    return matrix * scalar; // Reuse the member operator for efficiency.
}

// Overloads the modulo operator (%) for element-wise matrix multiplication.
matrix::SquareMat matrix::SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for element-wise multiplication.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = (*this)[i][j] * other[i][j];
        }
    }
    return result;
}

// Overloads the modulo operator (%) for scalar modulo (matrix % scalar).
matrix::SquareMat matrix::SquareMat::operator%(double scalar) const {
    if (static_cast<int>(scalar) == 0) {
        throw std::invalid_argument("Cannot perform modulo with a scalar of zero.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = static_cast<int>((*this)[i][j]) % static_cast<int>(scalar);
        }
    }
    return result;
}

// Overloads the division operator (/) for scalar division (matrix / scalar).
matrix::SquareMat matrix::SquareMat::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Cannot divide by a scalar of zero.");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = (*this)[i][j] / scalar;
        }
    }
    return result;
}

// Overloads the bitwise XOR operator (^) for matrix exponentiation (simple implementation).
matrix::SquareMat matrix::SquareMat::operator^(int exponent) const {
    if (exponent < 0) {
        throw std::invalid_argument("Exponent must be a non-negative integer.");
    }

    if (exponent == 0) {
        // Any matrix to the power of 0 is the identity matrix.
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1.0;
        }
        return result;
    }

    SquareMat result = *this; // Start with a copy of the original matrix.

    // Multiply the result by the original matrix (exponent - 1) times.
    for (int i = 1; i < exponent; ++i) {
        result = result * (*this);
    }

    return result;
}

// Overloads the pre-increment operator (++mat).
matrix::SquareMat& matrix::SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j]++;
        }
    }
    return *this;
}

// Overloads the pre-decrement operator (--mat).
matrix::SquareMat& matrix::SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j]--;
        }
    }
    return *this;
}

// Overloads the post-increment operator (mat++).
matrix::SquareMat matrix::SquareMat::operator++(int) {
    SquareMat temp = *this; // Create a copy of the current matrix.
    ++(*this);             // Call the pre-increment operator.
    return temp;           // Return the original copy.
}

// Overloads the post-decrement operator (mat--).
matrix::SquareMat matrix::SquareMat::operator--(int) {
    SquareMat temp = *this; // Create a copy of the current matrix.
    --(*this);             // Call the pre-decrement operator.
    return temp;           // Return the original copy.
}

// Overloads the bitwise NOT operator (~) for matrix transpose.
matrix::SquareMat matrix::SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[j][i] = (*this)[i][j];
        }
    }
    return result;
}

// Overloads the less than operator (<) to compare the sum of elements of two matrices.
bool matrix::SquareMat::operator<(const SquareMat& other) const {
    return this->sum() < other.sum();
}

// Overloads the greater than operator (>) to compare the sum of elements of two matrices.
bool matrix::SquareMat::operator>(const SquareMat& other) const {
    return this->sum() > other.sum();
}

// Overloads the less than or equal to operator (<=) to compare the sum of elements of two matrices.
bool matrix::SquareMat::operator<=(const SquareMat& other) const {
    return this->sum() <= other.sum();
}

// Overloads the greater than or equal to operator (>=) to compare the sum of elements of two matrices.
bool matrix::SquareMat::operator>=(const SquareMat& other) const {
    return this->sum() >= other.sum();
}



// Private helper function to create a sub-matrix.
matrix::SquareMat matrix::SquareMat::getSubMatrix(int rowToRemove, int colToRemove) const {
    if (size <= 1) {
        throw std::invalid_argument("Cannot create a sub-matrix of a 1x1 or smaller matrix.");
    }
    SquareMat subMatrix(size - 1);
    int currentRow = 0;
    for (int i = 0; i < size; ++i) {
        if (i != rowToRemove) {
            int currentCol = 0;
            for (int j = 0; j < size; ++j) {
                if (j != colToRemove) {
                    subMatrix[currentRow][currentCol] = (*this)[i][j];
                    currentCol++;
                }
            }
            currentRow++;
        }
    }
    return subMatrix;
}

// Overloads the logical NOT operator (!) to calculate the determinant of the matrix.
double matrix::SquareMat::operator!() const {
    return this->determinant();
}

// Overloads the compound addition assignment operator (+=).
matrix::SquareMat& matrix::SquareMat::operator+=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for addition assignment.");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += other[i][j];
        }
    }
    return *this;
}

// Overloads the compound subtraction assignment operator (-=).
matrix::SquareMat& matrix::SquareMat::operator-=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for subtraction assignment.");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= other[i][j];
        }
    }
    return *this;
}

// Overloads the compound multiplication assignment operator (*=) for matrix multiplication.
matrix::SquareMat& matrix::SquareMat::operator*=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same size for multiplication assignment.");
    }
    SquareMat temp = *this * other; // Use the regular multiplication operator.
    *this = temp;                   // Assign the result back to this matrix.
    return *this;
}

// Overloads the compound division assignment operator (/=) for scalar division.
matrix::SquareMat& matrix::SquareMat::operator/=(double scalar) {
    if (scalar == 0.0) {
        throw std::invalid_argument("Cannot divide by a scalar of zero.");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] /= scalar;
        }
    }
    return *this;
}

// Overloads the compound modulo assignment operator (%=) for scalar modulo.
matrix::SquareMat& matrix::SquareMat::operator%=(double scalar) {
    if (static_cast<int>(scalar) == 0) {
        throw std::invalid_argument("Cannot perform modulo with a scalar of zero.");
    }
    SquareMat result(size); // Create a temporary matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = static_cast<int>(data[i][j]) % static_cast<int>(scalar);
        }
    }
    *this = result; // Copy the results back to the original matrix
    return *this;
}

// Overloads the output stream operator (<<) for the SquareMat class.
std::ostream& operator<<(std::ostream& os, const SquareMat& matrix) {
    os << "M_" << matrix.getSize() << "x" << matrix.getSize() << ":\n";
    for (int i = 0; i < matrix.getSize(); ++i) {
        os << "[ ";
        for (int j = 0; j < matrix.getSize(); ++j) {
            os << matrix[i][j] << (j == matrix.getSize() - 1 ? "" : " ");
        }
        os << " ]\n";
    }
    return os;
}

} // namespace matrix