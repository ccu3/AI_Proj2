
#include "Matrix.hpp"
#include "NeuralNetwork.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int top[] = {6, 10, 16, 10, 3};
    int inp[] = {1, 0, 1, 0, 0, 0};
    Matrix in(6, 1, inp);
    NeuralNetwork net(5, top);
    net.ForwardPropagate(in);
}

