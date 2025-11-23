#include "DirectoryManager.h"

namespace fs = std::filesystem;

void DirectoryManager::copyDirectory(const fs::path& source, const fs::path& destination){
     
   if(fs::exists(source)){
        fs::copy(source, destination, fs::copy_options::recursive | fs::copy_options::directories_only);
    }
}


std::vector<fs::path> DirectoryManager::getFilesInDirectory(const std::filesystem::path& dirPath){

    std::vector<fs::path> filePaths;
    
    if(!fs::exists(dirPath)){
        throw std::runtime_error("Directory does not exist: " + dirPath.string());
    }

    fs::recursive_directory_iterator begin(dirPath);
    fs::recursive_directory_iterator end;

    for(auto& iter{begin}; iter!=end; ++iter) {
        
        auto& entry = *iter;

        if(fs::is_regular_file(entry)){
            filePaths.push_back(entry.path());
        }
    }
    return filePaths;
}