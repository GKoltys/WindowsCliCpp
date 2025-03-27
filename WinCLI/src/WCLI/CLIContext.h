#ifndef CLICONTEXT_H
#define CLICONTEXT_H

#include <string>
#include <stack>

class CLIContext
{
public:
    void changeDir(std::string newDir);

protected:
    std::string getCurrentDir() const;

private:
    std::string _currentDir;
    std::stack<std::string> _dirStack;
    bool _shouldExit;
};

#endif