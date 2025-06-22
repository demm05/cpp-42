#include "../inc/Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat: Default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(Cat const &rhs) : Animal(rhs) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    _brain = new Brain(*rhs._brain);
}

Cat::~Cat(void) {
    std::cout << "Cat: Deconstructed" << std::endl;
    delete _brain;
}

Cat const &Cat::operator=(Cat const &rhs) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    Animal::operator=(rhs);
    delete _brain;
    _brain = new Brain(*rhs._brain);
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat: Makes sound: Meeeeooow" << std::endl;
}

void Cat::printIdeas() const {
    for (int i = 0; i < IDEAS_COUNT; i++) {
        const std::string &idea = _brain->getIdea(i);
        if (idea.empty())
            return;
        std::cout << "Idea №" << i << " of the CAT is: " << idea << std::endl;
    }
}

void Cat::setIdea(size_t index, std::string idea) const {
    _brain->setIdea(index, idea);
}
