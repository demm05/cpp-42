#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(), m_Name("NoDiamond") {
    std::cout << "DiamondTrap " << m_Name << ": Default Constructor called"
              << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
    m_Name = name;
    std::cout << "DiamondTrap " << m_Name << ": Name constructor called"
              << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << m_Name << ": Deconstructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs)
    : ScavTrap(rhs.m_Name), FragTrap(rhs.m_Name) {
}

DiamondTrap const &DiamondTrap::operator=(DiamondTrap const &rhs) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ScavTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        m_Name = rhs.m_Name;
    }
    return *this;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap: I am " << m_Name << std::endl;
}

std::ostream &operator<<(std::ostream &o, DiamondTrap const &rhs) {
    std::cout << "> DiamondTrap stats of " << rhs.getName()
              << ": HP=" << rhs.getHitPoints()
              << ", EP=" << rhs.getEnergyPoints()
              << ", AD=" << rhs.getAttackDamage();
    return o;
}
