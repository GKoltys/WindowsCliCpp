#ifndef CLS_H
#define CLS_H

#include "../Command/stdCommand.h"

class Cls : public StdCommand
{
public:
    void execute(CliContext* ctx, const std::vector<std::string>& args) override;

protected:
    std::string getName() const override { return "cls"; }
};

#endif