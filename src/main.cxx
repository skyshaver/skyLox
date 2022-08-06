#include "Scanner.h"
#include "Token.h"
#include "fmt/format.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

static bool hadError = false;

void runFile(const std::string& path)
{
    std::ifstream fin(path, std::ios_base::binary);
    // can also use this iterator approach straight to a std::string
    std::vector<char> buffer( std::istreambuf_iterator<char>{fin},
                          std::istreambuf_iterator<char>() );

    run(std::string(buffer.begin(), buffer.end()));
    if(hadError) std::exit(1);
}

void runPrompt()
{
    fmt::print("Welcome to the skyLox REPL\n");
    std::string line;
    for(;;)
    {
        fmt::print(">");
        std::getline(std::cin, line);
        if(line.empty())
        {
            break;
        } 
        else       
        {
            fmt::print("input: {}\n", line);
            run(line);
            hadError = false;
        }        
    }
}

void run(const std::string& source)
{
    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();
    for(auto e : tokens)
    {
        fmt::print("{}", e);
    }
}

void error(int line, const std::string& message)
{
    report(line, "", message);
}

void report(int line, const std::string& where, const std::string& message)
{
    fmt::print("[line: {}] Error:{}{}", line, where, message);
    hadError = true;
}

int main(int argc, const char** argv)
{
    if(argc > 2)
    {
        fmt::print("Use [skyLox script]\n");
        return 1;
    }
    else if(argc == 2)
    {
        runFile(argv[1]);
    }
    else
    {
        runPrompt();
    }
    fmt::print("Thanks for playing!! \n");
}