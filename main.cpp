#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.h"

int main() {
    Lexer lexer = Lexer("Lenovo IdeaPad Gaming 3i Laptop, 15.6 Full HD Display");

    for (auto &element : lexer.getTokens())
    {
        std::cout << element.repr() << std::endl;
    }

    std::cout << "Size of tokens: " << lexer.getTokens().size() << std::endl;

    return 0;
}