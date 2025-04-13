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

    json configJson;
    file >> configJson;

    if (configJson.contains("logging"))
    {
        const json& log = configJson["logging"];
        _logToConsole = log.value("consoleLog", false);
        _logToFile = log.value("fileLog", false);
        _logFilename = log.value("filename", "WCLILogger.txt");
    }

    if (configJson.contains("theme"))
    {
        const json& theme = configJson["theme"];
        _backgroundColour = theme.value("backgroundColour", "0");
        _textColour = theme.value("textColour", "F");
    }
}