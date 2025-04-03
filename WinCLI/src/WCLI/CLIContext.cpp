#include <filesystem>
#include "CLIContext.h"
#include "Utils.h"

using namespace std;
using namespace Utils;
using namespace filesystem;

CliContext::CliContext() : 
    _currentDirStr(currentPath().string()),
    _currentDir(currentPath()),
    _dirStack(stack<string>()),
    _exitState(false) {}

CliContext::~CliContext() {}

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

bool CliContext::getExitState() const
{
    return _exitState;
}

string CliContext::getCurrentDirStr() const
{
    return _currentDirStr;
}

std::filesystem::path CliContext::getCurrentDir() const
{
    return _currentDir;
}

stack<string> CliContext::getStack() const
{
    return _dirStack;
}


