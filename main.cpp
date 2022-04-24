
#include "Matrix.hpp"
#include "NeuralNetwork.hpp"
#include "Detector.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream inFile("unaccented.csv");

    string str;
    vector<string> words;
    vector<string> langs;

    inFile >> str;
    istringstream ss(str);
    string token;

    while (getline(ss, token, ',')) {
        words.push_back(token);
        getline(ss, token, ',');
        langs.push_back(token);
    }

    //vector<int> topology = {260, 64, 32, 5};
    vector<int> topology = {260, 3, 4, 5};
    float learningRate = 0.5;
    Detector langDetector(topology, learningRate);
    langDetector.Print();
    langDetector.SaveToFile("weights.csv");
    langDetector.Train(words, langs, 1);
    langDetector.Print();
    cout << langDetector.GetPrediction("This is blood") << endl;
    langDetector.LoadFromFile(topology, learningRate, "weights.csv");
    langDetector.Print();
}

