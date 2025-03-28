#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include "Logger.h"
#include "Utils.h"

using namespace std;

// Initialises static file var
ofstream Logger::logFile;

// Ensures only one file is open at a time
bool Logger::fileReady = false;

// Opens log file on users command
void Logger::init(const std::string& filename)
{
    // Makes sure no files are already open
    if (!fileReady)
    {
        logFile.open(filename, ios::trunc);
        fileReady = true;
        if (!logFile.is_open())
        {
            fileReady = false;
            cerr << "Error: Could not open log file: " << filename << endl;
        }
    }
    else
    {
        cerr << "Error: Another file is already open" << endl;
    }
}

// Closes log file on users command
void Logger::close()
{
    // Makes sure there is an open file
    if (fileReady)
    {
        if (logFile.is_open())
        {
            logFile.close();
            fileReady = false;
        }
    }
    else
    {
        cerr << "Error: Nothing to close" << endl;
    }
}

// Standard log with only message
void Logger::log(const std::string& message)
{
    string logEntry = Utils::getDateTime() + " " + message + "\n";

    cout << logEntry << endl;

    if (fileReady)
    {
        logFile << logEntry << endl;
    }
}

// Log with extra log level
void Logger::log(const std::string& message, const string& level)
{
    string logEntry = Utils::getDateTime() + " [" + level + "] " + message + "\n";

    cout << logEntry << endl;

    if (fileReady)
    {
        logFile << logEntry;
    }
}

// Log for test case name display
void Logger::startTestCase(const std::string& message)
{
    string logEntry = "\n---- " + message + " ----\n";

    cout << logEntry << endl;

    if (fileReady)
    {
        logFile << logEntry;
    }
}

// Special log for test case name display along with test ID
void Logger::startTestCase(const int testID, const std::string& message)
{
    string logEntry = "\n---- Test Case " + to_string(testID) + ": " + message + " ----" + "\n";

    cout << logEntry << endl;

    if (fileReady)
    {
        logFile << logEntry;
    }
}