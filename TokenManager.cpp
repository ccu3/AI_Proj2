
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
    CheckDuplicates(tokens);
    RemoveDuplicates(tokens);
    Print(tokens);
    return  tokens;
}

vector<string> TokenManager::CheckDuplicates(vector<string> &input) {
     
        sort(input.begin(), input.end());
     
        for (int i = 1; i < input.size(); i++) {
            if (input[i - 1] == input[i]) {
     
                if (known.empty())
                  known.push_back(input[i]);
                else if (input[i] != known.back())
                    known.push_back(input[i]);
            }
        }
     
        if (known.size() == 0)
            cout << "No Duplicate words" << endl;
        else
            for (int i = 0; i < known.size(); i++)
                cout << "Duplicate: " << known[i] << endl;
    return known;
}
vector<string> TokenManager::RemoveDuplicates(vector<string> &noDuplicates) {
    
    auto end = noDuplicates.end();
       for (auto it = noDuplicates.begin(); it != end; ++it) {
           end = std::remove(it + 1, end, *it);
       }
    
       noDuplicates.erase(end, noDuplicates.end());
    return noDuplicates;
}

void TokenManager::Print(vector <string> tokens) {
    cout << "\nLeft words: " << endl;
    for (const string &s: tokens) {
           cout << s << endl;
       }

}

