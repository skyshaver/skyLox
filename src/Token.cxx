#include "Token.h"
#include "fmt/format.h"
#include "../include/magic_enum.hpp"

Token::Token() : type(TokenType::TT_EOF), line(0) 
{
    
}

Token::Token(TokenType type, std::string lexeme, Literal literal, size_t line)
: type(type), lexeme(lexeme), literal(literal), line(line)
{

}

std::string Token::toString()
{
    return fmt::format("Tyep: {} Lexeme: {} Literal: {} Line: {}", magic_enum::enum_name(type), lexeme, "", line);
}