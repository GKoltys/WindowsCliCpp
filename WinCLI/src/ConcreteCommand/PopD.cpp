#include <iostream>
#include <filesystem>
#include "../WCLI/Utils.h"
#include "Popd.h"
#include "Cd.h"

using namespace std;
using namespace filesystem;

Popd::Popd(const vector<string>& args) : DirectoryCommand(args) {}

void Popd::execute(CliContext& ctx)
{
    vector<string> args = getArgs();

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

    args.push_back(ctx.getStack().top().string());
    Cd cd(args);
    cd.execute(ctx);

    ctx.cliStackPop();
}

string Popd::getName() const
{
    return "popd";
}