#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept>

// Helper function to compare matrices for equality (within a tolerance)
bool areMatricesEqual(const matrix::SquareMat& mat1, const matrix::SquareMat& mat2, double tolerance = 1e-6) {
    if (mat1.getSize() != mat2.getSize()) {
        return false;
    }
    for (int i = 0; i < mat1.getSize(); ++i) {
        for (int j = 0; j < mat1.getSize(); ++j) {
            if (std::abs(mat1[i][j] - mat2[i][j]) > tolerance) {
                return false;
            }
        }
    }
    return true;
}

TEST_CASE("SquareMat Constructor and Basic Operations") {
    matrix::SquareMat mat1(3);
    CHECK(mat1.getSize() == 3);
    CHECK_THROWS_AS(matrix::SquareMat(0), std::invalid_argument);

    matrix::SquareMat mat2(2);
    mat2[0][0] = 1.0;
    mat2[0][1] = 2.0;
    mat2[1][0] = 3.0;
    mat2[1][1] = 4.0;

    matrix::SquareMat mat3 = mat2; // Copy constructor
    CHECK(areMatricesEqual(mat2, mat3));

    matrix::SquareMat mat4(2);
    mat4 = mat2; // Assignment operator
    CHECK(areMatricesEqual(mat2, mat4));

    CHECK(mat2.get(0, 0) == 1.0);
    mat2.set(0, 0, 5.0);
    CHECK(mat2.get(0, 0) == 5.0);
    CHECK_THROWS_AS(mat2.get(5, 0), std::out_of_range);
    CHECK_THROWS_AS(mat2.set(0, 5, 1.0), std::out_of_range);
}

