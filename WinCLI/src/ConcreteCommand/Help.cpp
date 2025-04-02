#include <iostream>
#include <string>
#include <vector>
#include "Help.h"

using namespace std;

Help::Help(const vector<string>& args) : OutputCommand(args)
{
    initialiseHelpMap();
}

// update this to unordered_map<string, vector<string>>
void Help::initialiseHelpMap()
{
    _helpTexts["cd"] = "Changes the current directory to [path].";
    _helpTexts["dir"] = "Lists contents of the current directory.";
    _helpTexts["echo"] = "Prints the given text to the screen.";
    _helpTexts["exit"] = "Exits the command line interpreter.";
    _helpTexts["help"] = "Shows help for supported commands.";
    _helpTexts["pushd"] = "Stores the current directory for use by the popd command, then\n\t\tchanges to the specified directory.";
    _helpTexts["popd"] = "Changes to the directory stored by the pushd command.";
    _helpTexts["cls"] = "Clears the screen.";
}

void Help::execute(CliContext& ctx)
{
    vector<string> args = getArgs();

    if (args.size() > 2)
    {
        std::cout << "Usage: help [command-name]\n";
        return;
    }
    if (args.size() == 2)
    {
        if (_helpTexts.count(args[1]))
        {
            auto cmd = _helpTexts.find(args[1]);
            cout << cmd->second << "\n\n" << cmd->first << "\n" << endl;
        }
        else
        {
            cout << "This command is not supported by the help utility\n";
        }
    }
    else
    {
        cout << "For more information on a specific command, type help [command-name]\n" << endl;
        for (const auto& cmd : _helpTexts)
        {
            cout << cmd.first << "\t\t" << cmd.second << endl;
        }
        cout << endl;
    }
}

string Help::getName() const
{
    return "help";
}