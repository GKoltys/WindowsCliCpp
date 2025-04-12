#ifndef POPD_H
#define POPD_H

#include "../Command/DirectoryCommand.h"

class Cd;

class Popd : public DirectoryCommand
{
public:
    Popd(Cd* cdHelper);

    void execute(CliContext& ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override;

private:
    Cd* _cdHelper;
};

#endif