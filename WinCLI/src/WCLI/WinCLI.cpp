#include "WCLI.h"

int main()
{
    WCLI cmd = WCLI();

    // Use either to start the CLI

    //cmd.run();
    cmd.runWithConfigFile("C:/Users/gkoltys/Documents/siriusXM-Internship/c++Learning/github/WindowsCLIcpp/WinCLI/src/Config/config.json");
}
