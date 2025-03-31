#ifndef QUIT_H
#define QUIT_H

#include "../Command/StdCommand.h"

class Quit : public StdCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif