#include "SourceLexer.h"
#include <fstream>
#include <iostream>

Lexer::Lexer(const char* filename) {
    std::streampos size;

    tn = 0;

    std::ifstream source(filename, std::ios::in|std::ios::binary|std::ios::ate);
    if (source.is_open()) {
        size = source.tellg();
        text = new char[size];
        source.seekg(0, std::ios::beg);
        source.read(text, size);
        source.close();
    } else {
        std::cout << "Can't open " << filename << ". Please input an existing filename!\n";
        std::exit(EXIT_FAILURE);
    }
}



char Lexer::step() {
}
