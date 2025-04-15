#include <iostream>
#include "CommandManager.h"
#include "Logger.h"
#include "../ConcreteCommand/Cd.h"
#include "../ConcreteCommand/Cls.h"
#include "../ConcreteCommand/Dir.h"
#include "../ConcreteCommand/Echo.h"
#include "../ConcreteCommand/Exit.h"
#include "../ConcreteCommand/Help.h"
#include "../ConcreteCommand/Popd.h"
#include "../ConcreteCommand/Pushd.h"

using namespace std;

CommandManager::CommandManager()
{
    Logger::log("Command Manager Initialised", "DEBUG");
    _commands["cd"] = new Cd();
    _commands["cls"] = new Cls();
    _commands["dir"] = new Dir();
    _commands["echo"] = new Echo();
    _commands["exit"] = new Exit();
    _commands["help"] = new Help();
    _commands["popd"] = new Popd(_commands["cd"]);
    _commands["pushd"] = new Pushd(_commands["cd"]);
}

CommandManager::~CommandManager()
{
    for (auto& [name, command] : _commands)
    {
        delete command;
    }
    Logger::log("Command Manager destroyed", "DEBUG");
}

void CommandManager::executeCommand(CliContext* ctx, const vector<string>& args)
{
    if (args.empty())
    {
        return;
    }

    const string& commandName = args[0];
    auto chosenCommand = _commands.find(commandName);

    if (chosenCommand != _commands.end())
    {
        Logger::log(commandName + " being executed", "DEBUG");
        chosenCommand->second->execute(ctx, args);
    }
    else
    {
        Logger::log("'" + commandName + "' is not recognised as a command.\n", "INFO");
        cout << "'" << commandName << "' is not recognised as a command.\n";
    }
}
