#pragma once

#include "TokenType.h"
#include <string>
#include <variant>
#include <any>

using Literal = std::variant<std::monostate, std::string, double>;

class Token {
public:
    Token();
    Token(TokenType type, std::string lexeme, Literal literal, size_t line);

    std::string toString();


    const TokenType type;
    const std::string lexeme;
    Literal literal;
    const size_t line;


};