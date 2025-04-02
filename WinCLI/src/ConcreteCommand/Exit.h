#ifndef QUIT_H
#define QUIT_H

#include "../Command/StdCommand.h"

class Exit : public StdCommand
{
public:
    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif