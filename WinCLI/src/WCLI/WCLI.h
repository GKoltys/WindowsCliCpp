#ifndef WCLI_H
#define WCLI_H

#include <string>

class CliContext;
class Config;
class CommandManager;

class WCLI
{
public:
    WCLI();
    ~WCLI();

    void applyConfig();
    void run();
    void runWithConfigFile(const std::string& path);

private:
    CliContext* _context;
    Config* _config;
    CommandManager* _cmdManager;
};

#endif