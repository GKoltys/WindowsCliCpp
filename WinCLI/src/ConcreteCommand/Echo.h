#ifndef ECHO_H
#define ECHO_H

#include "../Command/OutputCommand.h"

class ECHO : public OutputCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif