from lexer import *

class AST:
    def __init__(self, tree):
        self.tree = tree
    
    def __init__(self):
        pass

    def append(self, token):
        self.tree.append(token)

class BuiltIn:
    

def parser(code):
    tokens = lexer(code)

    crnt = 0
    crntTree = AST()
    while crnt <= tokens:
        if isinstance(tokens[crnt], keyword):
            if keyword.value == "print":