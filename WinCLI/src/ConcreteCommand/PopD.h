#ifndef POPD_H
#define POPD_H

#include "../Command/DirectoryCommand.h"

class Cd;

class Popd : public DirectoryCommand
{
public:
    Popd(Cd* cdHelper);
    // No explicit destructor since Cd is destroyed in CommandManager

    void execute(CliContext& ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "popd"; }

private:
    Cd* _cdHelper;
};

#endif