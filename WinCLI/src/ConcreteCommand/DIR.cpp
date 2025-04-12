#include <iostream>
#include <filesystem>
#include "Dir.h"
#include "../WCLI/CliContext.h"
#include "../WCLI/Utils.h"

using namespace std;
using namespace filesystem;

void Dir::execute(CliContext& ctx, const vector<string>& args)
{
    if (args.size() > 2)
    {
        cout << "Usage: dir [path]\n" << endl;
        return;
    }
    if (args.size() == 2)
    {
        path userPath = args[1];

        if (Utils::verifyPath(userPath))
        {
            cout << "\nDirectory of " << userPath << "\n" << endl;
            for (const auto& entry : directory_iterator(userPath))
            {
                cout << "\t" << entry.path().filename().string() << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "Specified path is invalid" << endl;
        }
    }
    else
    {
        string currentDir = ctx.getCurrentDirStr();
        cout << "\nDirectory of " << currentDir << "\n" << endl;
        for (const auto& entry : directory_iterator(currentDir))
        {
            cout << "\t" << entry.path().filename().string() << endl;
        }
        cout << endl;
    }
}

string Dir::getName() const
{
    return "dir";
}