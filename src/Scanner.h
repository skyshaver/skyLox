#include <string>
#include <vector>

class Token;

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

    bool isAtEnd() { return current >= source.length(); }
};