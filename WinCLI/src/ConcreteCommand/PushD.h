#ifndef PUSHD_H
#define PUSHD_H

#include "../Command/DirectoryCommand.h"

class Pushd : public DirectoryCommand
{
public:
    Pushd(Command* cdHelper);

    void execute(CliContext* ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "pushd"; }

private:
    Command* _cdHelper;
};

#endif
