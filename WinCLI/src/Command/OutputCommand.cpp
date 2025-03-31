#include <string>
#include "OutputCommand.h"

using namespace std;

OutputCommand::OutputCommand(const vector<string>& args) : _args(args) {}

string OutputCommand::getPrefix() const
{
    return "out_";
}

vector<string> OutputCommand::getArgs() const
{
    return _args;
}
