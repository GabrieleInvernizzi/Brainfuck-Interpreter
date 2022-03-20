#pragma once

#include <stdio.h>

#define MAX_MEM 65536


class Interpreter {
    unsigned int current_line;
    unsigned int tn;
    long long int size;
    char* text;
    char memory[MAX_MEM];
    unsigned int mem_ptr;
public:
    Interpreter();
    ~Interpreter() { if (text) delete[] text; }

    int LoadProgram(const char* filename);
    int Run();
};
