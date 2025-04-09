#ifndef COMMAND_INPUT_H
#define COMMAND_INPUT_H

#include <string>
#include <vector>

class CommandInput
{
public:
    CommandInput(std::string rawIn, std::vector<std::string> parsed);
    std::string getRawCmd() const;
    std::vector<std::string> getArgs() const;
    int getArgCount() const;

private: 
    std::string _rawCommand;
    std::vector<std::string> _parsed;
};

#endif