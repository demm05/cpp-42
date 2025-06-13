#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &rhs);
    ~DiamondTrap(void);

    DiamondTrap const &operator=(DiamondTrap const &rhs);

    void whoAmI(void);

private:
    std::string m_Name;
};

std::ostream &operator<<(std::ostream &o, DiamondTrap const &rhs);
