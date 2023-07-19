#include "token.h"

#include <string>

std::tuple<Error, Token::Primitive> Utils::toprim(std::string s_value) {
    std::map<std::string, Token::Primitive> TokToPrim = {
        {"bool", Token::Primitive::Boolean},
        {"num", Token::Primitive::Numeral},
        {"string", Token::Primitive::String},
        {"arr", Token::Primitive::Array},
        {"func", Token::Primitive::Func},
        {"any", Token::Primitive::AnyType},
        {"none", Token::Primitive::NoneType},
    };

    if (TokToPrim.find(s_value) != TokToPrim.end()) {
        return std::tuple<Error, Token::Primitive>(Error(), TokToPrim[s_value]);
    }
    return std::tuple<Error, Token::Primitive>(Error("TypeError: Type " + s_value + " doesn't exist.", Error::Severity::Warning), Token::Primitive::AnyType);
}

Token::Primitive Token::isprim() {
    if (this->get_type() == Token::Type::string || this->get_type() == Token::Type::numeral) {
        return Primitive::Numeral;
    } else if (this->get_type() == Token::Type::keyword) {
        if (this->s_value == "true" || this->s_value == "false") {
            return Primitive::Boolean;
        } else if (this->s_value == "none") {
            return Primitive::NoneType;
        }
    }
    return Primitive::AnyType;
}

std::map<Token::Type, char> TOKENREPR = {
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
    {Token::Type::comma, '.'},
    {Token::Type::tilda, '~'},
    {Token::Type::question_mark, '?'},
    {Token::Type::pipe, '|'},
    {Token::Type::tab, '\t'},
    {Token::Type::carriage_return, '\n'},
};

std::string Token::repr()
{

    switch (type)
    {
    case Token::Type::string:
    case Token::Type::keyword:
        return s_value;
    case Token::Type::numeral:
        return std::to_string(i_value);
    default:
        return std::string(1, TOKENREPR[type]);
    }
}
