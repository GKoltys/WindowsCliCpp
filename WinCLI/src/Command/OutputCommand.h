#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#include "Command.h"

class OutputCommand : public Command
{
public:
    virtual ~OutputCommand() = default;

protected:
    std::string getPrefix() const override { return "out_"; }
};

#endif