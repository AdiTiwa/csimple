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
        OhWhatTheHell,
    };

    Error(std::string message, Severity severity) : m(message), s(severity) {};
    Error(std::string message, Severity severity, FPos pos) : m(message), s(severity), p(pos) {};
private:
    std::string m;
    FPos p;
    Severity s;
};