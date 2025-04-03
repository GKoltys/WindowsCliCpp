#include <iostream>
#include <filesystem>
#include "Dir.h"
#include "../WCLI/Utils.h"

using namespace std;
namespace fs = std::filesystem;

Dir::Dir(const vector<string>& args) : DirectoryCommand(args) {}

void Dir::execute(CliContext& ctx)
{
    vector<string> args = getArgs();

    if (args.size() > 2)
    {
        cout << "Usage: dir [path]\n" << endl;
        return;
    }
    if (args.size() == 2)
    {
        if (Utils::verifyPath(args[1]))
        {
            cout << "\nDirectory of " << args[1] << "\n" << endl;
            for (const auto& entry : fs::directory_iterator(args[1]))
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
        for (const auto& entry : fs::directory_iterator(currentDir))
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