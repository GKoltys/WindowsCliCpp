#include "CommandInput.h"
#include "Utils.h"

using namespace std;

CommandInput::CommandInput(std::string rawIn, std::vector<std::string> parsed) :
    _rawCommand(rawIn),
    _parsed(parsed) 
{}

int CommandInput::getArgCount() const
{
    return _parsed.size();
}