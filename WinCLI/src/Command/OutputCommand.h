#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"

class OutputCommand : public Command
{
public:
    virtual ~OutputCommand() = default;

protected:
    std::string getPrefix() const override;
};

#endif