#include "Scanner.h"
#include "Token.h"

Scanner::Scanner(const std::string& source) : source(source)
{
    
}

std::vector<Token> Scanner::scanTokens()
{    
    while(!isAtEnd())
    {

    }
    tokens.push_back({TokenType::TT_EOF, "", nullptr, line});
    return tokens;
}