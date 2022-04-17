
#include "Matrix.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    cout << "Enter size of matrix [r c]: ";
    int r, c;
    cin >> r >> c;
    Matrix m1(r, c);
    cout << "Enter size of matrix [r c]: ";
    cin >> r >> c;
    Matrix m2(r, c);
    m1.Print();
    m2.Print();
    cout << "Added:\n";
    Matrix m3 = m1.Transpose();
    m3.Print();
}

