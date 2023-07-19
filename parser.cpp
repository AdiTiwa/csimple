#include "parser.h"

bool in_vector(std::vector<std::string> vec, std::string key) {
    return std::count(vec.begin(), vec.end(), key);
}

AST::AST() : tok(nullptr) {
    tree = std::vector<AST>(0);
}

std::string AST::repr() {
    if (tok != nullptr) {
        return tok->repr();
    }

    for (auto& element : tree) {
        return element.repr();
    }
}

bool Parser::is_legal(std::string name) {
    if (std::count(savedwords.begin(), savedwords.end(), name)) {
        return false;
    } else {
        return true;
    }
}

void Parser::build(Build build) {
    switch (build) {

    }
}

Parser::Parser(Lexer lex) {
    tokens = lex.getTokens();
    pos = 0;
    main = AST();
    workingtree = &main;

    while (pos < tokens.size()) {
        current_token = &tokens[pos];
        

        if (current_token->get_type() == Token::Type::keyword) {
            // *- keyword case -*
            
            if (current_token->s_value == "define") {
                AST ntree = AST();
            } else if (current_token->s_value == "var") {
                
            }
        } else if (current_token->get_type() == Token::Type::left_parenthesis) {
            /*
            
            *- function case -*
            `
            ([parameters]) =>
                [indented block]
            `

            */
            
            
        }
    }
}