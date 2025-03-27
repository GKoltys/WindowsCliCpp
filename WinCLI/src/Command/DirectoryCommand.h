#ifndef DIRECTORY_COMMAND_H
#define DIRECTORY_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"

class DirectoryCommand : public Command
{
public:
    DirectoryCommand(std::vector<std::string>);
    ~DirectoryCommand();

protected:
    std::string getPrefix() const;
    std::vector<std::string> getArgs() const;

private:
    std::vector<std::string> args;
};

#endif