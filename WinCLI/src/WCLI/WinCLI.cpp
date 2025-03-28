#include "WCLI.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    WCLI cmd = WCLI();
    cmd.run();
}
