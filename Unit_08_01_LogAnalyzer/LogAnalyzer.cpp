#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <algorithm>

void LogAnalyzer::analyzeFile(const std::string& filename, const std::vector<std::string>& keywords) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::cout << "Processing: " << filename << std::endl;

    std::string line;

   while(std::getline(file, line)){
         for(const std::string& keyword : keywords){
              if(line.find(keyword) != std::string::npos){//find returns index of first occurence of substring in a string                                          
                std::lock_guard<std::mutex> lock(countMutex); //else returns std::string::npos
                keywordCounts[keyword]++;
              }
         }
   }
}

void LogAnalyzer::printSummary() const {

  

    std::cout << "\n--- Keyword Summary ---\n";

    std::for_each(keywordCounts.begin(), keywordCounts.end(), [](const std::pair<std::string, int>& pair) {
        std::cout <<  pair.first << ": " << pair.second << "\n";
    });

    std::cout << "-----------------------\n";
}
