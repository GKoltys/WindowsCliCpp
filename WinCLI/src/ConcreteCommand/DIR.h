#ifndef DIR_H
#define DIR_H

#include "../Command/DirectoryCommand.h"

class DIR : public DirectoryCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif