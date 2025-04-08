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

bool Logger::_debugMode = false;

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

void Logger::setDebugMode(const bool debugMode)
{
    _debugMode = debugMode;
}

bool Logger::getDebugMode()
{
    return _debugMode;
}

bool Logger::getFileState()
{
    return _fileReady;
}

// Standard log with only message
void Logger::log(const std::string& message)
{
    string logEntry = Utils::getDateTime() + " " + message + "\n";

    if (_debugMode)
    {
        cout << logEntry << endl;
    }

    if (_fileReady)
    {
        _logFile << logEntry << endl;
    }
}

// Log with extra log level
void Logger::log(const std::string& message, const string& level)
{
    string logEntry = Utils::getDateTime() + " [" + level + "] " + message + "\n";

    if (_debugMode)
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

    if (_debugMode)
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

    if (_debugMode)
    {
        cout << logEntry << endl;
    }

    if (_fileReady)
    {
        _logFile << logEntry;
    }
}
