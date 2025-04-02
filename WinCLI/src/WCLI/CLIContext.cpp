#include "CLIContext.h"
#include "Utils.h"

using namespace std;
using namespace Utils;

CliContext::CliContext() : 
    _currentDir(currentPath()),
    _dirStack(stack<string>()),
    _shouldExit(false) {}

CliContext::~CliContext() {}

void CliContext::changeDir(string newDir)
{
    if (Utils::verifyPath(newDir))
    {
        _currentDir = newDir;
    }
}

void CliContext::changeExitState()
{
    _shouldExit = !_shouldExit;
}

string CliContext::getCurrentDir() const
{
    return _currentDir;
}

stack<string> CliContext::getStack() const
{
    return _dirStack;
}


