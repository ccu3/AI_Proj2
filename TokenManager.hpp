
#ifndef TokenManager_hpp
#define TokenManager_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class TokenManager {
public:
    vector<string> tokens;
    vector<string> known;
    void Print(vector <string> tokens);
    vector<string> ValidTokens(string token);
    vector<string> CheckDuplicates(vector<string> &);
    vector<string> RemoveDuplicates(vector<string>&);
    vector<string> RemoveSpecialChar(vector<string>&);
};
#endif /* TokenManager_hpp */

