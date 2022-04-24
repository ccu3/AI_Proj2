
#include "Detector.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Detector::Detector() {
    vector<int> topology = {260, 16, 16, 10};
    float learningRate = 0.5;
    neuralNet = NeuralNetwork(topology, learningRate);
    languages = {"English", "Portugeese", "French", "Dutch", "Spanish", "Danish", "Italian", "Turkish", "Sweedish", "German"};
}

Detector::Detector(vector<int> topology, float learningRate) {
    neuralNet = NeuralNetwork(topology, learningRate);
    languages = {"English", "Portugeese", "French", "Dutch", "Spanish", "Danish", "Italian", "Turkish", "Sweedish", "German"};
}

void Detector::Train(vector<string> input, vector<string> target, int generationCount) {
    cout << "Average error before training: " << GetAverage(input, target) << endl;
    cout << "Training..." << endl;
    float prevAvg = 0.0;
    for (int i = 0; i < generationCount; i++) {
        Matrix output = neuralNet.ForwardPropagate(StringToInput(input[0]));
        for (unsigned int j = 0; j < input.size(); j++) {
            output = neuralNet.ForwardPropagate(StringToInput(input[j]));
            neuralNet.Backpropagate(output, StringToOutput(target[j]));
        }
        float avgError = GetAverage(input, target);
        cout << "Generation (" << i + 1 << "/" << generationCount << ") - Average error: " << avgError << "\tChange: " << (prevAvg - avgError) << endl;
        prevAvg = avgError;
        SaveToFile("backup.csv");
    }
}

float Detector::GetAverage(vector<string> input, vector<string> target) {
    float avgError = 0.0;
    Matrix output = neuralNet.ForwardPropagate(StringToInput(input[0]));
    for (unsigned int j = 0; j < input.size(); j++) {
        output = neuralNet.ForwardPropagate(StringToInput(input[j]));
        avgError += neuralNet.GetError(output, StringToOutput(target[j]));
    }
    return avgError /= input.size();
}

Matrix Detector::StringToInput(string str) {
    const int ALPHABET_COUNT = 26;
    const int MAX_LETTERS = 10;
    Matrix input(ALPHABET_COUNT * MAX_LETTERS, 1, 0.0);
    for (unsigned int i = 0; i < MAX_LETTERS; i++)
        if (i < str.size())
            input.At(i * ALPHABET_COUNT + (str[i] - 'a'), 0) = 1.0;
    return input;
}

Matrix Detector::StringToOutput(string str) {
    int const LANG_COUNT = 5;
    int outArr[] = {0, 0, 0, 0, 0};
    if (str.compare("English") == 0)
        outArr[0] = 1;
    else if (str.compare("French") == 0)
        outArr[1] = 1;
    else if (str.compare("Spanish") == 0)
        outArr[2] = 1;
    else if (str.compare("Italian") == 0)
        outArr[3] = 1;
    else if (str.compare("German") == 0)
        outArr[4] = 1;
    return Matrix(LANG_COUNT, 1, outArr);
}

string Detector::GetPrediction(string sentence) {
    stringstream ss(sentence);
    vector<string> words;
    string token;

    while (getline(ss, token, ' '))
        words.push_back(token);

    Matrix sum(5, 1, 0.0);
    for (string word : words) {
        Matrix output = neuralNet.ForwardPropagate(StringToInput(word));
        sum = sum.Add(output);
    }

    float max = 0.0;
    int index = -1;
    for (int i = 0; i < 5; i++) {
        if (sum.At(i, 0) >= max) {
            max = sum.At(i, 0);
            index = i;
        }
    }

    string possibleLangs[] = {"English", "French", "Spanish", "Italian", "German"};
    
    return possibleLangs[index];
}

void Detector::SaveToFile(string filename) {
    neuralNet.SaveToFile(filename);
}

void Detector::LoadFromFile(vector<int> topology, float learningRate, string filename) {
    neuralNet = NeuralNetwork(topology, learningRate, filename);
}

void Detector::Print() {
    neuralNet.Print();
}