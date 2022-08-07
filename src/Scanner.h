#include <string>
#include <vector>

class Token;

class Scanner {
public:
    Scanner(const std::string& source);

    std::vector<Token> scanTokens();
};