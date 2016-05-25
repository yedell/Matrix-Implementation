#pragma once

#include <exception>
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
using twoD = std::vector<std::vector<T>>;
//more info on the above: http://stackoverflow.com/a/16861385/3255842

template<class T>
class Matrix {
private:
    int rows;
    int cols;
    twoD<T> matrix;
protected:
    void validSizeCheck(int rows, int cols);

public:
    Matrix(int rows, int cols);

    Matrix(int rows, int cols, twoD<T> newMatrix);

    twoD<T> getMatrix();

    int getRows();

    int getCols();

    void operator=(const Matrix<T> &);

    Matrix<T> &operator+=(const Matrix<T> &);

    Matrix<T> &operator-=(const Matrix<T> &);

    Matrix<T> &operator*=(const Matrix<T> &);

    Matrix<T> &operator*=(const T &);

    /*
    friend void operator<<(ostream &os, const Matrix<T> &m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                os << m.matrix[i][j] << " ";
            }
            os << endl;
        }
        os << endl;
        os << endl;
    }
     */

    void printMatrix();

    Matrix<T> operator+(const Matrix<T> &);//Matrix Addition

    Matrix<T> operator-(const Matrix<T> &);//Matrix Subtraction

    Matrix<T> operator*(const Matrix<T> &);//Matrix Multiplication

    Matrix<T> operator*(const T &);//Matrix Multiplication with a Scalar

};

template<class T>
void Matrix<T>::validSizeCheck(int rows, int cols) {
    //DO NOT MODIFY
    //This is a helper function for checking invalid size.
    if (rows < 1 || cols < 1) {
        throw exception();
    }
}


template<class T>
twoD<T> Matrix<T>::getMatrix() {
    //DO NOT MODIFY
    return matrix;
}

template<class T>
int Matrix<T>::getRows() {
    //DO NOT MODIFY
    return rows;
}

template<class T>
int Matrix<T>::getCols() {
    //DO NOT MODIFY
    return cols;
}


template<class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    //DO NOT MODIFY
    validSizeCheck(rows, cols);
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
            //cout << "Writing: i: " << i << " j: " << j << " val: " << matrix[i][j] << endl;
        }
    }

}

template<class T>
Matrix<T>::Matrix(int rows, int cols, twoD<T> newMatrix) : rows(rows), cols(cols) {
    //DO NOT MODIFY
    validSizeCheck(rows, cols);
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }


}

template<class T>
void Matrix<T>::operator=(const Matrix<T> &rhs) {
    //DO NOT MODIFY

    if (rows != rhs.rows || cols != rhs.cols) {
        //throw exception
    }
    Matrix<T> newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix.matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

template<class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this + rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this - rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs) {
    //DO NOT MODIFY
    *this = *this * rhs;
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const T &rhs) {
    //DO NOT MODIFY
    *this = *this * rhs;
    return *this;
}

template<class T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat2) {
    if(this->rows != mat2.rows || this->cols != mat2.cols){
        cout << "Matrix sizes do not match" << endl;
        throw exception();
    }
    Matrix<T> temp(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            temp.matrix[i][j] = this->matrix[i][j] + mat2.matrix[i][j];
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat2) {
    if(this->cols != mat2.cols || this->rows != mat2.rows){
        throw exception();
    }
    Matrix<T> temp(mat2.rows, mat2.cols);
    for(int i = 0; i < mat2.rows; i++){
        for (int j = 0; j < mat2.cols; j++){
            temp.matrix[i][j] = this->matrix[i][j] - mat2.matrix[i][j];
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T &num) {
//    if(matrix == nullptr || rows == 0 || cols == 0){
//        throw exception();
//    }
    Matrix<T> temp(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp.matrix[i][j] = this->matrix[i][j] * num;
        }
    }
    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat2) {
    if(this->cols != mat2.rows){
        throw exception();
    }

    Matrix<T> temp(this->rows, mat2.cols);

    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < mat2.cols; j++){
            //temp.matrix[i][j] = 0;
            for(int k = 0; k < cols; k++){
                temp.matrix[i][j] = temp.matrix[i][j] + (this->matrix[i][k] * mat2.matrix[k][j]);
            }
        }
    }

//    T t = 0;
//
//    for(int row = 0; row < this->rows; row++){
//        for(int col = 0; col < cols; col++){
//            t = 0;
//            for(int inner = 0; inner < this->cols; inner++){
//                t = t + this->matrix[row][inner] * m.matrix[inner][col];
//            }
//            temp.matrix[row][col] = t;
//        }
//    }
    return temp;
}