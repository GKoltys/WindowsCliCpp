#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <unordered_map>
#include <string>
#include <vector>

class Command;
class CliContext;

class CommandManager
{
public:
    CommandManager();
    ~CommandManager();

    void executeCommand(CliContext* ctx, const std::vector<std::string>& args);

private:
    std::unordered_map<std::string, Command*> _commands;
};

#endif
