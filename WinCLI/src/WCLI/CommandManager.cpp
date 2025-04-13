#include <iostream>
#include "CommandManager.h"
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
}

void CommandManager::executeCommand(CliContext& ctx, const vector<string>& args)
{
    if (args.empty())
    {
        return;
    }

    const string& commandName = args[0];
    auto chosenCommand = _commands.find(commandName);

    // Make sure find() didnt return end()/last element of map
    if (chosenCommand != _commands.end())
    {
        chosenCommand->second->execute(ctx, args);
    }
    else
    {
        cout << "'" << commandName << "' is not recognised as a command.\n";
    }
}
