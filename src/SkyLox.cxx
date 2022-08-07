#include "SkyLox.h"
#include "fmt/format.h"
#include <iostream>

void SkyLox::runFile(const std::string& path)
{
    std::ifstream fin(path, std::ios_base::binary);
    // can also use this iterator approach straight to a std::string
    std::vector<char> buffer( std::istreambuf_iterator<char>{fin},
                          std::istreambuf_iterator<char>() );

    run(std::string(buffer.begin(), buffer.end()));
    if(hadError) std::exit(1);
}

void SkyLox::runPrompt()
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

void SkyLox::run(const std::string& source)
{
    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();
    // for(auto e : tokens)
    // {
    //     // fmt::print("{}", e);
    // }
}

void SkyLox::error(int line, const std::string& message)
{
    report(line, "", message);
}

void SkyLox::report(int line, const std::string& where, const std::string& message)
{
    fmt::print("[line: {}] Error:{}{}", line, where, message);
    hadError = true;
}