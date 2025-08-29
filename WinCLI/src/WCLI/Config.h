#ifndef CONFIG_H
#define CONFIG_H

#include "../Libs/json.hpp"

class Config
{
public:
    void loadFromJson(const std::string& path);

    nlohmann::json toJson() const;

    bool isLog() const { return _logToConsole; }
    bool isLogFile() const { return _logToFile; }
    std::string getBackgroundColour() const { return _backgroundColour; }
    std::string getTextColour() const { return _textColour; }
    std::string getLogFilename() const { return _logFilename; }

private:
    bool _logToConsole = false;
    bool _logToFile = true;
    std::string _logFilename = "WinCli.log";
    std::string _backgroundColour = "0";
    std::string _textColour = "F";
};

#endif