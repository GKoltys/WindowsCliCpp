#include <fstream>
#include <iostream>
#include "Config.h"
#include "Logger.h"

using json = nlohmann::json;
using namespace std;

void Config::loadFromJson(const string& path)
{
    ifstream file(path);

    if (!file)
    {
        // This will turn to using the default fields specified in the Config class
        Logger::log("Couldn't open file at: " + path, "", true);
        
        json defaultJson = toJson();

        ofstream outFile(path);
        if (outFile)
        {
            outFile << defaultJson.dump(4);
            Logger::log("Default config file created at: " + path, "INFO", true);
        }
        else
        {
            Logger::log("Failed to create config file at: " + path, "ERROR", true);
        }
        
        file.open(path);
        if (!file)
        {
            Logger::log("Unable to reopen created config file\nRunning with default configurations", "ERROR", true);
            return;
        }
    }

    json configJson;
    file >> configJson;

    if (configJson.contains("logging"))
    {
        const json& log = configJson["logging"];
        if (log.contains("consoleLog") && log["consoleLog"].is_boolean())
        {
            _logToConsole = log["consoleLog"];
            Logger::log("consoleLog applied from Json", "INFO");
        }
        if (log.contains("fileLog") && log["fileLog"].is_boolean())
        {
            _logToFile = log["fileLog"];
            Logger::log("fileLog applied from Json", "INFO");
        }
        if (log.contains("filename") && log["filename"].is_string())
        {
            _logFilename = log["filename"];
            Logger::log("filename applied from Json", "INFO");
        }
    }

    if (configJson.contains("theme"))
    {
        const json& theme = configJson["theme"];
        if (theme.contains("backgroundColour") && theme["backgroundColour"].is_string())
        {
            _backgroundColour = theme["backgroundColour"];
            Logger::log("backgroundColour applied from Json", "INFO");
        }
        if (theme.contains("textColour") && theme["textColour"].is_string())
        {
            _textColour = theme["textColour"];
            Logger::log("textColour applied from Json", "INFO");
        }
    }
}

nlohmann::json Config::toJson() const
{
    return
    {
        { "logging", {
            { "consoleLog", _logToConsole },
            { "fileLog", _logToFile },
            { "filename", _logFilename }
        }},
        { "theme", {
            { "backgroundColour", _backgroundColour },
            { "textColour", _textColour}
        }}
    };
}
