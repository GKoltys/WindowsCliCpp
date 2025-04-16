#ifndef LOGGER_H
#define LOGGER_h

#include <string>

class Logger
{
public:
    static void init(const std::string& filename = "WCLILog.txt");
    static void close();

    static void setLogToConsole(const bool);
    static bool getLogToConsole();
    static bool getFileState();

    static void log(const std::string& message, const std::string& level, const bool forceLog = false);
    static void startTestCase(const std::string& message);
    static void startTestCase(const int testID, const std::string& message);

private:
    static std::ofstream _logFile;
    static bool _fileReady;
    static bool _logToConsole;
};

#endif