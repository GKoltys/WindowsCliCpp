#include <filesystem>
#include "CLIContext.h"
#include "Utils.h"
#include "Logger.h"

using namespace std;
using namespace filesystem;

CliContext::CliContext() : 
    _currentDirStr(Utils::currentPath().string()),
    _currentDir(Utils::currentPath()),
    _dirStack(stack<path>()),
    _exitState(false) {}

void CliContext::changeDir(path newDir)
{
    Logger::log("Current Directory changed to: " + newDir.string(), "DEBUG");

    if (Utils::verifyPath(newDir))
    {
        _currentDir = newDir;
        _currentDirStr = newDir.string();
    }
}

void CliContext::changeExitState()
{
    Logger::log("Exit state changed", "DEBUG");

    _exitState = !_exitState;
}

void CliContext::cliStackPush(path pathIn)
{
    Logger::log("'" + pathIn.string() + "' pushed to stack", "DEBUG");

    _dirStack.push(pathIn);
}

void CliContext::cliStackPop()
{
    Logger::log("'" + getStack().top().string() + "' popped from stack", "DEBUG");

    _dirStack.pop();
}
