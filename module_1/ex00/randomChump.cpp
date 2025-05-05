#include "Zombie.hpp"

void Zombie::randomChump(std::string name) const {
    Zombie zomb(name);
    zomb.announce();
}
