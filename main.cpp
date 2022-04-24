
#include "Matrix.hpp"
#include "NeuralNetwork.hpp"
#include "Detector.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    Detector langDetector();

    // int top[] = {2, 3, 2};
    // int inp1[] = {1, 0};
    // int inp2[] = {0, 1};
    // int tar1[] = {0, 1};
    // int tar2[] = {1, 1};
    // Matrix in1(2, 1, inp1);
    // Matrix ta1(2, 1, tar1);
    // Matrix in2(2, 1, inp2);
    // Matrix ta2(2, 1, tar2);
    // NeuralNetwork net(3, top, 0.5);
    // Matrix output = net.ForwardPropagate(in1);
    // cout << "Start1 Error : " << net.GetError(output, ta1) << endl;
    // output = net.ForwardPropagate(in2);
    // cout << "Start2 Error : " << net.GetError(output, ta2) << endl;
    // for (int i = 0; i < 100000; i++) {
    //     if (i % 2 == 1) {
    //         output = net.ForwardPropagate(in1);
    //         net.Backpropagate(output, ta1);
    //     }
    //     else {
    //         output = net.ForwardPropagate(in2);
    //         net.Backpropagate(output, ta2);
    //     }
    // }
    // output = net.ForwardPropagate(in1);
    // cout << "Final1 Error : " << net.GetError(output, ta1) << endl;
    // output.Print();
    // output = net.ForwardPropagate(in2);
    // cout << "Final2 Error : " << net.GetError(output, ta2) << endl;
    // output.Print();
}

