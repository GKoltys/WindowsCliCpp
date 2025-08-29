#ifndef EXIT_H
#define EXIT_H

#include "../Command/StdCommand.h"

class Exit : public StdCommand
{
public:
    void execute(CliContext* ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "exit"; }
};

#endif