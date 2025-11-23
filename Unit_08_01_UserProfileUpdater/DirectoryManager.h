#pragma once

#include <filesystem>
#include <vector>

class DirectoryManager{
    public:
    
    static void copyDirectory(const std::filesystem::path& source, const std::filesystem::path& destination);

    static  std::vector<std::filesystem::path> getFilesInDirectory(const std::filesystem::path& dirPath);
};
