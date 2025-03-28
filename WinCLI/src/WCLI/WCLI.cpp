#include <iostream>
#include <string>
#include "WCLI.h"

using namespace std;

WCLI::WCLI() : _context(CLIContext()), _logger(Logger())
{
   //_config = Config();
}

void WCLI::run()
{
    while (true)
    {
        string cmdIn;

        cout << _context.getCurrentDir() << ">";
        cin >> cmdIn;

        cout << cmdIn << endl;
    }
}

void WCLI::executeCommand()
{
}