TEST_CASE("SquareMat Arithmetic Operations") {
    matrix::SquareMat mat1(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat1[1][0] = 3.0;
    mat1[1][1] = 4.0;

    matrix::SquareMat mat2(2);
    mat2[0][0] = 5.0;
    mat2[0][1] = 6.0;
    mat2[1][0] = 7.0;
    mat2[1][1] = 8.0;

    matrix::SquareMat sumMat = mat1 + mat2;
    CHECK(sumMat[0][0] == 6.0);
    CHECK(sumMat[0][1] == 8.0);
    CHECK(sumMat[1][0] == 10.0);
    CHECK(sumMat[1][1] == 12.0);

    matrix::SquareMat diffMat = mat2 - mat1;
    CHECK(diffMat[0][0] == 4.0);
    CHECK(diffMat[0][1] == 4.0);
    CHECK(diffMat[1][0] == 4.0);
    CHECK(diffMat[1][1] == 4.0);

    matrix::SquareMat negMat = -mat1;
    CHECK(negMat[0][0] == -1.0);
    CHECK(negMat[0][1] == -2.0);
    CHECK(negMat[1][0] == -3.0);
    CHECK(negMat[1][1] == -4.0);

    matrix::SquareMat multMat = mat1 * mat2;
    CHECK(multMat[0][0] == 19.0);
    CHECK(multMat[0][1] == 22.0);
    CHECK(multMat[1][0] == 43.0);
    CHECK(multMat[1][1] == 50.0);

    matrix::SquareMat scalarMultMat1 = mat1 * 2.0;
    matrix::SquareMat scalarMultMat2 = 2.0 * mat1;
    CHECK(areMatricesEqual(scalarMultMat1, scalarMultMat2));
    CHECK(scalarMultMat1[0][0] == 2.0);
    CHECK(scalarMultMat1[0][1] == 4.0);
    CHECK(scalarMultMat1[1][0] == 6.0);
    CHECK(scalarMultMat1[1][1] == 8.0);

    matrix::SquareMat elemMultMat = mat1 % mat2;
    CHECK(elemMultMat[0][0] == 5.0);
    CHECK(elemMultMat[0][1] == 12.0);
    CHECK(elemMultMat[1][0] == 21.0);
    CHECK(elemMultMat[1][1] == 32.0);

    matrix::SquareMat moduloMat = mat1 % 2.0;
    CHECK(moduloMat[0][0] == 1.0);
    CHECK(moduloMat[0][1] == 0.0);
    CHECK(moduloMat[1][0] == 1.0);
    CHECK(moduloMat[1][1] == 0.0);

    matrix::SquareMat divMat = mat1 / 2.0;
    CHECK(divMat[0][0] == 0.5);
    CHECK(divMat[0][1] == 1.0);
    CHECK(divMat[1][0] == 1.5);
    CHECK(divMat[1][1] == 2.0);

    matrix::SquareMat powMat = mat1 ^ 2;
    CHECK(areMatricesEqual(powMat, mat1 * mat1));

    CHECK_THROWS_AS(mat1 + matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 - matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 * matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 % matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 % 0.0, std::invalid_argument);
    CHECK_THROWS_AS(mat1 / 0.0, std::invalid_argument);
    CHECK_THROWS_AS(mat1 ^ -1, std::invalid_argument);
}

TEST_CASE("SquareMat Increment/Decrement") {
    matrix::SquareMat mat1(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat1[1][0] = 3.0;
    mat1[1][1] = 4.0;

    ++mat1;
    CHECK(mat1[0][0] == 2.0);
    CHECK(mat1[0][1] == 3.0);
    CHECK(mat1[1][0] == 4.0);
    CHECK(mat1[1][1] == 5.0);

    --mat1;
    CHECK(mat1[0][0] == 1.0);
    CHECK(mat1[0][1] == 2.0);
    CHECK(mat1[1][0] == 3.0);
    CHECK(mat1[1][1] == 4.0);

    matrix::SquareMat mat2 = mat1++;
    CHECK(mat2[0][0] == 1.0);
    CHECK(mat2[0][1] == 2.0);
    CHECK(mat2[1][0] == 3.0);
    CHECK(mat2[1][1] == 4.0);
    CHECK(mat1[0][0] == 2.0);
    CHECK(mat1[0][1] == 3.0);
    CHECK(mat1[1][0] == 4.0);
    CHECK(mat1[1][1] == 5.0);

    matrix::SquareMat mat3 = mat1--;
    CHECK(mat3[0][0] == 2.0);
    CHECK(mat3[0][1] == 3.0);
    CHECK(mat3[1][0] == 4.0);
    CHECK(mat3[1][1] == 5.0);
    CHECK(mat1[0][0] == 1.0);
    CHECK(mat1[0][1] == 2.0);
    CHECK(mat1[1][0] == 3.0);
    CHECK(mat1[1][1] == 4.0);
}

TEST_CASE("SquareMat Transpose") {
    matrix::SquareMat mat1(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat1[1][0] = 3.0;
    mat1[1][1] = 4.0;

    matrix::SquareMat transMat = ~mat1;
    CHECK(transMat[0][0] == 1.0);
    CHECK(transMat[0][1] == 3.0);
    CHECK(transMat[1][0] == 2.0);
    CHECK(transMat[1][1] == 4.0);
}

TEST_CASE("SquareMat Comparison Operators") {
    matrix::SquareMat mat1(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat1[1][0] = 3.0;
    mat1[1][1] = 4.0; // Sum = 10

    matrix::SquareMat mat2(2);
    mat2[0][0] = 5.0;
    mat2[0][1] = 1.0;
    mat2[1][0] = 2.0;
    mat2[1][1] = 2.0; // Sum = 10

    matrix::SquareMat mat3(2);
    mat3[0][0] = 1.0;
    mat3[0][1] = 2.0;
    mat3[1][0] = 3.0;
    mat3[1][1] = 5.0; // Sum = 11

    CHECK(mat1 == mat2);
    CHECK(mat1 != mat3);
    CHECK(mat1 < mat3);
    CHECK(mat3 > mat1);
    CHECK(mat1 <= mat3);
    CHECK(mat3 >= mat1);
    CHECK(mat1 <= mat2);
    CHECK(mat1 >= mat2);
}

TEST_CASE("SquareMat Determinant") {
    matrix::SquareMat mat1(1);
    mat1[0][0] = 5.0;
    CHECK(!mat1 == 5.0);

    matrix::SquareMat mat2(2);
    mat2[0][0] = 1.0;
    mat2[0][1] = 2.0;
    mat2[1][0] = 3.0;
    mat2[1][1] = 4.0;
    CHECK(!mat2 == -2.0);

    matrix::SquareMat mat3(3);
    mat3[0][0] = 6.0;
    mat3[0][1] = 1.0;
    mat3[0][2] = 1.0;
    mat3[1][0] = 4.0;
    mat3[1][1] = -2.0;
    mat3[1][2] = 5.0;
    mat3[2][0] = 2.0;
    mat3[2][1] = 8.0;
    mat3[2][2] = 7.0;
    CHECK(!mat3 == -306.0);
}

TEST_CASE("SquareMat Compound Assignment") {
    matrix::SquareMat mat1(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat1[1][0] = 3.0;
    mat1[1][1] = 4.0;

    matrix::SquareMat mat2(2);
    mat2[0][0] = 5.0;
    mat2[0][1] = 6.0;
    mat2[1][0] = 7.0;
    mat2[1][1] = 8.0;

    mat1 += mat2;
    CHECK(mat1[0][0] == 6.0);
    CHECK(mat1[0][1] == 8.0);
    CHECK(mat1[1][0] == 10.0);
    CHECK(mat1[1][1] == 12.0);

    mat1 -= mat2;
    CHECK(mat1[0][0] == 1.0);
    CHECK(mat1[0][1] == 2.0);
    CHECK(mat1[1][0] == 3.0);
    CHECK(mat1[1][1] == 4.0);

    mat1 *= mat2;
    CHECK(mat1[0][0] == 19.0);
    CHECK(mat1[0][1] == 22.0);
    CHECK(mat1[1][0] == 43.0);
    CHECK(mat1[1][1] == 50.0);

    mat1 /= 2.0;
    CHECK(mat1[0][0] == 9.5);
    CHECK(mat1[0][1] == 11.0);
    CHECK(mat1[1][0] == 21.5);
    CHECK(mat1[1][1] == 25.0);
    
    mat1 %= 3.0;
    CHECK(mat1[0][0] == 0.0);
    CHECK(mat1[0][1] == 2.0);
    CHECK(mat1[1][0] == 0.0);
    CHECK(mat1[1][1] == 1.0);
    
    CHECK_THROWS_AS(mat1 += matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 -= matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 *= matrix::SquareMat(3), std::invalid_argument);
    CHECK_THROWS_AS(mat1 /= 0.0, std::invalid_argument);
    CHECK_THROWS_AS(mat1 %= 0.0, std::invalid_argument);
}

TEST_CASE("SquareMat Output Stream") {
    matrix::SquareMat mat1(2);
    mat1[0][0] = 1.0;
    mat1[0][1] = 2.0;
    mat1[1][0] = 3.0;
    mat1[1][1] = 4.0;

    std::stringstream ss;
    ss << mat1;
    std::string expectedOutput = "M_2x2:\n[ 1 2 ]\n[ 3 4 ]\n";
    CHECK(ss.str() == expectedOutput);
}