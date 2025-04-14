#ifndef DIR_H
#define DIR_H

#include "../Command/DirectoryCommand.h"

class Dir : public DirectoryCommand
{
public:
    void execute(CliContext* ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "dir"; }
};

#endif