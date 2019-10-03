#pragma once

// token types and corresponding values (Luckly there are few)
enum Tokens {
    Increment = '+',
    Decrement = '-',
    RShift = '>',
    LShift = '<',
    Out = '.',
    In = ',',
    OpenLoop = '[',
    CloseLoop = ']'
};



class Lexer {
    unsigned int current_line;
    unsigned int tn;
    char* text;
public:
    Lexer(const char* filename);
    ~Lexer() { if(text) delete[] text; }
    char step();
};
