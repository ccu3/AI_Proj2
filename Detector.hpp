
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
        vector<string> languages;
    public:
        Detector();
        Detector(vector<int>, float);
        void Train(vector<string>, vector<string>, int);
        float GetAverage(vector<string>, vector<string>);
        string GetPrediction(string);
        void SaveToFile(string);
        void LoadFromFile(vector<int>, float, string);
        void Print();
};

#endif