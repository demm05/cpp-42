#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "--- Basic Construction & Actions ---\n";
    ScavTrap zapper("Zapper");
    ScavTrap rusty;

    rusty = ScavTrap("Rusty");
    std::cout << zapper << std::endl;
    std::cout << rusty << std::endl;

    zapper.attack("a training dummy");
    zapper.takeDamage(25);
    zapper.beRepaired(10);
    zapper.guardGate();
    std::cout << "Zapper's final state: " << zapper << std::endl;

    std::cout << "\n--- Copy & Assignment Test ---\n";

    ScavTrap zapper_clone(zapper);
    std::cout << "Original: " << zapper << std::endl;
    std::cout << "Clone:    " << zapper_clone << std::endl;

    std::cout << "\n-> Damaging original...\n";
    zapper.takeDamage(50);
    std::cout << "Original: " << zapper << std::endl;
    std::cout << "Clone:    " << zapper_clone << " (unaffected)" << std::endl;

    std::cout << "\n-> Assigning clone to rusty...\n";
    rusty = zapper_clone;
    std::cout << "Rusty is now a copy of the clone: " << rusty << std::endl;

    std::cout << "\n--- TESTING POLYMORPHISM ---\n\n";

    ClapTrap* scav = new ScavTrap("RoboCop");

    std::cout << "\n-> Calling attack() via base pointer ...\n";
    scav->attack("a street thug");

    std::cout << "\n-> Deleting via base pointer ...\n";
    delete scav;

    std::cout << "\n-> For comparison, a standard ClapTrap ---\n";
    ClapTrap* clap = new ClapTrap("ED-209");
    clap->attack("Mr. Kinney");
    delete clap;

    std::cout << std::endl;

    return 0;
}
