#include <iostream>
#include "Interpreter.h"


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong number of arguments! Expected \"1\", found \"" 
                  << (argc - 1) << "\"\nUsage: BGi <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    Interpreter i(argv[1]);
    i.Run();
    
    return 0;
}
