#pragma once

#include <stdio.h>

#define MAX_MEM 65536

// token types and corresponding values (Luckly there are few)
enum Tokens {
    Increment = '+',
    Decrement = '-',
    RShift = '>',
    LShift = '<',
    Out = '.',
    In = ',',
    OpenLoop = '[',
    CloseLoop = ']',
    NewLine = '\n'
};


class Interpreter {
    unsigned int current_line;
    unsigned int tn;
    long long int size;
    char* text;
    char memory[MAX_MEM];
    unsigned int mem_ptr;
public:
    Interpreter(const char* filename);
    ~Interpreter() { if (text) delete[] text; }

    void Run();
};
