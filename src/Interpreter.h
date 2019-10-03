#pragma once

#include "SourceLexer.h"
#include <iostream>

class Interpreter {
    Lexer* lexer;
public:
    Interpreter(const char* filename) { lexer = new Lexer(filename); }
    ~Interpreter() { if (lexer) delete lexer; }

    void Run();
};
