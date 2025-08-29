#ifndef CD_H
#define CD_H

#include "../Command/DirectoryCommand.h"

class Cd : public DirectoryCommand
{
public:
    void execute(CliContext* ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "cd"; }
};

#endif