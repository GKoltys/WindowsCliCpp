#ifndef DIRECTORY_COMMAND_H
#define DIRECTORY_COMMAND_H

#include "Command.h"

class DirectoryCommand : public Command
{
public:
    virtual ~DirectoryCommand() = default;

protected:
    std::string getPrefix() const override { return "dir_"; }
};

#endif