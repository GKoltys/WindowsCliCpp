#include <filesystem>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Utils.h"

using namespace std;

filesystem::path Utils::currentPath()
{
    return filesystem::current_path();
}

vector<string> Utils::parse(string cmdIn)
{
    vector<string> parsed;
    string separate;
    std::istringstream stream(cmdIn);

    while (getline(stream, separate, ' ')) {
        parsed.push_back(separate);
    }

    return parsed;
}

string Utils::getDateTime()
{
    time_t now = time(nullptr);
    tm localTime;

    localtime_s(&localTime, &now);

    ostringstream oss;
    oss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

bool Utils::verifyPath(const filesystem::path& path)
{
    return filesystem::exists(path) && filesystem::is_directory(path);
}
