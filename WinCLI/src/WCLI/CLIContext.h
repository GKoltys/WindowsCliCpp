#ifndef CLICONTEXT_H
#define CLICONTEXT_H

#include <string>
#include <stack>
#include <filesystem>

class CliContext
{
public:
    CliContext();

    void changeDir(std::filesystem::path newDir);
    void changeExitState();
    void cliStackPush(std::filesystem::path pathIn);
    void cliStackPop();

    std::string getCurrentDirStr() const { return _currentDirStr; }
    std::filesystem::path getCurrentDir() const { return _currentDir; }
    std::stack<std::filesystem::path> getStack() const { return _dirStack; }
    bool getExitState() const { return _exitState; }

private:
    std::string _currentDirStr;
    std::filesystem::path _currentDir;
    std::stack<std::filesystem::path> _dirStack;
    bool _exitState;
};

#endif