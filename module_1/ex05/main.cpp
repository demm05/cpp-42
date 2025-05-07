#include <iostream>
#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Printing all harl could say." << std::endl << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("something else");
    return 0;
}
