#include "Zombie.hpp"

void Zombie::set_name(std::string name) {
    this->_name = name;
}

Zombie *Zombie::zombieHorde(int N, std::string name) const {
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].set_name(name);
    return (horde);
}
