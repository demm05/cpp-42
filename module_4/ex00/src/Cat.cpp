#include "../inc/Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(Cat const &rhs) : Animal(rhs) {
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Cat: Deconstructed" << std::endl;
}

Cat const &Cat::operator=(Cat const &rhs) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat: Makes sound: Meeeeooow" << std::endl;
}
