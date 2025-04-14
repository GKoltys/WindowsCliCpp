#include <iostream>
#include "Echo.h"

using namespace std;

void Echo::execute(CliContext* ctx, const vector<string>& args)
{
    for (int i = 1; i < args.size(); i++)
    {
        cout << args[i] << " ";
    }
    cout << endl;
}