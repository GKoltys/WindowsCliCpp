#include "WCLI.h"

int main()
{
    WCLI cmd = WCLI();
     
    // Use either to start the CLI

    //cmd.run();
    cmd.runWithConfigFile("config.json");
}
