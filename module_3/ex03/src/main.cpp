#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    std::cout << "--- 1. CONSTRUCTION & STATS TEST ---\n" << std::endl;

    DiamondTrap dt("ASH");
    std::cout << "\n--- Verifying Initial Stats for ASH ---" << std::endl;
    dt.whoAmI();
    std::cout << std::endl;

    std::cout << "--- 2. MEMBER FUNCTION TESTS ---\n" << std::endl;

    std::cout << "--- Testing ASH's abilities ---" << std::endl;
    dt.attack("a training dummy");
    dt.takeDamage(10);
    dt.beRepaired(5);
    dt.guardGate();
    dt.highFivesGuys();
    std::cout << "\n--- Verifying Stats after actions ---" << std::endl;
    dt.whoAmI();
    std::cout << std::endl;

    std::cout << "--- 3. COPY CONSTRUCTOR TEST ---\n" << std::endl;

    std::cout << "--- Creating a copy of ASH named ASH_COPY ---" << std::endl;
    DiamondTrap dt_copy(dt);
    std::cout << "\n--- Verifying ASH_COPY's identity and stats ---"
              << std::endl;
    dt_copy.whoAmI(); // Check both names
    std::cout << std::endl;

    std::cout << "--- 4. COPY ASSIGNMENT OPERATOR TEST ---\n" << std::endl;

    std::cout << "--- Creating a new DiamondTrap named ZEUS ---" << std::endl;
    DiamondTrap dt_assign("ZEUS");
    std::cout << "\n--- Verifying ZEUS's initial stats ---" << std::endl;
    dt_assign.whoAmI();

    std::cout << "--- Assigning ASH to ZEUS (ZEUS = ASH) ---" << std::endl;
    dt_assign = dt;
    std::cout << "\n--- Verifying ZEUS's new identity and stats ---"
              << std::endl;
    dt_assign.whoAmI();
    std::cout << std::endl;

    std::cout << "--- 5. DESTRUCTION TEST ---\n" << std::endl;
    std::cout << "--- Expected order for each object: ~DiamondTrap -> "
                 "~FragTrap -> ~ScavTrap -> ~ClapTrap ---"
              << std::endl;

    return 0;
}
