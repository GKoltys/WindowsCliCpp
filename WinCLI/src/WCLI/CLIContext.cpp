#include "CLIContext.h"
#include "Utils.h"

using namespace std;
using namespace Utils;

CLIContext::CLIContext() : 
    _currentDir(currentPath()),
    _dirStack(stack<string>()),
    _shouldExit(false) {}

CLIContext::~CLIContext() {}

void CLIContext::changeDir(string newDir)
{
    if (Utils::verifyPath(newDir))
    {
        _currentDir = newDir;
    }
}

void CLIContext::changeExitState()
{
    _shouldExit = !_shouldExit;
}

string CLIContext::getCurrentDir() const
{
    return _currentDir;
}

stack<string> CLIContext::getStack() const
{
    return _dirStack;
}


