#ifndef WCLI_H
#define WCLI_H

#include "CLIContext.h"
#include "Logger.h"
#include "Config.h"
#include "CommandInput.h"

class WCLI
{
public:
    WCLI();
    void run();
    void executeCommand(const CommandInput& input);

private:
    CliContext _context;
    Logger _logger;
    Config _config;
};

#endif