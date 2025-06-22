#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap(), m_Name("NoDiamond") {
    std::cout << "DiamondTrap " << m_Name << ": Default Constructor called"
              << std::endl;
    // m_EnergyPoints = ScavTrap::m_EnergyPoints;
    // m_HitPoints = FragTrap::m_HitPoints;
    // m_AttackDamage = FragTrap::m_AttackDamage;
    m_HitPoints = 100; 
    m_EnergyPoints = 50;
    m_AttackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),ScavTrap(name), FragTrap(name), m_Name(name) {
    std::cout << "DiamondTrap " << m_Name << ": Name constructor called"
              << std::endl;
    // m_EnergyPoints = ScavTrap::m_EnergyPoints;
    // m_HitPoints = FragTrap::m_HitPoints;
    // m_AttackDamage = FragTrap::m_AttackDamage;
    m_HitPoints = 100; 
    m_EnergyPoints = 50;
    m_AttackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs)
    : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs) {
    std::cout << "DiamondTrap copy constructor" << std::endl;
    m_Name = rhs.m_Name;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << m_Name << ": Deconstructed" << std::endl;
}

DiamondTrap const &DiamondTrap::operator=(DiamondTrap const &rhs) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        m_Name = rhs.m_Name;
    }
    return *this;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap: I am " << m_Name
              << " and I'm derived from ClapTrap class: " << ClapTrap::m_Name
              << "; My stats are: " << "HP=" << m_HitPoints
              << ", EP=" << m_EnergyPoints << ", AD=" << m_AttackDamage
              << ", IG=" << isGuardingGate() << std::endl;
}
