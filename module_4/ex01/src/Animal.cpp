#include "../inc/Animal.hpp"

Animal::Animal(void) : _type("default") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string const type) : _type(type) {
    std::cout << "Animal " << type << ": Type constructor called" << std::endl;
}

Animal::Animal(Animal const &rhs) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    _type = rhs._type;
}

Animal::~Animal(void) {
    std::cout << "Animal " << _type << ": Deconstructed" << std::endl;
}

Animal const &Animal::operator=(Animal const &rhs) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << "Animal " << _type << ": Doesn't make any sound" << std::endl;
}

std::string const &Animal::getType(void) const { return (_type); }
