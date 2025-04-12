#include <string>
#include <vector>
#include <iostream>
#include "CliContext.h"
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

CommandManager::CommandManager() {
    _cd = new Cd();
    _cls = new Cls();
    _dir = new Dir();
    _echo = new Echo();
    _exit = new Exit();
    _help = new Help();
    _popd = new Popd(_cd);
    _pushd = new Pushd(_cd);
}

CommandManager::~CommandManager() {
    delete _cd;
    delete _cls;
    delete _dir;
    delete _echo;
    delete _exit;
    delete _help;
    delete _popd;
    delete _pushd;
}

void CommandManager::executeCommand(CliContext& ctx, const vector<string>& args)
{
    string commandInput = args[0];

    try
    {
        if (commandInput == "cd")
        {
            _cd->execute(ctx, args);
        }
        else if (commandInput == "dir")
        {
            _dir->execute(ctx, args);
        }
        else if (commandInput == "echo")
        {
            _echo->execute(ctx, args);
        }
        else if (commandInput == "help")
        {
            _help->execute(ctx, args);
        }
        else if (commandInput == "popd")
        {
            _popd->execute(ctx, args);
        }
        else if (commandInput == "pushd")
        {
            _pushd->execute(ctx, args);
        }
        else if (commandInput == "exit")
        {
            _exit->execute(ctx, args);
        }
        else if (commandInput == "cls")
        {
            _cls->execute(ctx, args);
        }
        else
        {
            throw(commandInput);
        }
    }
    catch (string notSupported)
    {
        cout << "'" << notSupported << "'"
            << "is not recognised as an internal command"
            << endl;
    }
}