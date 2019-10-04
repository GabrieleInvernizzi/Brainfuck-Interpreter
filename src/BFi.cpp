#include <iostream>
#include "Interpreter.h"


int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Too few arguments! Usage: BGi <filename>";
        return EXIT_FAILURE;
    } else if (argc > 2) {
        std::cout << "Too many arguments! Usage: BGi <filename>";
        return EXIT_FAILURE;
    }

    Interpreter i(argv[1]);
    i.Run();
    
    return 0;
}
