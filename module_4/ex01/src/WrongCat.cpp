#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &rhs) : WrongAnimal(rhs) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat: Deconstructed" << std::endl;
}

WrongCat const &WrongCat::operator=(WrongCat const &rhs) {
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongCat: Makes sound: Meeeow" << std::endl;
}
