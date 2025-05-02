#include <cstdlib>
#include <string>
#include <iostream>

void read_input(const char *message, std::string &dest) {
    if (!message)
        return;
    while (1) {
        std::cout << "Enter " << message << ": ";
        if (!getline(std::cin, dest)) {
            std::cout << std::endl << "^D was pressed, exitining" << std::endl;
            exit(1);
        }
        if (!dest.empty())
            break;
        dest.clear();
    }
}
