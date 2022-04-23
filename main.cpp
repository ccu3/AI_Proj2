
#include "Matrix.hpp"
#include "NeuralNetwork.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int top[] = {2, 4, 3, 2};
    int inp[] = {1, 0};
    int tar[] = {0, 1};
    Matrix in(2, 1, inp);
    Matrix ta(2, 1, tar);
    NeuralNetwork net(4, top, 0.01);
    Matrix output = net.ForwardPropagate(in);
    output.Print();
    for (int i = 0; i < 10; i++) {
        output = net.ForwardPropagate(in);
        net.Backpropagate(output, ta);
        cout << "Error : " << net.GetError(output, ta) << endl;
    }
}

