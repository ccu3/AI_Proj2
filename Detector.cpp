
#include "Detector.hpp"
#include <vector>
#include <iostream>
using namespace std;

Detector::Detector() {
    vector<int> topology = {260, 16, 16, 16, 10};
    float learningRate = 0.5;
    neuralNet = NeuralNetwork(topology, learningRate);
    languages = {"English", "Portugeese", "French", "Dutch", "Spanish", "Danish", "Italian", "Turkish", "Sweedish", "German"};
}

void Detector::Train(vector<string> input, vector<string> target, int generationCount) {
    for (int i = 0; i < generationCount; i++) {
        avgError = 0.0;
        for (int j = 0; j < input.size(); j++) {
            Matrix output = neuralNet.ForwardPropagate(StringToInput(input[j]));
            neuralNet.Backpropagate(output, StringToOutput(target[j]));
        }
        if (i % 100 == 0)
            cout << "Generation " << i << " - Average error: " << avgError << endl;
    }
}

Matrix Detector::StringToInput(string str) {
    const int ALPHABET_COUNT = 26;
    const int MAX_LETTERS = 10;
    Matrix input(ALPHABET_COUNT * MAX_LETTERS, 1, 0.0);
    for (int i = 0; i < MAX_LETTERS; i++)
        if (i < str.size())
            input.At(i * ALPHABET_COUNT + (str[i] - 'a'), 0) = 1.0;
    return input;
}

Matrix Detector::StringToOutput(string str) {
    int const LANG_COUNT = 10;
    int outArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (str.compare("English") == 0)
        outArr[0] = 1;
    else if (str.compare("Portugeese") == 0)
        outArr[1] = 1;
    else if (str.compare("French") == 0)
        outArr[2] = 1;
    else if (str.compare("Dutch") == 0)
        outArr[3] = 1;
    else if (str.compare("Spanish") == 0)
        outArr[4] = 1;
    else if (str.compare("Danish") == 0)
        outArr[5] = 1;
    else if (str.compare("Italian") == 0)
        outArr[6] = 1;
    else if (str.compare("Turkish") == 0)
        outArr[7] = 1;
    else if (str.compare("Sweedish") == 0)
        outArr[8] = 1;
    else if (str.compare("German") == 0)
        outArr[9] = 1;
    return Matrix(LANG_COUNT, 0, outArr);
}

string Detector::GetPrediction(string sentence) {

}