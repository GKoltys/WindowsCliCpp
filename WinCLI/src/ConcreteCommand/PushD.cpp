#include <iostream>
#include <filesystem>
#include "../WCLI/Utils.h"
#include "Pushd.h"
#include "Cd.h"

using namespace std;
using namespace filesystem;

Pushd::Pushd(const vector<string>& args) : DirectoryCommand(args) {}

void Pushd::execute(CliContext& ctx)
{
    vector<string> args = getArgs();

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
            Cd cd(args);
            cd.execute(ctx);
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

string Pushd::getName() const
{
    return "push";
}