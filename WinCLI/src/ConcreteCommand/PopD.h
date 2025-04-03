#ifndef POPD_H
#define POPD_H

#include "../Command/DirectoryCommand.h"

class Popd : public DirectoryCommand
{
public:
    Popd(const std::vector<std::string>& args);

    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif