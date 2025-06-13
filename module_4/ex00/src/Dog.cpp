#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(Dog const &rhs) : Animal(rhs) {
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "Dog: Deconstructed" << std::endl;
}

Dog const &Dog::operator=(Dog const &rhs) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog: Makes sound: gafff gaff" << std::endl;
}
