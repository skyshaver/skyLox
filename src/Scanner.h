#include <string>

class Token;

class Scanner {
public:
    Scanner(const std::string& source);

    std::vector<Token> scanTokens();
};