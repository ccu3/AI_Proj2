
#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <vector>
#include "Matrix.hpp"

using namespace std;

class NeuralNetwork {
    private:
        Matrix inputLayer;
        vector<Matrix> weightsAll;
        vector<Matrix> deltas;
        vector<Matrix> rawNodeValues;
        Matrix outputLayer;
        float learningRate;
    public:
        NeuralNetwork(int, int*, float);
        Matrix ForwardStep(Matrix, Matrix);
        Matrix ForwardPropagate(Matrix);
        void Backpropagate(Matrix, Matrix);
        float GetError(Matrix, Matrix);
};

#endif