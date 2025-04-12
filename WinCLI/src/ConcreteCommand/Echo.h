#ifndef ECHO_H
#define ECHO_H

#include "../Command/OutputCommand.h"

class Echo : public OutputCommand
{
public:
    Echo();

    void execute(CliContext& ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override;
};

#endif