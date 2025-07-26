#include "easyfind.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Guess the number in a container of int numbers by "
                     "providing an integer "
                     "argument [1 - 42]"
                  << std::endl;
        return 1;
    }
    std::vector<int> a(4);
    // std::list<int> a(4);
    a.push_back(42);
    a.push_back(24);
    a.push_back(13);
    a.push_back(11);
    try {
        *easyfind(a, std::strtol(argv[1], NULL, 10));
        std::cout << "You won!!" << std::endl;
    } catch (...) {
        std::cout << "Number not found in container" << std::endl;
    }
    return 0;
}
