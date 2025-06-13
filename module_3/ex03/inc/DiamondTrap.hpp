#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
