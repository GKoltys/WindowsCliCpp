#ifndef PUSHD_H
#define PUSHD_H

#include "../Command/DirectoryCommand.h"

class Pushd : DirectoryCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif