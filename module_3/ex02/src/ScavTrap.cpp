#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
    m_HitPoints = 100;
    m_EnergyPoints = 50;
    m_AttackDamage = 20;
    m_IsGuardingGate = 0;
    std::cout << "ScavTrap " << m_Name << ": Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    m_HitPoints = 100;
    m_EnergyPoints = 50;
    m_AttackDamage = 20;
    m_IsGuardingGate = 0;
    std::cout << "ScavTrap " << m_Name << ": Constructed" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << m_Name << ": Deconstructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &rhs) : ClapTrap(rhs.m_Name) {
    m_HitPoints = rhs.m_HitPoints;
    m_EnergyPoints = rhs.m_EnergyPoints;
    m_AttackDamage = rhs.m_AttackDamage;
    m_IsGuardingGate = rhs.m_IsGuardingGate;
}

ScavTrap const &ScavTrap::operator=(ScavTrap const &rhs) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        m_HitPoints = rhs.m_HitPoints;
        m_EnergyPoints = rhs.m_EnergyPoints;
        m_AttackDamage = rhs.m_AttackDamage;
        m_IsGuardingGate = rhs.m_IsGuardingGate;
        m_Name = rhs.m_Name;
    }
    return *this;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << m_Name << ": Guarding gate" << std::endl;
    m_IsGuardingGate = 1;
}

bool ScavTrap::isGuardingGate(void) const { return (m_IsGuardingGate); }

void ScavTrap::attack(std::string const &target) {
    if (m_EnergyPoints > 0) {
        m_EnergyPoints--;
        std::cout << "ScavTrap " << m_Name << ": Attacks " << target
                  << ", causing " << m_AttackDamage << " points of damage!"
                  << std::endl;
    } else if (m_HitPoints < 1)
        std::cout << "ScavTrap " << m_Name
                  << ": Can't attack when he is knocked out" << std::endl;
    else
        std::cout << "ScavTrap " << m_Name << ": is out of energy" << std::endl;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &rhs) {
    std::cout << "> ScavTrap stats of " << rhs.getName()
              << ": HP=" << rhs.getHitPoints()
              << ", EP=" << rhs.getEnergyPoints()
              << ", AD=" << rhs.getAttackDamage()
              << ", IG=" << rhs.isGuardingGate();
    return o;
}
