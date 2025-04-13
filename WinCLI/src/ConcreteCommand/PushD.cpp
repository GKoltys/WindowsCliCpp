#include <iostream>
#include <filesystem>
#include "../WCLI/Utils.h"
#include "../WCLI/CliContext.h"
#include "Pushd.h"
#include "Cd.h"

using namespace std;
using namespace filesystem;

Pushd::Pushd(Command* cdHelper) : _cdHelper(cdHelper) {}

void Pushd::execute(CliContext& ctx, const vector<string>& args)
{
    if (args.size() > 2)
    {
        cout << "Usage: pushd [path]" << endl << endl;
        return;
    }

    if (args.size() == 2)
    {
        path userPath = args[1];

        if (Utils::verifyPath(userPath))
        {
            ctx.cliStackPush(ctx.getCurrentDir());
            _cdHelper->execute(ctx, args);
        }
        else
        {
            cout << "Specified path is invalid" << endl;
        }
    }
    else
    {
        cout << endl;
    }
}