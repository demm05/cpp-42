#pragma once

#include <string>

class ClapTrap {
public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &rhs);
    virtual ~ClapTrap(void);

    ClapTrap const &operator=(ClapTrap const &rhs);

    virtual void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int getAttackDamage(void) const;
    int getEnergyPoints(void) const;
    int getHitPoints(void) const;
    std::string getName(void) const;

protected:
    int m_HitPoints;
    int m_EnergyPoints;
    int m_AttackDamage;
    std::string m_Name;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs);
