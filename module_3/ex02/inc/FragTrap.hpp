#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(FragTrap const &rhs);
    ~FragTrap(void);

    FragTrap const &operator=(FragTrap const &rhs);

    void highFivesGuys(void) const;
};

std::ostream &operator<<(std::ostream &o, FragTrap const &rhs);
