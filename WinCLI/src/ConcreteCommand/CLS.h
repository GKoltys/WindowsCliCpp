#ifndef CLS_H
#define CLS_H

#include "../Command/stdCommand.h"

class CLS : public StdCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif