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
        Matrix(int num_Rows, int num_Cols);
        Matrix(int, int, int*);
        ~Matrix();
        Matrix Output(int num_Cols, int num_Rows);
        float& At(int num_Rows, int num_Cols);
        Matrix Add(Matrix& target);
        Matrix AddScalar(float s);
        Matrix Multiply(Matrix& mult);
        Matrix MultiplyScalar(float s);
        Matrix Negative();
        Matrix Transpose();
        Matrix Logistic();

        void Print();
    
//    void setValue(int r, int c, double v);
//    double getValue(int r, int c);
//    void swapRows(int r1, int r2);
    
};
#endif /* Matrix_hpp */

