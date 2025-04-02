#ifndef CLICONTEXT_H
#define CLICONTEXT_H

#include <string>
#include <stack>

class CliContext
{
public:
    CliContext();
    ~CliContext();

    void changeDir(std::string newDir);
    void changeExitState();

    std::string getCurrentDir() const;
    std::stack<std::string> getStack() const;
    bool getExitState() const;

private:
    std::string _currentDir;
    std::stack<std::string> _dirStack;
    bool _exitState;
};

#endif