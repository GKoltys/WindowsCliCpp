#ifndef POPD_H
#define POPD_H

#include "../Command/DirectoryCommand.h"

class POPD : public DirectoryCommand
{
public:
    void execute(CLIContext ctx);

protected:
    std::string getName();
};

#endif