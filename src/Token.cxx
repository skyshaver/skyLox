#include "Token.h"

Token::Token() : type(TokenType::TT_EOF), line(0) 
{
    
}

Token::Token(TokenType type, std::string lexeme, std::any literal, int line)
: type(type), lexeme(lexeme), literal(literal), line(line)
{

}