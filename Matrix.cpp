
#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

Matrix::Matrix() {}
Matrix::~Matrix() {}

Matrix::Matrix(int rows, int cols) {
    num_Rows = rows;
    num_Cols = cols;
    vals.resize(num_Cols * num_Rows, 0.0f);
    
   for (int i = 0; i < num_Rows; ++i)
        for (int j = 0; j < num_Cols; ++j)
            At(i, j) = i + j;
}

float& Matrix::At(int row, int col) {
    return vals[row * num_Cols + col];
}

Matrix Matrix::Add(Matrix& target) {
    assert(num_Rows == target.num_Rows && num_Cols == target.num_Cols);
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
            temp.At(i, j) = At(i, j) + temp.At(i, j);
    return temp;
}
Matrix Matrix::AddScalar(float s) {
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < num_Rows; i++)
        for(int j = 0; j < num_Cols; j++)
            temp.At(i, j) += s;
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

Matrix Matrix::MultiplyScalar(float s) {
    Matrix temp(num_Rows, num_Cols);
    for(int i = 0; i < num_Rows; i++)
        for(int j = 0; j < num_Cols; j++)
            temp.At(i, j) *= s;
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

