#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {
    this->_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon &weapon)
    : _name(name), _weapon(&weapon) {
}

HumanB::~HumanB(void) {
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack(void) const {
    if (!this->_weapon)
        std::cout << this->_name << " doesn't have a weapon to attack with"
                  << std::endl;
    else
        std::cout << this->_name << " attacks with their "
                  << this->_weapon->getType() << std::endl;
}
