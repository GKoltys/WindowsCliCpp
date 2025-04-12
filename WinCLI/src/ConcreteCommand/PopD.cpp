#include <iostream>
#include <filesystem>
#include "Popd.h"
#include "../WCLI/CliContext.h"
#include "Cd.h"

using namespace std;
using namespace filesystem;

Popd::Popd(Cd* cdHelper) : _cdHelper(cdHelper) {}

void Popd::execute(CliContext& ctx, const vector<string>& args)
{
    if (args.size() > 1)
    {
        cout << "Usage: popd" << endl << endl;
        return;
    }

    if (ctx.getStack().size() == 0)
    {
        cout << endl;
        return;
    }

    vector<string> prevDir = { args[0], (ctx.getStack().top().string())};
    _cdHelper->execute(ctx, args);

    ctx.cliStackPop();
}

string Popd::getName() const
{
    return "popd";
}