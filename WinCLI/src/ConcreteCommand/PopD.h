#ifndef POPD_H
#define POPD_H

#include "../Command/DirectoryCommand.h"

class Popd : public DirectoryCommand
{
public:
    Popd(Command* cdHelper);

    void execute(CliContext& ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "popd"; }

private:
    Command* _cdHelper;
};

#endif