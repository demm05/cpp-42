#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie(void) {
    std::cout << "Zombie: " << this->_name << " was destroyed" << std::endl;
}

Zombie::Zombie(void) {
}

// anounces a new zombie
void Zombie::announce() const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
