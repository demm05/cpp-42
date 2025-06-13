#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &rhs);
    virtual ~ScavTrap(void);

    ScavTrap const &operator=(ScavTrap const &rhs);

    bool isGuardingGate(void) const;
    void guardGate(void);
    void attack(std::string const &target);

private:
    bool m_IsGuardingGate;
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &rhs);
