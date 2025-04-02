#ifndef CD_H
#define CD_H

#include "../Command/DirectoryCommand.h"

class Cd : public DirectoryCommand
{
public:
    void execute(CliContext& ctx);

protected:
    std::string getName();
};

#endif