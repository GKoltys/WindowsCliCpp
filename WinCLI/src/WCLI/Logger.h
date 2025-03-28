#ifndef LOGGER_H
#define LOGGER_h

#include <string>

class Logger
{
public:
    static void init(const std::string& filename = "WCLILog.txt");
    static void close();

    static void log(const std::string& message);
    static void log(const std::string& message, const std::string& level);
    static void startTestCase(const std::string& message);
    static void startTestCase(const int testID, const std::string& message);

private:
    static std::ofstream logFile;
    static bool fileReady;
};

#endif