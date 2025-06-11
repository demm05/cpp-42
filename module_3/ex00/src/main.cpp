#include "ClapTrap.hpp"
#include <iostream>

void test(const std::string &desc, bool passed) {
    if (passed)
        std::cout << "\033[1;32m[PASS] \033[0m" << desc << std::endl;
    else
        std::cout << "\033[1;31m[FAIL] \033[0m" << desc << std::endl;
}

int main(void) {
    std::cout << "\n--- Testing Constructors ---" << std::endl;
    ClapTrap bob("Bob");
    test("Named constructor sets the name", bob.getName() == "Bob");
    test("Constructor sets Hit Points to 10", bob.getHitPoints() == 10);
    test("Constructor sets Energy Points to 10", bob.getEnergyPoints() == 10);
    test("Constructor sets Attack Damage to 0", bob.getAttackDamage() == 0);

    std::cout << "\n--- Testing Actions ---" << std::endl;
    ClapTrap anna("Anna");

    anna.attack("a target");
    test("Attack consumes 1 energy point", anna.getEnergyPoints() == 9);
    test("Attack does not change hit points", anna.getHitPoints() == 10);

    anna.takeDamage(4);
    test("takeDamage reduces hit points", anna.getHitPoints() == 6);
    test("takeDamage does not change energy points",
         anna.getEnergyPoints() == 9);

    anna.beRepaired(2);
    test("beRepaired restores hit points", anna.getHitPoints() == 8);
    test("beRepaired consumes 1 energy point", anna.getEnergyPoints() == 8);

    std::cout << "\n--- Testing Edge Cases ---" << std::endl;
    ClapTrap carl("Carl");

    carl.takeDamage(100);
    test("Hit points do not go below 0", carl.getHitPoints() == 0);

    carl.takeDamage(1);
    test("Taking damage at 0 HP has no effect", carl.getHitPoints() == 0);

    ClapTrap denise("Denise");
    for (int i = 0; i < 10; ++i)
        denise.attack("the void");

    test("Energy points should be 0 after 10 attacks",
         denise.getEnergyPoints() == 0);

    int hp_before = denise.getHitPoints();
    denise.attack("the void again");
    denise.beRepaired(5);
    test("Attack at 0 energy has no effect on HP",
         denise.getHitPoints() == hp_before);
    test("Repair at 0 energy has no effect on HP",
         denise.getHitPoints() == hp_before);
    test("Actions at 0 energy do not change energy",
         denise.getEnergyPoints() == 0);

    std::cout << "\n--- Testing Copy and Assignment ---" << std::endl;
    ClapTrap original("Original");
    original.takeDamage(3);

    ClapTrap copy(original);
    test("Copy constructor copies name", copy.getName() == "Original");
    test("Copy constructor copies hit points", copy.getHitPoints() == 7);
    test("Copy constructor copies energy points", copy.getEnergyPoints() == 10);

    ClapTrap assigned("Assigned");
    assigned = original;
    test("Assignment operator copies name", assigned.getName() == "Original");
    test("Assignment operator copies hit points", assigned.getHitPoints() == 7);
    test("Assignment operator copies energy points",
         assigned.getEnergyPoints() == 10);

    copy.attack("a new foe");
    test("Modifying copy does not change original's energy",
         original.getEnergyPoints() == 10);
    std::cout << std::endl;
    return 0;
}
