

#ifndef CSVReader_hpp
#define CSVReader_hpp
#include <string>
#include <stdio.h>
#include <vector>
#include <regex>
using namespace std;

class CSVReader {
    
private:
    const std::regex delimiter{ "," };
    std::vector<std::string>& data;
    
public:
    CSVReader();
    void ReadCSV(std::string filename);
};
#endif /* CSVReader_hpp */

