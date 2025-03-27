#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"

class OutputCommand : public Command
{
public:
    OutputCommand(std::vector<std::string> args);
    ~OutputCommand();

protected:
    std::string getPrefix() const;
    std::vector<std::string> getArgs() const;

private:
    std::vector<std::string> args;
};

#endif