#ifndef HELP_H
#define HELP_H

#include <unordered_map>
#include "../Command/OutputCommand.h"

class Help : public OutputCommand
{
public:
    Help(const std::vector<std::string>& args);

    void execute(CliContext& ctx) override;

protected:
    std::string getName() const override;

private:
    std::unordered_map<std::string, std::string> _helpTexts;
    void initialiseHelpMap();
};

#endif