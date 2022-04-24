
#ifndef DETECTOR
#define DETECTOR

#include <string>
#include <vector>
#include "NeuralNetwork.hpp"
using namespace std;

class Detector {
    private:
        NeuralNetwork neuralNet;
        Matrix StringToInput(string);
        Matrix StringToOutput(string);
        float avgError;
        vector<string> languages;
    public:
        Detector();
        void Train(vector<string>, vector<string>, int);
        string GetPrediction(string);
};

#endif