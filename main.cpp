#include "SquareMat.hpp"
#include <iostream>

int main() {
    try {
        // Creating two 2x2 matrices.
        matrix::SquareMat mat1(2);
        mat1.set(0, 0, 1.0);
        mat1.set(0, 1, 2.0);
        mat1.set(1, 0, 3.0);
        mat1.set(1, 1, 4.0);

        matrix::SquareMat mat2(2);
        mat2.set(0, 0, 5.0);
        mat2.set(0, 1, 6.0);
        mat2.set(1, 0, 7.0);
        mat2.set(1, 1, 8.0);

        std::cout << "Matrix 1:" << std::endl;
        mat1.print();
        std::cout << "\nMatrix 2:" << std::endl;
        mat2.print();

        // Testing the addition operator.
        matrix::SquareMat sum_mat = mat1 + mat2;
        std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
        sum_mat.print();

        // Testing the subtraction operator.
        matrix::SquareMat diff_mat = mat2 - mat1;
        std::cout << "\nMatrix 2 - Matrix 1:" << std::endl;
        diff_mat.print();

        // Testing the unary minus operator.
        matrix::SquareMat neg_mat1 = -mat1;
        std::cout << "\n-Matrix 1:" << std::endl;
        neg_mat1.print();

        // Trying to add matrices of different sizes (will throw an exception).
        matrix::SquareMat mat3(3);
        try {
            matrix::SquareMat invalid_sum = mat1 + mat3;
            std::cout << "\nThis should not be printed." << std::endl;
            invalid_sum.print();
        } catch (const std::invalid_argument& e) {
            std::cerr << "\nError: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}