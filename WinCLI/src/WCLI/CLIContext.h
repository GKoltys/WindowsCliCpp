#ifndef CLICONTEXT_H
#define CLICONTEXT_H

#include <string>
#include <stack>
#include <filesystem>

class CliContext
{
public:
    CliContext();
    ~CliContext();

    void changeDir(std::filesystem::path newDir);
    void changeExitState();

    std::string getCurrentDirStr() const;
    std::filesystem::path getCurrentDir() const;
    std::stack<std::string> getStack() const;
    bool getExitState() const;

private:
    std::string _currentDirStr;
    std::filesystem::path _currentDir;
    std::stack<std::string> _dirStack;
    bool _exitState;
};

#endif