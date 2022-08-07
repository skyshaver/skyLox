#include "Scanner.h"
#include "Token.h"
#include <string>
#include <fstream>
#include <vector>

#pragma once

class SkyLox {
    
public:
    static SkyLox& Instance(){
        static SkyLox s;
        return s;
    }

    void runFile(const std::string& path);
    void runPrompt();
    void run(const std::string& source);
    static void error(int line, const std::string& message);
    static void report(int line, const std::string& where, const std::string& message);
    inline static bool hadError = false;

    SkyLox(const SkyLox&) = delete;
    SkyLox& operator = (const SkyLox&) = delete;

private:
    SkyLox() = default;

};


