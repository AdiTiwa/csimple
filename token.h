#include "error.h"

class Utils {
public: 
    static std::tuple<Error, Token::Primitive> toprim(std::string s_value);
    static std::tuple<Error, Token::Primitive> toprim(std::string s_value, bool questionmark); // TODO: FIND A FUCKING NAME FOR THIS VARIABLE IM SO TIRED HELP ME GOD
};

class Token {
public:
    enum Type
    {
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
        left_parenthesis,
        right_parenthesis,
        period,
        tilda,
        question_mark,
        pipe,
        carriage_return,
    };

    enum Primitive
    {
        Numeral,
        String,
        Boolean,
        Func,
        Array,
        AnyType,
        NoneType,
    };

    Primitive isprim();

    std::vector<Type> primtypes{Type::numeral, Type::string};

    Token(Type type) : type(type) {}
    Token(Type type, const std::string str) : type(type), s_value(str) {}
    Token(Type type, int v) : type(type), i_value(v) {}
    Token(Type type, bool v) : type(type), b_value(v) {}

    inline Type get_type() { return type; };
    std::string s_value;
    int i_value;
    bool b_value;

    std::string repr();

    inline Token get() { return *this; };

private:
    Type type;
};

