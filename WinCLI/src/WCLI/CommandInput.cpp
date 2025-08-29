#include "CommandInput.h"

using namespace std;

CommandInput::CommandInput(std::string rawIn, std::vector<std::string> parsed) :
    _rawCommand(rawIn),
    _parsed(parsed) 
{}

size_t CommandInput::getArgCount() const
{
    return _parsed.size();
}