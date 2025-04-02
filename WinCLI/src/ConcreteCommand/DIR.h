#ifndef DIR_H
#define DIR_H

#include "../Command/DirectoryCommand.h"

class Dir : public DirectoryCommand
{
public:
    Dir(const std::vector<std::string>& args);

    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif