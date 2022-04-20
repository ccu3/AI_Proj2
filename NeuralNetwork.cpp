
#include "NeuralNetwork.hpp"
#include <iostream>

NeuralNetwork::NeuralNetwork(int layerCount, int* topology) {
    inputLayer = Matrix(topology[0], 1);
    outputLayer = Matrix(topology[layerCount - 1], 1);
    weightsAll = vector<Matrix>(layerCount - 1);
    for (unsigned int i = 0; i < weightsAll.size(); i++)
        weightsAll[i] = Matrix(topology[i + 1], topology[i]); // [cols] + 1 for bias
}

Matrix NeuralNetwork::ForwardStep(Matrix input, Matrix weights) { // last input element = 1 for bias
    std::cout << "weights:\n";
    weights.Print();
    Matrix out = weights.Multiply(input);
    std::cout << "raw:\n";
    out.Print();
    return out;
}

Matrix NeuralNetwork::ForwardPropagate(Matrix input) {
    inputLayer = input;
    Matrix output = input;
    std::cout << "Input:\n";
    input.Print();
    for (unsigned int i = 0; i < weightsAll.size(); i++) {
        output = ForwardStep(output, weightsAll[i]).Logistic();
        std::cout << "logistic:\n";
        output.Print();
    }
    return output;
}