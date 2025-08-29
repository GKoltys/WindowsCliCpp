#include "WCLI.h"

int main()
{
    WCLI cmd = WCLI();

    cmd.runWithConfigFile("config.json");
}
