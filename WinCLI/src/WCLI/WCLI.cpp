#include <iostream>
#include <string>
#include "WCLI.h"
#include "Utils.h"
#include "../ConcreteCommand/Cd.h"
#include "../ConcreteCommand/Cls.h"
#include "../ConcreteCommand/Dir.h"
#include "../ConcreteCommand/Echo.h"
#include "../ConcreteCommand/Help.h"
#include "../ConcreteCommand/Popd.h"
#include "../ConcreteCommand/pushd.h"
#include "../ConcreteCommand/Exit.h"

using namespace std;

WCLI::WCLI() : _context(CliContext()), _logger(Logger())
{
   //_config = Config();
}

void WCLI::run()
{
    while (!_context.getExitState())
    {
        string cmdIn;

        cout << _context.getCurrentDirStr() << ">";
        getline(cin, cmdIn);

        if (cmdIn == "")
        {
            continue;
        }

        CommandInput command(cmdIn);

        executeCommand(command);
    }
}

void WCLI::executeCommand(const CommandInput& input)
{
    string commandInput = input.getArgs()[0];

    try
    {
        if (commandInput == "cd")
        {
            Cd toExecute(input.getArgs());
            toExecute.execute(_context);
        }
        else if (commandInput == "dir")
        {
            Dir toExecute(input.getArgs());
            toExecute.execute(_context);
        }
        else if (commandInput == "echo")
        {
            Echo toExecute(input.getArgs());
            toExecute.execute(_context);
        }
        else if (commandInput == "help")
        {
            Help toExecute(input.getArgs());
            toExecute.execute(_context);
        }
        else if (commandInput == "popd")
        {
            Popd toExecute(input.getArgs());
            toExecute.execute(_context);
        }
        else if (commandInput == "pushd")
        {
            Pushd toExecute(input.getArgs());
            toExecute.execute(_context);
        }
        else if (commandInput == "exit")
        {
            Exit toExecute;
            toExecute.execute(_context);
        }
        else if (commandInput == "cls")
        {
            Cls toExecute;
            toExecute.execute(_context);
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
