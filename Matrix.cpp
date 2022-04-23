#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

Matrix::Matrix() {}
Matrix::~Matrix() {}

Matrix::Matrix(int rows, int cols) {
    srand(time(NULL));
    num_Rows = rows;
    num_Cols = cols;
    vals.resize(num_Cols * num_Rows, 0.0f);
    
   for (int i = 0; i < num_Rows; ++i)
        for (int j = 0; j < num_Cols; ++j)
            At(i, j) = (double) rand() / RAND_MAX * 2 - 1;
}

Matrix::Matrix(int rows, int cols, int* elements) {
    srand(time(NULL));
    num_Rows = rows;
    num_Cols = cols;
    vals.resize(num_Cols * num_Rows, 0.0f);
    
   for (int i = 0; i < num_Rows; ++i)
        for (int j = 0; j < num_Cols; ++j)
            At(i, j) = elements[i * num_Cols + j];
}

float& Matrix::At(int row, int col) {
    return vals[row * num_Cols + col];
}

Matrix Matrix::Add(Matrix& target) {
    assert(num_Rows == target.num_Rows && num_Cols == target.num_Cols);
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
            temp.At(i, j) = At(i, j) + target.At(i, j);
    return temp;
}

Matrix Matrix::AddVector(Matrix& target) {
    assert(num_Rows == target.num_Rows && target.num_Cols == 1);
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
            temp.At(i, j) = At(i, j) + target.At(i, 0);
    return temp;
}

Matrix Matrix::AddScalar(float s) {
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < num_Rows; i++)
        for(int j = 0; j < num_Cols; j++)
            temp.At(i, j) = At(i, j) + s;
    return temp;
}

Matrix Matrix::Multiply(Matrix& mult) {
    assert(num_Cols == mult.num_Rows);
    Matrix temp(num_Rows, mult.num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++) {
            float result = 0.0f;
            for(int k = 0; k < num_Cols; k++)
                result += At(i, k) * mult.At(k, j);
            temp.At(i, j) = result;
        }
    return temp;
}

Matrix Matrix::MultiplyByElement(Matrix& mult) {
    assert(num_Rows == mult.num_Rows && num_Cols == mult.num_Cols);
    Matrix temp(num_Rows, mult.num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
            temp.At(i, j) = At(i, j) * mult.At(i, j);
    return temp;
}

Matrix Matrix::MultiplyVector(Matrix& target) {
    assert(num_Rows == target.num_Rows && target.num_Cols == 1);
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
            temp.At(i, j) = At(i, j) * target.At(i, 0);
    return temp;
}

Matrix Matrix::MultiplyScalar(float s) {
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < num_Rows; i++)
        for(int j = 0; j < num_Cols; j++)
            temp.At(i, j) = At(i, j) * s;
    return temp;
}

Matrix Matrix::RowSums() {
    Matrix temp(num_Rows, 1);
    for(int i = 0; i < num_Rows; i++) {
        float sum = 0.0;
        for(int j = 0; j < num_Cols; j++)
            sum += At(i, j);
        temp.At(i, 0) = sum;
    }
    return temp;
}

Matrix Matrix::ColSums() {
    Matrix temp(1, num_Cols);
    for(int j = 0; j < num_Cols; j++) {
        float sum = 0.0;
        for(int i = 0; i < num_Rows; i++)
            sum += At(i, j);
        temp.At(0, j) = sum;
    }
    return temp;
}

Matrix Matrix::Negative() {
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < num_Rows; i++)
        for(int j = 0; j < num_Cols; j++)
            temp.At(i, j) = -At(i, j);
    return temp;
}

Matrix Matrix::Transpose() {
    Matrix temp(num_Cols, num_Rows);
    for (int i = 0; i < num_Cols; ++i)
        for (int j = 0; j < num_Rows; ++j)
            temp.At(i,j) = At(j,i);
    return temp;
}

Matrix Matrix::Sigmoid() {
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < num_Rows; i++)
        for(int j = 0; j < num_Cols; j++)
            temp.At(i, j) = 1 / (1 + exp(-At(i, j)));
    return temp;
}

Matrix Matrix::DeSigmoid() {
    Matrix sigmoid = Sigmoid();
    return Sigmoid().AddScalar(-1).Negative().MultiplyByElement(sigmoid);
}

void Matrix::Print() {
    for (int i = 0; i < num_Rows; i++) {
        for (int j = 0; j < num_Cols; j++)
            cout << ' ' << At(i, j);
        cout << '\n';
    }
    cout << '\n';
}

//Just a guide that we can add on later (if needed)

//void Matrix::swapRows(int r1, int r2)
//{
//    double *temp = p[r1];
//    p[r1] = p[r2];
//    p[r2] = temp;
//}
//
//Matrix::~Matrix()
//{
//    for (int i = 0; i < rows_; ++i) {
//        delete[] p[i];
//    }
//    delete[] p;
//}

