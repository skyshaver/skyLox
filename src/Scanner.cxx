#include "Scanner.h"
#include "Token.h"
#include "SkyLox.h"

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
        case '(' : 
            addToken(TokenType::LEFT_PAREN);
            break;
        case ')' : 
            addToken(TokenType::RIGHT_PAREN);
            break;
        case '{' : 
            addToken(TokenType::LEFT_BRACE);
            break;
        case '}' : 
            addToken(TokenType::RIGHT_BRACE);
            break;
        case ',' : 
            addToken(TokenType::COMMA);
            break;
        case '.' : 
            addToken(TokenType::DOT);
            break;
        case '-' : 
            addToken(TokenType::MINUS);
            break;
        case '+' : 
            addToken(TokenType::PLUS);
            break;
        case ';' : 
            addToken(TokenType::SEMICOLON);
            break;
        case '*' : 
            addToken(TokenType::STAR);
            break;
        case '!':
            addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '=':
            addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '<':
            addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>':
            addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;
        default:
            SkyLox::error(line, "Unexpected Character");
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
    return source.at(current++);
}