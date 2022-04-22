#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>
#include "CSVReader.hpp"

using namespace std;



void CSVReader::ReadCSV(std::string filename)
{
    if (std::ifstream csvFile(filename); csvFile) {

           std::vector<std::vector<std::string>> csvData{};


           for (std::string line{}; std::getline(csvFile, line); ) {
               csvData.emplace_back(std::vector<std::string>(std::sregex_token_iterator(line.begin(), line.end(), delimiter, -1), {}));
           }
            string sentence{}, language{};
           for (size_t i = 1U; i < csvData.size(); ++i) {

              sentence += std::stod(csvData[i].at(1));
               language += std::stod(csvData[i].at(2));
               
           }
       }
       else { // In case that we could not open the source file
           std::cerr << "\n*** Error. Could not open file " << filename << "\n\n";
       }
}

