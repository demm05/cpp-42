#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
    m_HitPoints = 100;
    m_EnergyPoints = 100;
    m_AttackDamage = 30;
    m_Name = "NoName";
    std::cout << "FragTrap " << m_Name << ": Default Constructor called"
              << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    m_HitPoints = 100;
    m_EnergyPoints = 100;
    m_AttackDamage = 30;
    m_Name = name ;
    std::cout << "FragTrap " << m_Name << ": Name constructor called"
              << std::endl;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << m_Name << ": Deconstructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &rhs) : ClapTrap(rhs.m_Name) {
    m_HitPoints = rhs.m_HitPoints;
    m_EnergyPoints = rhs.m_EnergyPoints;
    m_AttackDamage = rhs.m_AttackDamage;
}

FragTrap const &FragTrap::operator=(FragTrap const &rhs) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

void FragTrap::highFivesGuys(void) const {
    if (m_HitPoints > 0)
        std::cout << "FragTrap " << this->getName()
                  << " requests a high five! ... Anyone? ... Up high! ... No?"
                  << std::endl;
    else
        std::cout << "FragTrap " << this->getName()
                  << " can't request a high five, it's in pieces." << std::endl;
}

std::ostream &operator<<(std::ostream &o, FragTrap const &rhs) {
    std::cout << "> FragTrap stats of " << rhs.getName()
              << ": HP=" << rhs.getHitPoints()
              << ", EP=" << rhs.getEnergyPoints()
              << ", AD=" << rhs.getAttackDamage();
    return o;
}
