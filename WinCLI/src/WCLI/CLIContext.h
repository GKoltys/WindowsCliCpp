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
    void cliStackPush(std::filesystem::path pathIn);
    void cliStackPop();

    std::string getCurrentDirStr() const { return _currentDirStr; };
    std::filesystem::path getCurrentDir() const;
    std::stack<std::filesystem::path> getStack() const;
    bool getExitState() const;

private:
    std::string _currentDirStr;
    std::filesystem::path _currentDir;
    std::stack<std::filesystem::path> _dirStack;
    bool _exitState;
};

#endif