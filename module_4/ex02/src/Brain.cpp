#include "../inc/Brain.hpp"
#include <iostream>

Brain::Brain(void) {
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(Brain const &rhs) {
    std::cout << "Brain: Copy constructor called" << std::endl;
    *this = rhs;
}

Brain::~Brain(void) { std::cout << "Brain: Deconstructed" << std::endl; }

Brain const &Brain::operator=(Brain const &rhs) {
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < IDEAS_COUNT; i++)
            _ideas[i] = rhs._ideas[i];
    }
    return *this;
}

std::string const &Brain::getIdea(size_t index) const {
    if (index > IDEAS_COUNT)
        return _ideas[index % IDEAS_COUNT];
    return (_ideas[index]);
}

void Brain::setIdea(size_t index, std::string idea) {
    if (index > IDEAS_COUNT)
        return;
    _ideas[index] = idea;
}
