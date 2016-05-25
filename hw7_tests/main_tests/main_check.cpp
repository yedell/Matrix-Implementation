#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include "gtest/gtest.h"
#include "Matrix.h"
#include <exception>
#include<iostream>

using namespace std;

int currentPoints = 0;

template<class T>
bool checkTwoDVectors(twoD<T> vec1, twoD<T> vec2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (abs(vec1[i][j]) - abs(vec2[i][j]) > 0.3) return false;
            //cout << "Writing: i: " << i << " j: " << j << " val: " << matrix[i][j] << endl;
        }
    }
    return true;
}

TEST(hw7Test, basicConstructor) {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(4, 4);

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7IntTest, intAdditionTest) {
    twoD<int> expectedMatrix = {{2, 4, 6, 8},
                                {2, 4, 6, 8},
                                {2, 4, 6, 8},
                                {2, 4, 6, 8}};
    twoD<int> intMatrix1 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}};
    twoD<int> intMatrix2 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}};
    Matrix<int> m1(4, 4, intMatrix1);
    Matrix<int> m2(4, 4, intMatrix2);
    Matrix<int> m3 = m1 + m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7FloatTest, floatAdditionTest) {
    twoD<float> expectedMatrix = {{2.2, 4.4, 6.6, 8.8},
                                  {2.2, 4.4, 6.6, 8.8},
                                  {2.2, 4.4, 6.6, 8.8},
                                  {2.2, 4.4, 6.6, 8.8}};
    twoD<float> floatMatrix1 = {{1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4}};
    twoD<float> floatMatrix2 = {{1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4}};
    Matrix<float> m1(4, 4, floatMatrix1);
    Matrix<float> m2(4, 4, floatMatrix2);
    Matrix<float> m3 = m1 + m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7IntTest, intSubtractionTest) {
    twoD<int> expectedMatrix = {{1, 2, 3, 4},
                                {1, 2, 3, 4},
                                {1, 2, 3, 4},
                                {1, 2, 3, 4}};
    twoD<int> intMatrix1 = {{2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8}};
    twoD<int> intMatrix2 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}};
    Matrix<int> m1(4, 4, intMatrix1);
    Matrix<int> m2(4, 4, intMatrix2);
    Matrix<int> m3 = m1 - m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7FloatTest, floatSubtractionTest) {
    twoD<float> expectedMatrix = {{1.1, 2.2, 3.3, 4.4},
                                  {1.1, 2.2, 3.3, 4.4},
                                  {1.1, 2.2, 3.3, 4.4},
                                  {1.1, 2.2, 3.3, 4.4}};
    twoD<float> floatMatrix1 = {{2.2, 4.4, 6.6, 8.8},
                                {2.2, 4.4, 6.6, 8.8},
                                {2.2, 4.4, 6.6, 8.8},
                                {2.2, 4.4, 6.6, 8.8}};
    twoD<float> floatMatrix2 = {{1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4}};
    Matrix<float> m1(4, 4, floatMatrix1);
    Matrix<float> m2(4, 4, floatMatrix2);
    Matrix<float> m3 = m1 - m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7IntTest, intScalarMultiplicationTest) {
    twoD<int> expectedMatrix = {{6, 12, 18, 24},
                                {6, 12, 18, 24},
                                {6, 12, 18, 24},
                                {6, 12, 18, 24}};
    twoD<int> intMatrix1 = {{2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8}};
    int scalar = 3;
    Matrix<int> m1(4, 4, intMatrix1);
    Matrix<int> m3 = m1 * scalar;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7FloatTest, floatScalarMultiplicationTest) {
    twoD<float> expectedMatrix = {{6, 12, 18, 24},
                                  {6, 12, 18, 24},
                                  {6, 12, 18, 24},
                                  {6, 12, 18, 24}};
    twoD<float> floatMatrix1 = {{2, 4, 6, 8},
                                {2, 4, 6, 8},
                                {2, 4, 6, 8},
                                {2, 4, 6, 8}};
    float scalar = 3;
    Matrix<float> m1(4, 4, floatMatrix1);
    Matrix<float> m3 = m1 * scalar;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7IntTest, intMatrixMultiplicationTest) {
    twoD<int> expectedMatrix = {{1, 2, 3, 4},
                                {1, 2, 3, 4},
                                {1, 2, 3, 4},
                                {1, 2, 3, 4}};
    twoD<int> intMatrix1 = {{2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8}};
    twoD<int> intMatrix2 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}};
    Matrix<int> m1(4, 4, intMatrix1);
    Matrix<int> m2(4, 4, intMatrix2);
    Matrix<int> m3 = m1 - m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7FloatTest, floatMatrixMultiplicationTest) {
    twoD<float> expectedMatrix = {{1.1, 2.2, 3.3, 4.4},
                                  {1.1, 2.2, 3.3, 4.4},
                                  {1.1, 2.2, 3.3, 4.4},
                                  {1.1, 2.2, 3.3, 4.4}};
    twoD<float> floatMatrix1 = {{2.2, 4.4, 6.6, 8.8},
                                {2.2, 4.4, 6.6, 8.8},
                                {2.2, 4.4, 6.6, 8.8},
                                {2.2, 4.4, 6.6, 8.8}};
    twoD<float> floatMatrix2 = {{1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4},
                                {1.1, 2.2, 3.3, 4.4}};
    Matrix<float> m1(4, 4, floatMatrix1);
    Matrix<float> m2(4, 4, floatMatrix2);
    Matrix<float> m3 = m1 - m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7IntTest, intMatrixMultiplicationVariableSizesTest) {
    twoD<int> expectedMatrix = {{31, 15,  -18, 34},
                                {43, -10, 68,  40},
                                {22, -1,  7,   21},
                                {50, 98,  149, 83}};
    twoD<int> intMatrix1 = {{1,  3, -3},
                            {-4, 4, 5},
                            {-1, 2, 0},
                            {6,  7, 8}};
    twoD<int> intMatrix2 = {{-2, 9, 3,  1},
                            {10, 4, 5,  11},
                            {-1, 2, 12, 0}};
    Matrix<int> m1(4, 3, intMatrix1);
    Matrix<int> m2(3, 4, intMatrix2);
    Matrix<int> m3 = m1 * m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

TEST(hw7FloatTest, floatMatrixMultiplicationVariableSizesTest) {
    //TODO
    twoD<float> expectedMatrix = {{31, 15,  -18, 34},
                                  {43, -10, 68,  40},
                                  {22, -1,  7,   21},
                                  {50, 98,  149, 83}};
    twoD<float> floatMatrix1 = {{1,  3, -3},
                                {-4, 4, 5},
                                {-1, 2, 0},
                                {6,  7, 8}};
    twoD<float> floatMatrix2 = {{-2, 9, 3,  1},
                                {10, 4, 5,  11},
                                {-1, 2, 12, 0}};
    Matrix<float> m1(4, 3, floatMatrix1);
    Matrix<float> m2(3, 4, floatMatrix2);
    Matrix<float> m3 = m1 * m2;
    EXPECT_TRUE(checkTwoDVectors(expectedMatrix, m3.getMatrix(), m3.getRows(), m3.getCols()));

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;

}

/**
 * START OF EXCEPTION TESTS
 */

TEST(hw7ExceptionsTest, basicExceptionTest) {
    EXPECT_THROW(Matrix<int> m1(-4, 3), exception);
    EXPECT_THROW(Matrix<float> m1(-4, 3), exception);

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw7ExceptionsTest, AdditionExceptionTest) {

    twoD<int> expectedMatrix = {{2, 4, 6, 8},
                                {2, 4, 6, 8},
                                {2, 4, 6, 8},
                                {2, 4, 6, 8}};
    twoD<int> intMatrix1 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}};
    twoD<int> intMatrix2 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}
    };
    Matrix<int> m1(4, 4, intMatrix1);
    Matrix<int> m2(3, 4, intMatrix2);


    EXPECT_THROW(Matrix<int> m3 = m1 + m2, exception);

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw7ExceptionsTest, SubtractionExceptionTest) {
    twoD<int> expectedMatrix = {{1, 2, 3, 4},
                                {1, 2, 3, 4},
                                {1, 2, 3, 4},
                                {1, 2, 3, 4}};
    twoD<int> intMatrix1 = {{2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8},
                            {2, 4, 6, 8}};
    twoD<int> intMatrix2 = {{1, 2, 3, 4},
                            {1, 2, 3, 4},
                            {1, 2, 3, 4}};
    Matrix<int> m1(4, 4, intMatrix1);
    Matrix<int> m2(3, 4, intMatrix2);


    EXPECT_THROW(Matrix<int> m3 = m1 - m2, exception);

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}

TEST(hw7ExceptionsTest, MultiplicationExceptionTest) {

    twoD<int> expectedMatrix = {{31, 15,  -18, 34},
                                {43, -10, 68,  40},
                                {22, -1,  7,   21},
                                {50, 98,  149, 83}};
    twoD<int> intMatrix1 = {{1,  3, -3},
                            {-4, 4, 5},
                            {-1, 2, 0},
                            {6,  7, 8}};
    twoD<int> intMatrix2 = {{-2, 9, 3, 1},
                            {10, 4, 5, 11}
    };
    Matrix<int> m1(4, 3, intMatrix1);
    Matrix<int> m2(2, 4, intMatrix2);

    EXPECT_THROW(Matrix<int> m3 = m1 * m2, exception);

    if (!HasFailure())currentPoints += 10;
    cout << "Current POINTS:" << currentPoints << endl;
}
