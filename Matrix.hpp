#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Matrix {
private:
    int num_Rows;
    int num_Cols;
    vector<float> vals;
public:
    Matrix();
    Matrix(int num_Rows, int num_Cols,bool rand);
    float at (int num_Rows, int num_Cols);
    Matrix Multiply(const Matrix& mult);
    Matrix output(int num_Cols, int num_Rows);
    Matrix add(Matrix& target);
    Matrix multiplyScalar(float s)
    
//    void setValue(int r, int c, double v);
//    double getValue(int r, int c);
//    void swapRows(int r1, int r2);
    Matrix *transpose();
    ~Matrix();
};
#endif /* Matrix_hpp */

