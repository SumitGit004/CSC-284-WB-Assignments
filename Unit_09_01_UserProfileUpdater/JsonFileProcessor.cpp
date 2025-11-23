#include "JsonFileProcessor.h"

using json = nlohmann::ordered_json;

JsonFileProcessor::JsonFileProcessor() = default;

json JsonFileProcessor::readJson(const std::string filePath){

       
        std::ifstream file;

        file.open(filePath, std::ios::in);

        if(!file){
            throw std::runtime_error("Could not open filezzz for reading: " + filePath);
        }
        

        json j = json::parse(file);

        file.close();

        return j;
    
}
        

void JsonFileProcessor::writeJson(const std::string filePath, const json& j){
        
        std::ofstream file;

        file.open(filePath,  std::ios::out);
        if(!file){
            throw std::runtime_error("Could not open file for writing: " + filePath);
        }
        
        file << j.dump(4);// write to file in json format with specified integer indent
        file.close();

}