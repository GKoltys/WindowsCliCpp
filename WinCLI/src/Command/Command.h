#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../WCLI/WCLI.h"

class Command
{
public:
    virtual ~Command();
    virtual void execute(CLIContext ctx);

protected:
    virtual std::string getName() const;
    virtual std::string getPrefix() const;
};

#endif