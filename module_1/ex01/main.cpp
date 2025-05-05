#include "Zombie.hpp"

int main(void) {
    Zombie *horde;
    Zombie  zomb("Foo");
    int     num;
    int     blah;

    zomb.announce();
    num = 10;
    horde = zomb.zombieHorde(num, "Bar");
    for (int i = 0; i < num; i++)
        horde[i].announce();
    delete[] horde;
}
