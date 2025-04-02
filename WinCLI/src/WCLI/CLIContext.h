#ifndef CLICONTEXT_H
#define CLICONTEXT_H

#include <string>
#include <stack>

class CliContext
{
public:
    CliContext();
    ~CliContext();

    std::string getCurrentDir() const;
    std::stack<std::string> getStack() const;

protected:
    void changeDir(std::string newDir);
    void changeExitState();

private:
    std::string _currentDir;
    std::stack<std::string> _dirStack;
    bool _shouldExit;
};

#endif