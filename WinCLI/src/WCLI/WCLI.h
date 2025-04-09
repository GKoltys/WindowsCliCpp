#ifndef WCLI_H
#define WCLI_H

#include <string>
#include "CliContext.h"
#include "Config.h"
#include "Logger.h"

class CommandInput;

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