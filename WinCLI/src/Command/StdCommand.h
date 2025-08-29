#ifndef STD_COMMAND_H
#define STD_COMMAND_H

#include "Command.h"

class StdCommand : public Command
{
public:
    virtual ~StdCommand() = default;

protected:
    std::string getPrefix() const override { return "std_"; }
};

#endif