#include <string>
#include "DirectoryCommand.h"

using namespace std;

DirectoryCommand::DirectoryCommand(vector<string> args) : _args(args) {}

DirectoryCommand::~DirectoryCommand() {}

string DirectoryCommand::getPrefix() const
{
    return "dir_";
}

vector<string> DirectoryCommand::getArgs() const
{
    return _args;
}
