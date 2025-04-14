#ifndef ECHO_H
#define ECHO_H

#include "../Command/OutputCommand.h"

class Echo : public OutputCommand
{
public:
    void execute(CliContext* ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "echo"; }
};

#endif