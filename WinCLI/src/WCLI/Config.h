#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config
{
public:
    void loadFromJson(const std::string& path);

    bool isLog() const;
    bool isLogFile() const;
    std::string getBackgroundColour() const;
    std::string getTextColour() const;
    std::string getLogFilename() const;

private:
    bool _logToConsole = false;
    bool _logToFile = false;
    std::string _logFilename = "default.txt";
    std::string _backgroundColour = "0";
    std::string _textColour = "F";
};

#endif