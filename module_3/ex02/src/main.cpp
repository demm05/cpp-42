#include "FragTrap.hpp"
#include <iostream>

int main(void) {
    FragTrap frag("FraG");
    std::cout << "Initial state: " << frag << std::endl;

    std::cout << "\nTesting overridden attack()...\n";
    frag.attack("a skag");

    std::cout << "\nTesting unique ability...\n";
    frag.highFivesGuys();

    std::cout << "\nTesting inherited takeDamage()...\n";
    frag.takeDamage(40);
    std::cout << "Final state: " << frag << std::endl << std::endl;
    return 0;
}
