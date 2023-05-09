#include "lexer.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <hashtable.h>

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
    l = code[idx];

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
    l = code[idx];

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
    l = code[idx];

    if (l != '"') {
        return buildString(Token(currentToken.get_type(), currentToken.s_value + l));
    }
    return currentToken;
}

void Lexer::other_token() {
    switch (l) {
        case '\n':
            tokens.push_back(Token(Token::Type::newline));
            break;
        case '[':
            tokens.push_back(Token(Token::Type::left_square_bracket));
            break;
        case ']':
            tokens.push_back(Token(Token::Type::right_square_bracket));
            break;
        case ',':
            tokens.push_back(Token(Token::Type::comma));
            break;
        case ':':
            tokens.push_back(Token(Token::Type::colon));
            break;
        case '+':
            tokens.push_back(Token(Token::Type::plus));
            break;
        case '-':
            tokens.push_back(Token(Token::Type::minus));
            break;
        case '*':
            tokens.push_back(Token(Token::Type::multiply));
            break;
        case '/':
            tokens.push_back(Token(Token::Type::divide));
            break;
        case '=':
            tokens.push_back(Token(Token::Type::equal));
    }
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
        l = code[idx];

        if (isnumeric(l)) {
            tokens.push_back(buildNumeral(Token(Token::Type::numeral, l - '0')));
        } else if (isidentifier(l)) {
            tokens.push_back(buildKeyword(Token(Token::Type::keyword, std::string(1, l))));
        } else if (l == '"') {
            tokens.push_back(buildKeyword(Token(Token::Type::string, std::string(1, l))));
        }

        this->other_token();
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
            return std::to_string(this->type);
    }
}

/*


define print: func (todisplay: str):
    print todiplay

define nor: op (a, b):
    a or b = c
    not c

define g: f(x, y): x^2 + 4x + y^2 + 6y + 13

d/dx (g)

*/