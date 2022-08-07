#include "TokenType.h"
#include <string>
#include <any>

class Token {
public:
    Token();
    Token(TokenType type, std::string lexeme, std::any literal, int line);
    const TokenType type;
    const std::string lexeme;
    std::any literal;
    const int line;


};