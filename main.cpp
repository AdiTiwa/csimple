#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "lexer.h"

int main() {
    Lexer lexer = Lexer("9:\nhello world");

    for (auto &element : lexer.getTokens())
    {
        std::cout << element.repr() << std::endl;
    }

    std::cout << "Size of tokens: " << lexer.getTokens().size() << std::endl;

    return 0;
}