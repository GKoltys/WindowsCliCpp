#include <iostream>
#include <string>
#include <vector>
#include "Echo.h"

using namespace std;

Echo::Echo() {}

void Echo::execute(CliContext& ctx, const vector<string>& args)
{
    for (int i = 1; i < args.size(); i++)
    {
        cout << args[i] << " ";
    }
    cout << endl;
}

string Echo::getName() const
{
    return "echo";
}
