
#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <vector>
#include "Matrix.hpp"

using namespace std;

class NeuralNetwork {
    private:
        Matrix inputLayer;
        vector<Matrix> weightsAll;
        Matrix outputLayer;
    public:
        NeuralNetwork(int, int*);
        Matrix ForwardStep(Matrix, Matrix);
        Matrix ForwardPropagate(Matrix);
};

#endif