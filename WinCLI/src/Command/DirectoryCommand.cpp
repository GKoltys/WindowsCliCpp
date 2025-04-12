#include <string>
#include "Command.h"
#include "DirectoryCommand.h"

using namespace std;

DirectoryCommand::DirectoryCommand() {}

DirectoryCommand::~DirectoryCommand() {}

string DirectoryCommand::getPrefix() const
{
    return "dir_";
}
