#ifndef CLS_H
#define CLS_H

#include "../Command/stdCommand.h"

class Cls : public StdCommand
{
public:
    void execute(CliContext& ctx);

protected:
    std::string getName();
};

#endif