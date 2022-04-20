
#ifndef TokenManager_hpp
#define TokenManager_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class TokenManager {
public:
    vector<string> tokens;
    void Print(vector <string> tokens);
    vector<string> ValidTokens(string token);
};
#endif /* TokenManager_hpp */

