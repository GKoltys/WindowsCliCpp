#ifndef WCLI_H
#define WCLI_H

#include <string>
#include "CLIContext.h"
#include "Logger.h"
#include "Config.h"
#include "CommandInput.h"

class WCLI
{
public:
    WCLI();
    void applyConfig();
    void run();
    void run(const std::string& path);
    void executeCommand(const CommandInput& input);

private:
    CliContext _context;
    Logger _logger;
    Config _config;
};

#endif