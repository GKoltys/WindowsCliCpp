#ifndef CLS_H
#define CLS_H

#include "../Command/stdCommand.h"

class Cls : public StdCommand
{
public:
    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;
};

#endif