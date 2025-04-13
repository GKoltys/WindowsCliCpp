#ifndef WCLI_H
#define WCLI_H

#include <string>
#include "CliContext.h"
#include "Config.h"
#include "CommandManager.h"

class WCLI
{
public:
    WCLI();
    void applyConfig();
    void run();
    void runWithConfigFile(const std::string& path);

private:
    CliContext _context;
    Config _config;
    CommandManager _cmdManager;
};

#endif