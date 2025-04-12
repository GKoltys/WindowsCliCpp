#ifndef PUSHD_H
#define PUSHD_H

#include "../Command/DirectoryCommand.h"

class Cd;

class Pushd : DirectoryCommand
{
public:
    Pushd(Cd* cdHelper);

    void execute(CliContext& ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override;

private:
    Cd* _cdHelper;
};

#endif