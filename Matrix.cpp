
#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

Matrix::Matrix(){}

Matrix::Matrix(int num_Rows,int num_Cols) {
//    for (int i = 0; i < rows_; ++i) {
//            for (int j = 0; j < cols_; ++j) {
//                p[i][j] = 0;
//            }
//        }
    vals.resize(num_Cols * num_Rows, 0.0f);
}
float Matrix::at(int row, int col) {
    return vals[num_Rows * num_Cols + col];
}
Matrix Matrix::add(Matrix& target)
{
    assert(num_Rows == target.num_Rows && num_Cols == target.num_Cols);
     Matrix temp(num_Cols, num_Rows);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
        {
            at(i, j) += temp.at(i, j);
        }
    return temp;
}
Matrix Matrix::addScalar(float s)
{
    Matrix temp(num_Cols,num_Rows);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
        {
            temp.at(j, i) += temp.at(j, i) + s;
        }
    return temp;
}

Matrix Matrix::Multiply(Matrix& mult) {
    assert(num_Cols == mult.num_Rows);
    Matrix temp(num_Rows, mult.num_Cols);
    for(int i = 0; i < temp.num_Rows; i++)
        for(int j = 0; j < temp.num_Cols; j++)
        {
            float result = 0.0f;
            for(int k = 0; k < num_Cols; k++)
                result += at(k, i) * mult.at(j,k);
            result = temp.at(j, i);
        }
    return temp;
}

Matrix Matrix::multiplyScalar(float s)
{
    Matrix temp(num_Cols,num_Rows);
    for(int i = 0; i < temp.num_Rows; i++)
    {
        for(int j = 0; j < temp.num_Cols; j++)
        {
            temp.at(j, i) += temp.at(j, i) * s;
        }
    }
    return temp;
}


Matrix Matrix::negative()
{
    Matrix temp(num_Cols,num_Rows);
    for(int y = 0; y < temp.num_Rows; y++)
        for(int x = 0; x < temp.num_Cols; x++)
        {
            temp.at(x, y) = -at(x, y);
        }
    return temp;
}

Matrix Matrix::transpose()
{
    Matrix temp(num_Rows, num_Cols);
    for (int i = 0; i < num_Rows; ++i) {
        for (int j = 0; j < num_Cols; ++j) {
            temp.at(i,j) = at(j,i);
        }
    }
    return temp;
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

