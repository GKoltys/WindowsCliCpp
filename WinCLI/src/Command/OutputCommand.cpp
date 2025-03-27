#include <string>
#include "OutputCommand.h"

using namespace std;

OutputCommand::OutputCommand(vector<string> args) : _args(args) {}

OutputCommand::~OutputCommand()
{
}

string OutputCommand::getPrefix() const
{
    return string();
}

vector<string> OutputCommand::getArgs() const
{
    return vector<string>();
}
