import re

class token:
    def __init__(self, value):
        self.value = value

    def __repr__(self):
        return str(self.value)
    
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

class symbol(token):
    pass

letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
numbers = "1234567890"

def lexer(code):

    global idx, ast, l, ncode, line
    idx = 0
    line = 0
    ast = []
    ncode = code.split("\n")
    l = ncode[line][idx]

    print(ncode)

    def advanceToken():
        global idx, ast, l, ncode, line

        idx += 1
        if idx > len(ncode[line]) - 1:
            line += 1
            idx = 0
            if line == len(ncode):
                return True
        l = ncode[line][idx]
        print(l)

    def buildString(currentToken):
        if advanceToken(): return currentToken
        if not l == '"':
            return buildString(string(currentToken.get() + l))
        return currentToken
    
    def buildKeyword(currentToken):
        if advanceToken(): return currentToken
        if not l == " ":
            return buildKeyword(keyword(currentToken.get() + l))
        return currentToken

    def buildNumber(currentToken):
        if advanceToken(): return currentToken
        if not l == " ":
            return buildNumber(numeral(int(str(currentToken.get()) + l)))
        return currentToken

    while (idx < len(code)):
        if (l == '"'):
            ast.append(buildString(string("")))
        elif (re.search(letters, l)):
            ast.append(buildKeyword(keyword(l)))
        elif (re.search(numbers, l)):
            ast.append(buildNumber(numeral(int(l))))

        print(ast)
        if advanceToken(): 
            return ast

if __name__ == "__main__":
    cd = """print "hello world"
    x: int = 1 
    y: int = 2 
    z: int = x + y 
    print z 
    """

    print(lexer(cd))