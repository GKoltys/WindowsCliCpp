#include <iostream>
#include <string>
#include <vector>
#include "Echo.h"

using namespace std;

Echo::Echo(const std::vector<std::string>& args) :
    OutputCommand(args)
{}

void Echo::execute(CLIContext& ctx)
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
