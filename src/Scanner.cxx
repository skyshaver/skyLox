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
        case '\\':
            if(match('\\'))
            {
                while(peek() != '\n' && !isAtEnd())
                {
                    advance();
                }
            }
            else
            {
                addToken(TokenType::SLASH);
            }
        // ignore whitespace
        case ' ': 
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        case '"':
            string();
            break;
        default:
            if(std::isdigit(c))
            {
                number();
            }
            else if (std::isalpha(c) or c == '_')
            {
                identifier();
            }            
            else
            {
                SkyLox::error(line, "Unexpected Character");
            }
            break;
    }

}

void Scanner::addToken(TokenType type)
{
    addToken(type, Literal{});
}
void Scanner::addToken(TokenType type, Literal literal)
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

char Scanner::peek()
{
    if(isAtEnd()) return '\0';
    return source.at(current);
}

char Scanner::peekNext()
{
    if(current + 1 >= source.length()) return '\0';
    return source.at(current + 1);
}

void Scanner::number()
{
    while(std::isdigit(peek())) advance();

    if(peek() == '.' and std::isdigit(peekNext())){
        advance();
        while(std::isdigit(peek())) advance();
    }

    addToken(TokenType::NUMBER, std::stod(source.substr(start, current - start)));
}

void Scanner::string()
{
    while(peek() != '"' and !isAtEnd()) 
    {
        if(peek() == '\n') line++;
        advance();
    }

    if(isAtEnd())
    {
        SkyLox::error(line, "Unterminated String");
        return;
    }
    // closing "
    advance();
    // Trim the surround quotes
    std::string value = source.substr(start + 1, (current - 1) - start);
    addToken(TokenType::STRING, value);
}

void Scanner::identifier()
{
    while(std::isalnum(peek())) advance();
    std::string text = source.substr(start, current - start);
    auto it = keywordsMap.find(text);
    if(it == keywordsMap.end()) 
        addToken(TokenType::IDENTIFIER);
    else
        addToken(it->second); 

}