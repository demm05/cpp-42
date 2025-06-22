#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
    : m_HitPoints(10), m_EnergyPoints(10), m_AttackDamage(0), m_Name("NoName") {
    std::cout << "Claptrap: " << m_Name << ": default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : m_HitPoints(10), m_EnergyPoints(10), m_AttackDamage(0), m_Name(name) {
    std::cout << "ClapTrap " << m_Name << ": Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << m_Name << ": deconstructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs)
    : m_HitPoints(rhs.m_HitPoints), m_EnergyPoints(rhs.m_EnergyPoints),
      m_AttackDamage(rhs.m_AttackDamage), m_Name(rhs.m_Name) {
    std::cout << "ClapTrap " << m_Name << ": Copy constructor called" << std::endl;
}

ClapTrap const &ClapTrap::operator=(ClapTrap const &rhs) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        m_HitPoints = rhs.m_HitPoints;
        m_EnergyPoints = rhs.m_EnergyPoints;
        m_AttackDamage = rhs.m_AttackDamage;
        m_Name = rhs.m_Name;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target) {
    if (m_EnergyPoints > 0) {
        m_EnergyPoints--;
        std::cout << "ClapTrap " << m_Name << " attacks " << target
                  << ", causing " << m_AttackDamage << " points of damage!"
                  << std::endl;
    } else if (m_HitPoints < 1)
        std::cout << "ClapTrap " << m_Name
                  << " can't attack when he is knocked out" << std::endl;
    else
        std::cout << "ClapTrap " << m_Name << " is out of energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (m_HitPoints > 0) {
        m_HitPoints -= amount;
        if (m_HitPoints < 0)
            m_HitPoints = 0;
        std::cout << "ClapTrap " << m_Name << " took " << amount
                  << " points of damage!" << std::endl;
    } else
        std::cout << "ClapTrap " << m_Name << " is already knocked out"
                  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (m_EnergyPoints > 0) {
        m_EnergyPoints--;
        m_HitPoints += amount;
        std::cout << "ClapTrap " << m_Name << " was repaired by " << amount
                  << std::endl;
    } else
        std::cout << "ClapTrap " << m_Name
                  << " is out of energy and cannot be repaired" << std::endl;
}

int ClapTrap::getAttackDamage(void) const { return m_AttackDamage; }
int ClapTrap::getHitPoints(void) const { return m_HitPoints; }
int ClapTrap::getEnergyPoints(void) const { return m_EnergyPoints; }
std::string ClapTrap::getName(void) const { return m_Name; }

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs) {
    std::cout << "ClapTrap " << rhs.getName() << " properties: energy( "
              << rhs.getEnergyPoints() << "); hitPoints( " << rhs.getHitPoints()
              << "); attackDamage(" << rhs.getAttackDamage() << ")"
              << std::endl;
    return o;
}
