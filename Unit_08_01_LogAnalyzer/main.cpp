#include "LogAnalyzer.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <vector>

namespace fs = std::filesystem;//create an alias for shorter name

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <log_directory>\n";
        return 1;
    }

    std::string folderPath = argv[1];
    LogAnalyzer analyzer;
    std::vector<std::string> keywords = {"[WARN]", "[ERROR]", "[FATAL]", "[INFO]","[DEBUG]","[TRACE]" };
    std::vector<std::thread> threads;

    std::cout << "Analyzing folder: " << folderPath << "\n\n";
     
    if(!fs::exists(folderPath) || !fs::is_directory(folderPath)){
        std::cerr << "Error: Provided path is not a valid directory.\n";
        return 1;
    }

    for(const auto& entry : fs::directory_iterator(folderPath)){
        if(entry.is_regular_file() && entry.path().extension() == ".log"){
             /*add a new thread to process the log file, using pointer to the member function
              so we dont need to overload function call operator() in LogAnalzyer*/
            threads.push_back(std::thread(&LogAnalyzer::analyzeFile,&analyzer,entry.path().string(), keywords));
        }
    }

    for(auto& thread : threads){
        thread.join();
    }
 
    analyzer.printSummary();

    return 0;
}
