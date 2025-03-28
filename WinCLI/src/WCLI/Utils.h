#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace Utils
{
    std::string currentPath();
    std::vector<std::string> parse(std::string cmdIn);
    std::string getDateTime();
    bool verifyPath(const std::string& path);
};

#endif