#ifndef DIRECTORY_COMMAND_H
#define DIRECTORY_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"

// Continue this format

class DirectoryCommand : public Command
{
public:
    DirectoryCommand();
    ~DirectoryCommand();

protected:
    std::string getPrefix() const override;
};

#endif