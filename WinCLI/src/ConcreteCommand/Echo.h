#ifndef ECHO_H
#define ECHO_H

#include "../Command/OutputCommand.h"

class Echo : public OutputCommand
{
public:
    Echo(const std::vector<std::string>& args);

    void execute(CLIContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif