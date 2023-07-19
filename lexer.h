#pragma once

#include "token.h"

class Lexer {
public: 
    Lexer(const std::string code);
    Token buildNumeral(Token currentToken);
    Token buildString(Token currentToken);
    Token buildKeyword(Token currentToken);

    void other_token();

    inline std::vector<Token> getTokens() {return tokens;};
private:
    int idx;
    char l;
    std::vector<Token> tokens;
    const std::string code;
}; 