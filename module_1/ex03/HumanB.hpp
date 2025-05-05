#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB {
public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon &weapon);
    ~HumanB(void);
    void attack(void) const;
    void setWeapon(Weapon &weapon);

private:
    std::string _name;
    Weapon     *_weapon;
};

#endif
