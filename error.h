#pragma once

#include "base.h"

struct FPos{
    int line;
    int character;
};

class Error {
public:
    enum Severity {
        Warning,
        Breaking,
        Info,
        Nothing
    };

    Error(std::string message, Severity severity) : m(message), s(severity) {};
    Error(std::string message, Severity severity, FPos pos) : m(message), s(severity), p(pos) {};
    Error() : s(Severity::Nothing) {};
    
    inline bool is_error() { if (s == Severity::Nothing) { return false; } else { return true; } }
    inline std::string repr() { return m; };
private:
    std::string m;
    FPos p;
    Severity s;
};

/*

x: int = 0; y: str = "hello world";

define add: func(x, y) ->
    print x + y

define g: f(x) -> y
    x^2 + 4x + 4

d/dx g(x)

graph g(x), 0, 15

*/