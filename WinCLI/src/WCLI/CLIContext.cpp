#include "CLIContext.h"
#include "Utils.h"
#include <iostream>

using namespace std;
using namespace Utils;

CliContext::CliContext() : 
    _currentDir(currentPath()),
    _dirStack(stack<string>()),
    _exitState(false) {}

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
    _exitState = !_exitState;
}

bool CliContext::getExitState() const
{
    return _exitState;
}

string CliContext::getCurrentDir() const
{
    return _currentDir;
}

stack<string> CliContext::getStack() const
{
    return _dirStack;
}


