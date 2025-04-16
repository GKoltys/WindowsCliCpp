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
ofstream Logger::_logFile;

// Ensures only one file is open at a time
bool Logger::_fileReady = false;

bool Logger::_logToConsole = false;

// Opens log file on users command
void Logger::init(const std::string& filename)
{
    // Makes sure no files are already open
    if (!_fileReady)
    {
        _logFile.open(filename, ios::trunc);
        _fileReady = true;
        if (!_logFile.is_open())
        {
            _fileReady = false;
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
    if (_fileReady)
    {
        if (_logFile.is_open())
        {
            _logFile.close();
            _fileReady = false;
        }
    }
    else
    {
        cerr << "Error: Nothing to close" << endl;
    }
}

void Logger::setLogToConsole(const bool logToConsole)
{
    _logToConsole = logToConsole;
}

bool Logger::getLogToConsole()
{
    return _logToConsole;
}

bool Logger::getFileState()
{
    return _fileReady;
}

// Standard log with extra log level and force parameter
void Logger::log(const std::string& message, const string& level, const bool forceLog)
{
    string logEntry = Utils::getDateTime() + " [" + level + "] " + message + "\n";

    if (forceLog)
    {
        cout << message << endl << endl;
    }

    if (_logToConsole)
    {
        cout << logEntry << endl;
    }

    if (_fileReady)
    {
        _logFile << logEntry;
    }
}

// Log for test case name display
void Logger::startTestCase(const std::string& message)
{
    string logEntry = "\n---- " + message + " ----\n";

    if (_logToConsole)
    {
        cout << logEntry << endl;
    }

    if (_fileReady)
    {
        _logFile << logEntry;
    }
}

// Special log for test case name display along with test ID
void Logger::startTestCase(const int testID, const std::string& message)
{
    string logEntry = "\n---- Test Case " + to_string(testID) + ": " + message + " ----" + "\n";

    if (_logToConsole)
    {
        cout << logEntry << endl;
    }

    if (_fileReady)
    {
        _logFile << logEntry;
    }
}
