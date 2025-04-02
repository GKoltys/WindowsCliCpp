#ifndef PUSHD_H
#define PUSHD_H

#include "../Command/DirectoryCommand.h"

class Pushd : DirectoryCommand
{
public:
    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif