#include <iostream>
#include "Interpreter.h"


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong number of arguments! Expected \"1\", found \"" 
                  << (argc - 1) << "\".\nUsage: BGi <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    Interpreter i;

    if (i.LoadProgram(argv[1]) == -1) {
        std::cerr << "Error! Can't load the program from file: \"" << argv[1] << "\"." << std::endl;
        return EXIT_FAILURE;
    }
    
    return i.Run();
}
