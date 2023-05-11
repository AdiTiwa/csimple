#pragma once

#include <string>

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
    };

    Error(std::string message, Severity severity) : m(message), s(severity) {};
    Error(std::string message, Severity severity, FPos pos) : m(message), s(severity), p(pos) {};

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