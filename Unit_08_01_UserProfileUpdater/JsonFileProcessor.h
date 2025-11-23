#pragma once

#include <fstream>
#include <string>
#include "json.hpp"



class JsonFileProcessor{
    


    public:
    
    JsonFileProcessor();
 
    nlohmann::ordered_json readJson(const std::string filePath);

    void writeJson(const std::string filePath, const nlohmann::ordered_json& j);

};