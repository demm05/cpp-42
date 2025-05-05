#include "Zombie.hpp"

int main(void) {
    Zombie zomb("Foo");
    zomb.announce();
    zomb.randomChump("Fizz");
    Zombie *temp = zomb.newZombie("Bar");
    temp->announce();
    delete temp;
}
