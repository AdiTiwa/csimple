import re

class token:
    def __init__(self, value):
        self.value = value

    def __repr__(self):
        return self
    
    def get(self):
        return self.value

class numeral(token):
    def __init__(self, value):
        super().__init__(value)

class string(token):
    def __init__(self, value):
        super().__init__(value)

class keyword(token):
    def __init__(self, value):
        super().__init__(value)

letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
numbers = "1234567890"

def lexer(code):

    global idx, ast, l
    idx = 0
    ast = []
    l = code[idx]
    def advanceToken():
        global idx, ast, l

        idx += 1
        if idx >= len(code):
            return ast
        l = code[idx]

    def buildString(currentToken):
        advanceToken()
        if not l == '"':
            return buildString(string(currentToken.get() + l))
        return currentToken
    
    def buildKeyword(currentToken):
        advanceToken()
        if not l == " ":
            return buildKeyword(keyword(currentToken.get() + l))
        return currentToken

    def buildNumber(currentToken):
        advanceToken()
        if not l == " ":
            return buildNumber(numeral(int(str(currentToken.get()) + l)))
        return currentToken

    while (idx < len(code)):
        if (l == '"'):
            ast.append(buildString(string("")))
        elif (re.search(l, letters)):
            ast.append(buildKeyword(keyword(l)))
        elif (re.search(l, numbers)):
            ast.append(buildNumber(numeral(int(l))))

        advanceToken()

    return ast

print(lexer('12345 add "hello world"'))