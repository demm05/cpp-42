#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name) const {
    return (new Zombie(name));
}
