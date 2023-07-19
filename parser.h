#pragma once

#include "lexer.h"

class Variable {
public:
    Variable();
    std::string name;
    bool isTypeSafe;
    Token::Primitive prim;
    Token* tok;

    int i_val;
    bool b_val;
    std::string s_value;  
};

class AST { // Abstract Syntax Tree
public:
    enum Type {
        Function,
        ControlFlow,
        Operation,
        Tok,
    };

    AST();
    AST(AST* parent) : parent(parent) {  };

    inline void add(AST o) { tree.push_back(o); };
    inline AST* getParent() {return parent; };
    inline Type getType() { return type; }

    Type type;
    std::string repr();

    std::vector<std::tuple<Variable*, std::string>> scope;

private:
    std::vector<AST> tree;
    AST *parent;
    Token *tok;
};

class Parser {
public:
    Parser(Lexer lex);

    inline AST get_ast() { return main; };
private:
    enum Build {
        variable,
    };

    void build(Build build);

    bool is_legal(std::string name);

    std::vector<Token> tokens;
    int pos;
    Token* current_token;
    AST main;
    AST *workingtree;

    std::vector<std::string> types{"num", "string", "bool", "func", "arr", "none"};

    std::vector<std::string> keywords{"print", "input", "define", "while", "for", "if", "else", "elif", "class", "not", "or", "and", "var"};

    std::vector<std::string> savedwords { "print", "input", "define", "while", "for", "if", "else", "elif", "class", "not", "or", "and", "num", "string", "bool", "func", "arr", "none", "true", "false" };

    std::vector<Error> errors;
};