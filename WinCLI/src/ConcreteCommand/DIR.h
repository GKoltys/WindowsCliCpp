#ifndef DIR_H
#define DIR_H

#include "../Command/DirectoryCommand.h"

class Dir : public DirectoryCommand
{
public:
    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif