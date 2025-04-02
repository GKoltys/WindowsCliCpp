#ifndef POPD_H
#define POPD_H

#include "../Command/DirectoryCommand.h"

class Popd : public DirectoryCommand
{
public:
    void execute(CliContext ctx);

protected:
    std::string getName();
};

#endif