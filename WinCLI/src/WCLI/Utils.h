#ifndef UTILS_H
#define UTILS_H

#include <filesystem>
#include <string>
#include <vector>

namespace Utils
{
    std::filesystem::path currentPath();
    std::vector<std::string> parse(std::string cmdIn);
    std::string getDateTime();
    bool verifyPath(const std::filesystem::path& path);
};

#endif