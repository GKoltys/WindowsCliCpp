#ifndef PUSHD_H
#define PUSHD_H

#include "../Command/DirectoryCommand.h"

class Pushd : DirectoryCommand
{
public:
    Pushd(const std::vector<std::string>& args);

    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif