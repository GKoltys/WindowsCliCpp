#ifndef CONFIG_H
#define CONFIG_H

class Config
{
public:
    void loadFromJson(const std::string& path);

    bool isLog() const { return _logToConsole; }
    bool isLogFile() const { return _logToFile; }
    std::string getBackgroundColour() const { return _backgroundColour; }
    std::string getTextColour() const { return _textColour; }
    std::string getLogFilename() const { return _logFilename; }

private:
    bool _logToConsole = false;
    bool _logToFile = false;
    std::string _logFilename = "default.txt";
    std::string _backgroundColour = "0";
    std::string _textColour = "F";
};

#endif