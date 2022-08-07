#pragma once

#include "TokenType.h"
#include <string>
#include <any>


class Token {
public:
    Token();
    Token(TokenType type, std::string lexeme, std::any literal, size_t line);

    std::string toString();


    const TokenType type;
    const std::string lexeme;
    std::any literal;
    const size_t line;


};