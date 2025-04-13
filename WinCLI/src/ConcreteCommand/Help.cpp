#include <iostream>
#include "Help.h"

using namespace std;

Help::Help()
{
    initialiseHelpMap();
}

// Structure unordered_map<key (string): Command Name,
// Value (vector<string>): {Command Syntax, Command Description}>
void Help::initialiseHelpMap()
{
    _helpTexts["cd"] = { "cd [path]", "Changes the current directory to [path]."};
    _helpTexts["dir"] = { "dir [path]", "Lists contents of the current directory." };
    _helpTexts["echo"] = { "echo [message]", "Prints the given text to the screen." };
    _helpTexts["exit"] = { "exit", "Exits the command line interpreter." };
    _helpTexts["help"] = { "help [command-name]", "Shows help for supported commands." };
    _helpTexts["pushd"] = { "pushd [path | ..]", "Stores the current directory for use by the popd command, then\n\t\tchanges to the specified directory." };
    _helpTexts["popd"] = { "popd", "Changes to the directory stored by the pushd command." };
    _helpTexts["cls"] = { "cls", "Clears the screen." };
}

void Help::execute(CliContext& ctx, const vector<string>& args)
{
    if (args.size() > 2)
    {
        cout << "Usage: help [command-name]\n" << endl;
        return;
    }
    if (args.size() == 2)
    {
        if (_helpTexts.count(args[1]))
        {
            auto cmd = _helpTexts.find(args[1]);
            cout << cmd->second[1] << "\n\n" << cmd->second[0] << "\n" << endl;
        }
        else
        {
            cout << "This command is not supported by the help utility" << endl << endl;
        }
    }
    else
    {
        cout << "For more information on a specific command, type help [command-name]\n" << endl;
        for (const auto& cmd : _helpTexts)
        {
            cout << cmd.first << "\t\t" << cmd.second[1] << endl;
        }
        cout << endl;
    }
}