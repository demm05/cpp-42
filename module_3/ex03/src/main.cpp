#include "DiamondTrap.hpp"
#include <iostream>

// A helper function to print the stats of any ClapTrap-derived object
void printStats(ClapTrap const & clap) {
    std::cout << "  Name: " << clap.getName() << std::endl;
    std::cout << "  HP: " << clap.getHitPoints() << std::endl;
    std::cout << "  EP: " << clap.getEnergyPoints() << std::endl;
    std::cout << "  AD: " << clap.getAttackDamage() << std::endl;
    std::cout << "-------------------------" << std::endl;
}


int main(void) {
    std::cout << "--- 1. CONSTRUCTION & STATS TEST ---\n" << std::endl;

    // A DiamondTrap should have:
    // - FragTrap's Hit Points (100)
    // - ScavTrap's Energy Points (50)
    // - FragTrap's Attack Damage (30)
    // - Its own name AND ClapTrap's name (name_clap_name)
    DiamondTrap dt("ASH");
    std::cout << "\n--- Verifying Initial Stats for ASH ---" << std::endl;
    printStats(dt);
    std::cout << std::endl;


    std::cout << "--- 2. MEMBER FUNCTION TESTS ---\n" << std::endl;

    // Test inherited functions
    std::cout << "--- Testing ASH's abilities ---" << std::endl;
    dt.attack("a training dummy"); // Should use ScavTrap's attack
    dt.takeDamage(10);
    dt.beRepaired(5);
    dt.guardGate();       // ScavTrap ability
    dt.highFivesGuys();   // FragTrap ability
    dt.whoAmI();          // DiamondTrap's own ability
    std::cout << "\n--- Verifying Stats after actions ---" << std::endl;
    printStats(dt);
    std::cout << std::endl;


    std::cout << "--- 3. COPY CONSTRUCTOR TEST ---\n" << std::endl;
    
    std::cout << "--- Creating a copy of ASH named ASH_COPY ---" << std::endl;
    DiamondTrap dt_copy(dt);
    std::cout << "\n--- Verifying ASH_COPY's identity and stats ---" << std::endl;
    dt_copy.whoAmI(); // Check both names
    printStats(dt_copy);
    std::cout << std::endl;


    std::cout << "--- 4. COPY ASSIGNMENT OPERATOR TEST ---\n" << std::endl;

    std::cout << "--- Creating a new DiamondTrap named ZEUS ---" << std::endl;
    DiamondTrap dt_assign("ZEUS");
    std::cout << "\n--- Verifying ZEUS's initial stats ---" << std::endl;
    printStats(dt_assign);

    std::cout << "--- Assigning ASH to ZEUS (ZEUS = ASH) ---" << std::endl;
    dt_assign = dt; // Assignment happens here
    std::cout << "\n--- Verifying ZEUS's new identity and stats ---" << std::endl;
    dt_assign.whoAmI();
    printStats(dt_assign);
    std::cout << std::endl;
    

    std::cout << "--- 5. DESTRUCTION TEST ---\n" << std::endl;
    std::cout << "--- Objects will now go out of scope. Observe destructor order. ---" << std::endl;
    std::cout << "--- Expected order for each object: ~DiamondTrap -> ~FragTrap -> ~ScavTrap -> ~ClapTrap ---" << std::endl;

    return 0;
}
