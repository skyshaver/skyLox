#include "TokenType.h"
#include <string>
#include <vector>
#include <variant>
#include <map>

#pragma once

class Token;

using Literal = std::variant<std::monostate, std::string, double>;

const std::map <std::string, TokenType> keywordsMap {
    { "and", TokenType::AND },
    { "class", TokenType::CLASS },
    { "else", TokenType::ELSE },
    { "false", TokenType::FALSE },
    { "for", TokenType::FOR },
    { "fun", TokenType::FUN },
    { "if", TokenType::IF },
    { "nil", TokenType::NIL },
    { "or", TokenType::OR },
    { "print", TokenType::PRINT },
    { "return", TokenType::RETURN },
    { "super", TokenType::SUPER },
    { "this", TokenType::THIS },
    { "true", TokenType::TRUE },
    { "var", TokenType::VAR },
    { "while", TokenType::WHILE }

};



class Scanner {
public:
    Scanner(const std::string& source);

    std::vector<Token> scanTokens();
    std::vector<Token> tokens;
private:
    std::string source;
    size_t start {};
    size_t current {};
    size_t line {1};

    void scanToken();
    void addToken(TokenType type);
    void addToken(TokenType type, Literal literal);
    char advance();
    char peek();
    char peekNext();
    bool match(char expected);
    void number();
    void string();
    void identifier();
    bool isAtEnd() { return current >= source.length(); }
};