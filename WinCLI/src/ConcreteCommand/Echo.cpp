#include <iostream>
#include <string>
#include <vector>
#include "Echo.h"

using namespace std;

Echo::Echo(const vector<string>& args) :
    OutputCommand(args)
{}

void Echo::execute(CliContext& ctx)
{
    for (int i = 1; i < getArgs().size(); i++)
    {
        cout << getArgs()[i] << " ";
    }
    cout << endl;
}

string Echo::getName() const
{
    return "echo";
}
