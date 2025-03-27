#ifndef WCLI_H
#define WCLI_H

#include "CLIContext.h"
#include "Logger.h"
#include "Config.h"

class WCLI
{
public:
    WCLI();
    void run();
    void executeCommand();

private:
    CLIContext _context;
    Logger _logger;
    Config _config;
};

#endif