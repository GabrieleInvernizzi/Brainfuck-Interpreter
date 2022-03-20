#include "Interpreter.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

enum Tokens
{
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


Interpreter::Interpreter()
    : tn(0), current_line(0), mem_ptr(0)
{}

int Interpreter::LoadProgram(const char *filename)
{
    std::ifstream source(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (source.is_open()) return -1;
    size = source.tellg();
    if (size == -1) return -1;
    text = new char[size];
    source.seekg(0, std::ios::beg);
    source.read(text, size);
    source.close();
    return 0;
}

int Interpreter::Run()
{
    while (tn < size)
    {
        int lc = 0;
        char cur_tok = text[tn];

        switch (cur_tok)
        {

        case Increment:
            memory[mem_ptr]++;
            break;

        case Decrement:
            memory[mem_ptr]--;
            break;

        case RShift:
            if (mem_ptr != MAX_MEM - 1)
                mem_ptr++;
            else
            {
                std::cerr << "Error! Tried to access past the end of memory at line: " << current_line << " with the instruction: \"" << cur_tok << "\". Abort. (Memory size = " << MAX_MEM << ")\n";
                return EXIT_FAILURE;
            }
            break;

        case LShift:
            if (mem_ptr != 0)
                mem_ptr--;
            else
            {
                std::cerr << "Error! Tried to access cell (-1) at line: " << current_line << " with the instruction: \"" << cur_tok << "\". Abort.\n";
                return EXIT_FAILURE;
            }
            break;

        case Out:
            putchar(memory[mem_ptr]);
            break;

        case In:
            memory[mem_ptr] = getchar();
            break;

        case OpenLoop:
            if (!memory[mem_ptr])
            {
                tn++;
                while (lc > 0 || (cur_tok = text[tn]) != CloseLoop)
                {
                    if (cur_tok == OpenLoop)
                        lc++;
                    else if (cur_tok == CloseLoop)
                        lc--;
                    tn++;
                }
            }
            break;

        case CloseLoop:
            if (memory[mem_ptr])
            {
                tn--;
                while (lc > 0 || (cur_tok = text[tn]) != OpenLoop)
                {
                    if (cur_tok == CloseLoop)
                        lc++;
                    else if (cur_tok == OpenLoop)
                        lc--;
                    tn--;
                }
                tn--;
            }
            break;

        case NewLine:
            current_line++;
            break;
        }

        tn++;
    }

    return EXIT_SUCCESS;
}
