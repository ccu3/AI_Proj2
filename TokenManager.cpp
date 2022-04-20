
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include "TokenManager.hpp"

using namespace std;
 
vector<string> TokenManager::ValidTokens(string token) {

        // Vector of string to save tokens
        vector <string> tokens;
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
    
        // stringstream class check1
        stringstream check1(token);
        string intermediate;
    
        // Tokenizing w.r.t. space ' '
        while(getline(check1, intermediate, ' '))
        {
            
            tokens.push_back(intermediate);
        }

    Print(tokens);
    return  tokens;
}

void TokenManager::Print(vector <string> tokens) {
    cout << tokens.size();
    for (const string &s: tokens) {
           cout << s << endl;
       }

}

