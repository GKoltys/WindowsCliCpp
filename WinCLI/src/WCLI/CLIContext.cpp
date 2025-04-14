#include <filesystem>
#include "CLIContext.h"
#include "Utils.h"

using namespace std;
using namespace filesystem;

CliContext::CliContext() : 
    _currentDirStr(Utils::currentPath().string()),
    _currentDir(Utils::currentPath()),
    _dirStack(stack<path>()),
    _exitState(false) {}

void CliContext::changeDir(path newDir)
{
    if (Utils::verifyPath(newDir))
    {
        _currentDir = newDir;
        _currentDirStr = newDir.string();
    }
}

void CliContext::changeExitState()
{
    _exitState = !_exitState;
}

void CliContext::cliStackPush(path pathIn)
{
    _dirStack.push(pathIn);
}

void CliContext::cliStackPop()
{
    _dirStack.pop();
}
