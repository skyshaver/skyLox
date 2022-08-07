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

void Scanner::scanToken()
{
    char c = advance();
    switch(c)
    {
        case '(' : addToken(TokenType::LEFT_PAREN);
            break;
        case ')' : addToken(TokenType::RIGHT_PAREN);
            break;
        case '{' : addToken(TokenType::LEFT_BRACE);
            break;
        case '}' : addToken(TokenType::RIGHT_BRACE);
            break;
    }

}

void Scanner::addToken(TokenType type)
{
    addToken(type, nullptr);
}
void Scanner::addToken(TokenType type, std::any literal)
{
    std::string text = source.substr(start, current - start);
    tokens.push_back({type, text, literal, line});
}

bool Scanner::match(char expected)
{
    if(isAtEnd()) return false;
    if(source.at(current) != expected) return false;

    current++;
    return true;
}

char Scanner::advance() 
{
    return 'a';
}