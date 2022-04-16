#include "Matrix.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

Matrix::Matrix(){}

Matrix::Matrix(int num_Rows,int num_Cols,bool rand) {
    //insert something
    vals.resize(num_Cols * num_Rows, 0.0f);
}
float Matrix::at(int row, int col) {
    return vals[num_Rows * num_Cols + col];
}

Matrix Matrix::Multiply(const Matrix& mult) {
    assert(num_Cols == mult.num_Rows);
    output(mult.num_Cols, num_Rows);
    for(int j = 0; j < output.num_Rows; j++)
        for(int k = 0; k < output.num_Cols; k++)
        {
            float result = 0.0f;
            for(int k = 0; k < num_Cols; k++)
                result += at(k, y) * target.at(x,k);
            output.at(x,y) = result;
        }
    return output;
}

Matrix Matrix::add(Matrix& target)
{
    assert(num_Rows == target.num_Rows && num_Cols == target.num_Cols);
     output(num_Cols, num_Rows);
    for(int y = 0; y < output.num_Rows; y++)
        for(int x = 0; x < output.num_Cols; x++)
        {
            output.at(x, y) = at(x, y) + target.at(x, y);
        }
    return output;
}
Matrix Matrix::multiplyScalar(float s)
{
    assert(num_Cols == target.num_Rows);
    Matrix output(num_Cols,num_Rows);
    for(int y = 0; y < output.num_Cols; x++)
    {
        output.at(x, y) = at(x, y) * s;
    }
    return output;
}

Matrix Matrix::addScalar(float s)
{
    assert(num_Cols == target.num_Rows);
    Matrix output(num_Cols,num_Rows);
    for(int y = 0; y < output.num_Cols; x++)
    {
        output.at(x, y) = at(x, y) + s;
    }
    return output;
}
//void Matrix::swapRows(int r1, int r2)
//{
//    double *temp = p[r1];
//    p[r1] = p[r2];
//    p[r2] = temp;
//}
//
//Matrix Matrix::transpose()
//{
//    Matrix ret(cols_, rows_);
//    for (int i = 0; i < rows_; ++i) {
//        for (int j = 0; j < cols_; ++j) {
//            ret.p[j][i] = p[i][j];
//        }
//    }
//    return ret;
//}
//Matrix::~Matrix()
//{
//    for (int i = 0; i < rows_; ++i) {
//        delete[] p[i];
//    }
//    delete[] p;
//}

