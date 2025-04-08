#include <fstream>
#include <iostream>
#include "Config.h"
#include "../Libs/json.hpp"

using json = nlohmann::json;
using namespace std;

void Config::loadFromJson(const string& path)
{
    ifstream file(path);

    if (!file)
    {
        cout << "no file" << endl;
        return;
    }

    json j;
    file >> j;

    if (j.contains("logging"))
    {
        const json& log = j["logging"];
        _logToConsole = log.value("consoleLog", false);
        _logToFile = log.value("fileLog", false);
        _logFilename = log.value("filename", "WCLILogger.txt");
    }

    if (j.contains("theme"))
    {
        const json& theme = j["theme"];
        _backgroundColour = theme.value("backgroundColour", "0");
        _textColour = theme.value("textColour", "F");
    }
}

bool Config::isLog() const
{
    return _logToConsole;
}

bool Config::isLogFile() const
{
    return _logToFile;
}

string Config::getBackgroundColour() const
{
    return _backgroundColour;
}

std::string Config::getTextColour() const
{
    return _textColour;
}

std::string Config::getLogFilename() const
{
    return _logFilename;
}
