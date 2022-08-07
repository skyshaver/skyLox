#include "SkyLox.h"
#include "fmt/format.h"

int main(int argc, const char** argv)
{
    SkyLox& skyLox = SkyLox::Instance();
    if(argc > 2)
    {
        fmt::print("Use [skyLox script]\n");
        return 1;
    }
    else if(argc == 2)
    {
        skyLox.runFile(argv[1]);
    }
    else
    {
        skyLox.runPrompt();
    }
    fmt::print("Thanks for playing!! \n");
}