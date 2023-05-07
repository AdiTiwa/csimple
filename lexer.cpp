#include "lexer.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

bool isspace(char c) {
    switch (c) {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            return true;
        default:
            return false;
    }
}

bool isidentifier(char c) {
    switch (c) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '_':
            return true;
        default:
            return false;
    }
}

bool isnumeric(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;

    }
}

Token Lexer::buildNumeral(Token currentToken) {
    idx++;
    if (idx >= code.length()) {
        return currentToken;
    }
    char l = code[idx];

    if (isnumeric(l)) {
        return buildNumeral(Token(currentToken.get_type(), std::stoi(std::to_string(currentToken.i_value) + l)));
    }
    return currentToken;
}

Token Lexer::buildKeyword(Token currentToken) {
    idx++;
    if (idx >= code.length())
    {
        return currentToken;
    }
    char l = code[idx];

    if (isidentifier(l)) {
        return buildKeyword(Token(currentToken.get_type(), currentToken.s_value + l));
    }
    return currentToken;
}

Token Lexer::buildString(Token currentToken) {
    idx++;
    if (idx >= code.length())
    {
        return currentToken;
    } 
    char l = code[idx];

    if (l != '"') {
        return buildString(Token(currentToken.get_type(), currentToken.s_value + l));
    }
    return currentToken;
}

Lexer::Lexer(const std::string code)
    : code(code)
{
    idx = -1;

    while (true) {
        idx++;
        if (idx >= code.length()) {
            break;
        }
        char l = code[idx];

        if (isnumeric(l)) {
            tokens.push_back(buildNumeral(Token(Token::Type::numeral, l - '0')));
        } else if (isidentifier(l)) {
            tokens.push_back(buildKeyword(Token(Token::Type::keyword, std::string(1, l))));
        } else if (l == '"') {
            tokens.push_back(buildKeyword(Token(Token::Type::string, std::string(1, l))));
        }

    }
}

std::string Token::repr() {
    switch (type) {
        case Token::Type::string:
        case Token::Type::keyword:
            return s_value;
        case Token::Type::numeral:
            return std::to_string(i_value);
        default:
            return "bro how did you get here??? *skull emoji*";
    }
}