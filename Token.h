#pragma once
#include <vector>
#include <string>

class Token
{
public:
	void repr();
	void set();
	void get();
};

class Number : Token {
private:
	int value;
};

class String : Token {
private:
	std::vector<char> value;
};

class Boolean : Token {
private:
	bool value;
};

class KeyWord : Token {
private:
	std::string value;
};

class Tree : Token {
public:
	std::vector<Token> tree;
};
