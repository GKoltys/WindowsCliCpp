#include <iostream>
#include <filesystem>
#include "Cd.h"
#include "../WCLI/CliContext.h"
#include "../WCLI/Utils.h"

using namespace std;
using namespace filesystem;

Cd::Cd(const vector<string>& args) : DirectoryCommand(args) {}

void Cd::execute(CliContext& ctx)
{
    const vector<string>& args = getArgs();

    if (args.size() > 2)
    {
        cout << "Usage: cd [path]" << endl << endl;
        return;
    }

    if (args.size() == 2)
    {
        path userPath = args[1];

        if (userPath == ".")
        {
            cout << endl;
            return;
        }
        
        if (userPath == "..")
        {
            const path current = ctx.getCurrentDir();
            const path parent = current.parent_path();

            if (!parent.empty())
            {
                ctx.changeDir(parent);
                cout << endl;
            }
            else
            {
                cout << "Already at the root directory." << endl << endl;
            }
            return;
        }

        path target = ctx.getCurrentDir() / userPath;
        if (Utils::verifyPath(target))
        {
            ctx.changeDir(target);
            cout << endl;
        }
        else
        {
            cout << "The system cannot find the path specified" << endl << endl;
        }
    }
    else
    {
        cout << ctx.getCurrentDirStr() << endl << endl;
    }
}

string Cd::getName() const
{
    return "cd";
}