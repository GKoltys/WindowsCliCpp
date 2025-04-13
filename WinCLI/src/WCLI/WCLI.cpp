#include <iostream>
#include <cstring>
#include "Logger.h"
#include "WCLI.h"
#include "Utils.h"
#include "CommandInput.h"

using namespace std;

WCLI::WCLI() : _context(CliContext()), _config(Config()), _cmdManager(CommandManager()) {}

void WCLI::applyConfig()
{
    Logger::setDebugMode(_config.isLog());

    string themeCommand = "color " + _config.getBackgroundColour() + _config.getTextColour();
    system(themeCommand.c_str());
    
    if (_config.isLogFile())
    {
        Logger::init(_config.getLogFilename());
    }

    Logger::log("Config applied");
}

void WCLI::runWithConfigFile(const string& path)
{
    _config.loadFromJson(path);
    run();
}

void WCLI::run()
{
    applyConfig();

    Logger::log("Shell started");

    while (!_context.getExitState())
    {
        try
        {
            string cmdIn;

            cout << _context.getCurrentDirStr() << ">";
            getline(cin, cmdIn);

            if (cmdIn != "")
            {
                CommandInput command(cmdIn, Utils::parse(cmdIn));
                _cmdManager.executeCommand(_context, command.getArgs());
            }
        }
        catch (const exception& e)
        {
            Logger::log(e.what(), "[ERROR]");
        }
    }

    if (Logger::getFileState())
    {
        Logger::close();
    }
}
