#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../WCLI/WCLI.h"

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(CliContext& ctx) = 0;
    virtual std::string getName() const = 0;
    virtual std::string getPrefix() const = 0;
};

#endif