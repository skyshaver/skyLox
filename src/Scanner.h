#include <string>
#include <vector>
#include <variant>

#pragma once

class Token;
enum class TokenType;
using Literal = std::variant<std::string, double>;

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
    bool match(char expected);
    bool isAtEnd() { return current >= source.length(); }
};