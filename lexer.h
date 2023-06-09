#pragma once
#include <vector>
#include <string>
#include <map>

class Token {
public:
    enum Type {
        keyword,
        string,
        numeral,
        scientific,
        newline,
        tab,
        left_square_bracket,
        right_square_bracket,
        comma,
        colon,
        plus,
        minus,
        multiply,
        divide,
        equal,
        less_than,
        greater_than,
        hashtag,
        percent,
        caret,
        underscore,
        left_brace,
        right_brace,
        period,
        tilda,
        question_mark,
        pipe,
        carriage_return,
    };

    Token(Type type) : type(type) {}
    Token(Type type, const std::string str) : type(type), s_value(str) {}
    Token(Type type, int v) : type(type), i_value(v) {}
    Token(Type type, bool v) : type(type), b_value(v) {}

    inline Type get_type() { return type; };
    std::string s_value;
    int i_value;
    bool b_value;

    std::string repr();
private:
    Type type;
};

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