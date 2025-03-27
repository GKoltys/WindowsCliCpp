#ifndef HELP_H
#define HELP_H

#include "../Command/OutputCommand.h"

class HELP : public OutputCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif