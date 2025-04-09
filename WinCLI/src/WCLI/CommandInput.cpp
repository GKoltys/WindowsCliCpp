#include <string>
#include <vector>
#include "CommandInput.h"
#include "Utils.h"

using namespace std;

CommandInput::CommandInput(std::string rawIn, std::vector<std::string> parsed) :
    _rawCommand(rawIn),
    _parsed(parsed) 
{}

string CommandInput::getRawCmd() const
{
    return _rawCommand;
}

vector<string> CommandInput::getArgs() const
{
    return _parsed;
}

int CommandInput::getArgCount() const
{
    return _parsed.size();
}