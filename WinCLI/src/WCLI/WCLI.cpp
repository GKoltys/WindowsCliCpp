#include <iostream>
#include <string>
#include "WCLI.h"
#include "Utils.h"

using namespace std;

WCLI::WCLI() : _context(CLIContext()), _logger(Logger())
{
   //_config = Config();
}

void WCLI::run()
{
    while (true)
    {
        string cmdIn;

        cout << _context.getCurrentDir() << ">";
        getline(cin, cmdIn);

        CommandInput command(cmdIn);

        executeCommand(command);
        cout << cmdIn << endl;
    }
}

void WCLI::executeCommand(const CommandInput& input)
{
    cout << to_string(input.getArgCount()) << endl;

    string commandInput = input.getArgs()[0];

    try
    {
        if (commandInput == "cd")
        {
            ;
        }
        else if (commandInput == "dir")
        {

        }
        else if (commandInput == "echo")
        {

        }
        else if (commandInput == "help")
        {

        }
        else if (commandInput == "popd")
        {

        }
        else if (commandInput == "pushd")
        {

        }
        else if (commandInput == "quit")
        {

        }
        else if (commandInput == "cls")
        {

        }
        else
        {
            throw(commandInput);
        }
    }
    catch (string notSupported)
    {
        cout << "No command " << notSupported << " found" << endl;
    }
}
