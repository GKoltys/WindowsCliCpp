#include <string>
#include "Exit.h"
#include "../WCLI/CliContext.h"

using namespace std;

void Exit::execute(CliContext& ctx, const vector<string>& args)
{
    ctx.changeExitState();
}

string Exit::getName() const
{
    return "exit";
}