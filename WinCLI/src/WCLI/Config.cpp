#include <fstream>
#include <iostream>
#include "Config.h"
#include "Logger.h"
#include "../Libs/json.hpp"

using json = nlohmann::json;
using namespace std;

void Config::loadFromJson(const string& path)
{
    ifstream file(path);

    if (!file)
    {
        // This will turn to using the default fields specified in the Config class
        cout << "Couldn't open file at: " << path << endl << "Starting CLI with default configurations" << endl << endl;
        Logger::log("Couldn't open file at: " + path + "Starting CLI with default configurations");
        return;
    }

    json configJson;
    file >> configJson;

    if (configJson.contains("logging"))
    {
        const json& log = configJson["logging"];
        if (log.contains("consoleLog") && log["consoleLog"].is_boolean())
        {
            _logToConsole = log["consoleLog"];
        }
        if (log.contains("fileLog") && log["fileLog"].is_boolean())
        {
            _logToFile = log["fileLog"];
        }
        if (log.contains("filename") && log["filename"].is_string())
        {
            _logFilename = log["filename"];
        }
    }

    if (configJson.contains("theme"))
    {
        const json& theme = configJson["theme"];
        if (theme.contains("backgroundColour") && theme["backgroundColour"].is_string())
        {
            _backgroundColour = theme["backgroundColour"];
        }
        if (theme.contains("textColour") && theme["textColour"].is_string())
        {
            _textColour = theme["textColour"];
        }
    }
}