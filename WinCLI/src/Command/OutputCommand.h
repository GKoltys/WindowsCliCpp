#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#include <string>
#include <vector>
#include "Command.h"

class OutputCommand : public Command
{
public:
    OutputCommand(const std::vector<std::string>& args);
    virtual ~OutputCommand() = default;

protected:
    std::string getPrefix() const override;
    std::vector<std::string> getArgs() const;

private:
    std::vector<std::string> _args;
};

#endif