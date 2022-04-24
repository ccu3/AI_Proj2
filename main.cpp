
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

    /* Setup */

    vector<int> topology = {260, 10, 10, 10, 5};
    float learningRate = 0.6;
    Detector langDetector(topology, learningRate);
    
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

    /* Evaluate */

    ifstream test_inFile("testing.csv");

    string test_str;
    vector<string> test_words;
    vector<string> test_langs;

    test_inFile >> test_str;
    istringstream test_ss(test_str);
    string test_token;

    while (getline(test_ss, test_token, ',')) {
        test_words.push_back(test_token);
        getline(test_ss, test_token, ',');
        test_langs.push_back(test_token);
    }

    langDetector.LoadFromFile(topology, learningRate, "backup.csv");
    cout << "Evaluation on training data - Average Error: " << langDetector.GetAverage(words, langs) << endl;
    cout << "Evaluation on testing data - Average Error: " << langDetector.GetAverage(test_words, test_langs) << endl;

    /* Train */

    cout << "Train or Interact? (t/i): ";
    char discission;
    cin >> discission;
    cin.ignore();
    if (discission == 't') {
        int generations;
        cout << "Enter number of generations to train: ";
        cin >> generations;
        langDetector.LoadFromFile(topology, learningRate, "backup.csv");
        langDetector.Train(words, langs, generations);
        langDetector.SaveToFile("weights.csv");
        cout << "Evaluation on training data - Average Error: " << langDetector.GetAverage(words, langs) << endl;
        cout << "Evaluation on testing data - Average Error: " << langDetector.GetAverage(test_words, test_langs) << endl;
    }

    /* Interact */

    langDetector.LoadFromFile(topology, learningRate, "backup.csv");
    cout << "\nPossible languages detectable: [English, French, Spanish, Italian, German]\n\n";
    while (true) {
        cout << "Enter a sentence to detect: ";
        string test;
        getline(cin, test);
        cout << "Predicted language: " << langDetector.GetPrediction(test) << endl;
        cout << "\nContinue? (y/n): ";
        char next;
        cin >> next;
        cin.ignore();
        if (next == 'n')
            break;
    }

}

