#include "Cls.h"

using namespace std;

void Cls::execute(CliContext& ctx, const std::vector<std::string>& args)
{
    // Reference: https://stackoverflow.com/questions/74446197/c-how-does-if-systemcls-systemclear-work#:~:text=cls%20and%20clear%20are%20terminal,a%20command%20was%20completed%20successfully.
    // ANSI escape code
    printf(
        "\033[2J"      // clear the screen
        "\033[1;1H");  // move cursor home
}