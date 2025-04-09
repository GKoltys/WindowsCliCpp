#include <string>
#include "Exit.h"
#include "../WCLI/CliContext.h"

using namespace std;

void Exit::execute(CliContext& ctx)
{
    ctx.changeExitState();
}

string Exit::getName() const
{
    return "exit";
}