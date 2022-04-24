
#include "NeuralNetwork.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

NeuralNetwork::NeuralNetwork() {}

NeuralNetwork::NeuralNetwork(vector<int> topology, float learningRate) {
    this->learningRate = learningRate;
    this->topology = topology;
    int layerCount = topology.size();
    inputLayer = Matrix(topology[0], 1);
    outputLayer = Matrix(topology[layerCount - 1], 1);
    weightsAll = vector<Matrix>(layerCount - 1);
    deltas = vector<Matrix>(layerCount - 1);
    rawNodeValues = vector<Matrix>(layerCount);
    for (unsigned int i = 0; i < weightsAll.size(); i++)
        weightsAll[i] = Matrix(topology[i + 1], topology[i]);
}

NeuralNetwork::NeuralNetwork(vector<int> topology, float learningRate, string filename) {
    NeuralNetwork(topology, learningRate);
    ifstream inFile(filename);
    
    string str;
    vector<float> storedWeights;

    inFile >> str;
    istringstream ss(str);
    string token;

    while (getline(ss, token, ','))
        storedWeights.push_back(stof(token));

    int counter = 0;
    for (unsigned int i = 0; i < weightsAll.size(); i++) {
        Matrix weights = weightsAll[i];
        for (int j = 0; j < weights.GetRows(); j++)
            for (int k = 0; k < weights.GetCols(); k++) {
                weights.At(j, k) = storedWeights[counter++];
                cout << weights.At(j, k) << ',';
            }
    }
}

Matrix NeuralNetwork::ForwardStep(Matrix input, Matrix weights) {
    return weights.Multiply(input);
}

Matrix NeuralNetwork::ForwardPropagate(Matrix input) {
    inputLayer = input;
    Matrix output = input;
    rawNodeValues[0] = output;
    for (unsigned int i = 0; i < weightsAll.size(); i++) {
        output = ForwardStep(output, weightsAll[i]);
        rawNodeValues[i + 1] = output;
        output = output.Sigmoid();
    }
    return output;
}

void NeuralNetwork::Backpropagate(Matrix output, Matrix target) {
    Matrix derivative = rawNodeValues[rawNodeValues.size() - 1].DeSigmoid();
    deltas[deltas.size() - 1] = output.Negative().Add(target).MultiplyByElement(derivative);
    for (unsigned int i = deltas.size() - 1; i > 0; i--) {
        Matrix weightedDeltaSum = weightsAll[i].MultiplyVector(deltas[i]).ColSums().Transpose();
        deltas[i - 1] = rawNodeValues[i].DeSigmoid().MultiplyByElement(weightedDeltaSum);
    }

    for (unsigned int i = 0; i < weightsAll.size(); i++) {
        Matrix transposedInput = rawNodeValues[i].Sigmoid().Transpose();
        Matrix addend = deltas[i].Multiply(transposedInput).MultiplyScalar(learningRate);
        weightsAll[i] = weightsAll[i].Add(addend);
    }
}

float NeuralNetwork::GetError(Matrix output, Matrix target) {
    Matrix negative = target.Negative();
    Matrix difference = output.Add(negative);
    return difference.Transpose().Multiply(difference).At(0, 0);
}

void NeuralNetwork::SaveToFile(string filename) {
    ofstream outFile(filename);
    for (unsigned int i = 0; i < weightsAll.size(); i++) {
        vector<float> weights = weightsAll[i].GetValues();
        for (unsigned int j = 0; j < weights.size(); j++) {
            outFile << weights[j] << ',';
        }
    }
}

void NeuralNetwork::Print() {
    for (unsigned int i = 0; i < weightsAll.size(); i++)
        weightsAll[i].Print();
}