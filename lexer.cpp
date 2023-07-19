#include "lexer.h"


std::map<char, Token::Type> TokenMap = {
    {'\n', Token::Type::newline},
    {'[', Token::Type::left_square_bracket},
    {']', Token::Type::right_square_bracket},
    {',', Token::Type::comma},
    {':', Token::Type::colon},
    {'+', Token::Type::plus},
    {'-', Token::Type::minus},
    {'*', Token::Type::multiply},
    {'/', Token::Type::divide},
    {'=', Token::Type::equal},
    {'<', Token::Type::less_than},
    {'>', Token::Type::greater_than},
    {'#', Token::Type::hashtag},
    {'%', Token::Type::percent},
    {'^', Token::Type::caret},
    {'_', Token::Type::underscore},
    {'(', Token::Type::left_parenthesis},
    {')', Token::Type::right_parenthesis},
    {'.', Token::Type::period},
    {'~', Token::Type::tilda},
    {'?', Token::Type::question_mark},
    {'|', Token::Type::pipe},
    {'\t', Token::Type::tab},
    {'\n', Token::Type::carriage_return},
};

std::map<Token::Type, char> TokenRepr = {
    {Token::Type::newline, '\n'},
    {Token::Type::left_square_bracket, '['},
    {Token::Type::right_square_bracket, ']'},
    {Token::Type::comma, ','},
    {Token::Type::colon, ':'},
    {Token::Type::plus, '+'},
    {Token::Type::minus, '-'},
    {Token::Type::multiply, '*'},
    {Token::Type::divide, '/'},
    {Token::Type::equal, '='},
    {Token::Type::less_than, '<'},
    {Token::Type::greater_than, '>'},
    {Token::Type::hashtag, '#'},
    {Token::Type::percent, '%'},
    {Token::Type::caret, '^'},
    {Token::Type::underscore, '_'},
    {Token::Type::left_parenthesis, '('},
    {Token::Type::right_parenthesis, ')'},
    {Token::Type::period, '.'},
    {Token::Type::tilda, '~'},
    {Token::Type::question_mark, '?'},
    {Token::Type::pipe, '|'},
    {Token::Type::tab, '\t'},
    {Token::Type::carriage_return, '\n'},
};

bool isspace(char c) {
    switch (c)
    {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
        return true;
    default:
        return false;
    };
}

bool isidentifier(char c) {
    switch (c)
    {
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
    };
}

bool isnumeric(char c) {
    switch (c)
    {
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
    };
}

Token Lexer::buildNumeral(Token currentToken)
{
    idx++;
    if (idx >= code.length())
    {
        return currentToken;
    }
    l = code[idx];

    if (isnumeric(l))
    {
        return buildNumeral(Token(currentToken.get_type(), std::stoi(std::to_string(currentToken.i_value) + l)));
    }
    return currentToken;
}

Token Lexer::buildKeyword(Token currentToken)
{
    idx++;
    if (idx >= code.length())
    {
        return currentToken;
    }
    l = code[idx];

    if (isidentifier(l))
    {
        return buildKeyword(Token(currentToken.get_type(), currentToken.s_value + l));
    }
    return currentToken;
}

Token Lexer::buildString(Token currentToken)
{
    idx++;
    if (idx >= code.length())
    {
        return currentToken;
    }
    l = code[idx];

    if (l != '"')
    {
        return buildString(Token(currentToken.get_type(), currentToken.s_value + l));
    }
    return currentToken;
}

void Lexer::other_token()
{
    if (TokenMap.find(l) != TokenMap.end())
    {
        tokens.push_back(Token(TokenMap[l]));
    }
}

Lexer::Lexer(const std::string code)
    : code(code)
{
    idx = -1;

    while (true)
    {
        idx++;
        if (idx >= code.length())
        {
            break;
        }
        l = code[idx];

        if (isnumeric(l))
        {
            tokens.push_back(buildNumeral(Token(Token::Type::numeral, l - '0')));
        }
        else if (isidentifier(l))
        {
            tokens.push_back(buildKeyword(Token(Token::Type::keyword, std::string(1, l))));
        }
        else if (l == '"')
        {
            tokens.push_back(buildKeyword(Token(Token::Type::string, std::string(1, l))));
        }

        this->other_token();
    }
}