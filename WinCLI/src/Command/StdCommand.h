#ifndef STD_COMMAND_H
#define STD_COMMAND_H

#include <string>
#include "Command.h"

class StdCommand : public Command
{
protected:
    std::string getPrefix();
};

#endif