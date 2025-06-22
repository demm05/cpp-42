#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("default") {
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type) {
    std::cout << "WrongAnimal " << type << ": Type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &rhs) {
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    _type = rhs._type;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal " << _type << ": Deconstructed" << std::endl;
}

WrongAnimal const &WrongAnimal::operator=(WrongAnimal const &rhs) {
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal " << _type << ": Doesn't make any sound" << std::endl;
}

std::string const &WrongAnimal::getType(void) const { return (_type); }
