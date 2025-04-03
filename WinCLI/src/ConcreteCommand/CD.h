#ifndef CD_H
#define CD_H

#include "../Command/DirectoryCommand.h"

class Cd : public DirectoryCommand
{
public:
    Cd(const std::vector<std::string>& args);

    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif