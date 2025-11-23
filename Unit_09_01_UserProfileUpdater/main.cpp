#include <iostream>
#include <iomanip>
#include <chrono>
#include <format>
#include <filesystem>
#include "DirectoryManager.h"
#include "JsonFileProcessor.h"
#include <vector>
#include <map>
#include <algorithm>

namespace fs = std::filesystem;
using systemClock = std::chrono::system_clock;
using json = nlohmann::ordered_json; // ordered json to preserve insertion order, otherwise keys are sorted alphabetically

std::string getCurrDateAndTime();

template <typename T>
int findIndex(const json &jArray, const T &value);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <log_directory>\n";
        return 1;
    }

    fs::path srcDir = argv[1];
    fs::path destDir = "user_profiles_updated_" + getCurrDateAndTime();

    std::map<std::string, json> updates;
    updates.insert({"enabled", {{"status", "enabled"}, {"since", "2024-10-01"}}});
    updates.insert({"disabled", {{"status", "disabled"}, {"since", "2024-10-01"}}});
    updates.insert({"manage_users", {{"permission", "manage_users"}, {"granted_at", "2024-10-05"}, {"level", "full"}}});
    updates.insert({"view_content", {{"permission", "view_content"}, {"granted_at", "2024-09-25"}, {"level", "read-only"}}});


    DirectoryManager::copyDirectory(srcDir, destDir);

    std::vector<fs::path> files = DirectoryManager::getFilesInDirectory(srcDir);

    JsonFileProcessor jsonProcessor;

    for (const auto &filePath : files)
    {

        // find the position of first "/" in the file path
        int pos = filePath.string().find("/");
        
        // get the sub path after the root directory
        std::string subPath = filePath.string().substr(pos);

        // create destination path
        fs::path destPath = destDir.string() + filePath.string().substr(pos);

        try
        {
           
            json j = jsonProcessor.readJson(filePath.string());

            std::string search = "@company.com";
            std::string replace = "@newcompany.com";

            std::string email = j["email"].get<std::string>();

            int pos = email.find(search);
            if (pos != std::string::npos)
            {
                email.replace(pos, search.length(), replace);
                j["email"] = email;
            }

            j["preferences"]["notifications"] = (j["preferences"]["notifications"] == "enabled" ? updates["enabled"] : updates["disabled"]);  

            int index = findIndex(j["permissions"], "manage_users");

            if (index != -1)
            {
                j["permissions"][index] = updates["manage_users"];
            }

            index = findIndex(j["permissions"], "view_content");

            if (index != -1)
            {
                j["permissions"][index] = updates["view_content"];
            }

            jsonProcessor.writeJson(destPath.string(), j);
        }

        catch (json::parse_error &e)
        {

            fs::copy(filePath, destPath);
        }

        catch(std::runtime_error &e){
            std::cout << "Couldn't open " << filePath.string() << " for reading\n";
        }
    }
}

std::string getCurrDateAndTime()
{

    auto now = systemClock::now();
    std::time_t t = systemClock::to_time_t(now);
    std::tm local_tm = *std::localtime(&t);

    std::string datetime_str = std::format(
        "{:04}{:02}{:02}_{:02}{:02}{:02}",
        1900 + local_tm.tm_year,
        1 + local_tm.tm_mon,
        local_tm.tm_mday,
        local_tm.tm_hour,
        local_tm.tm_min,
        local_tm.tm_sec);

    return (datetime_str);
}

template <typename T>
int findIndex(const json &jArray, const T &value)
{

    if (!jArray.is_array())
    {
        return -1;
    }

    auto it = std::find(jArray.begin(), jArray.end(), value);

    if (it == jArray.end())
    {
        return -1;
    }

    return std::distance(jArray.begin(), it);
}
