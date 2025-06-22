#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog: Default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(Dog const &rhs) : Animal(rhs) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    _brain = new Brain(*rhs._brain);
}

Dog::~Dog(void) {
    std::cout << "Dog: Deconstructed" << std::endl;
    delete _brain;
}

Dog const &Dog::operator=(Dog const &rhs) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    Animal::operator=(rhs);
    delete _brain;
    _brain = new Brain(*rhs._brain);
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog: Makes sound: gafff gaff" << std::endl;
}

void Dog::printIdeas() const {
    for (int i = 0; i < IDEAS_COUNT; i++) {
        const std::string &idea = _brain->getIdea(i);
        if (idea.empty())
            continue;
        std::cout << "Idea №" << i << " of the DOG is: " << idea << std::endl;
    }
}

void Dog::setIdea(size_t index, std::string idea) const {
    _brain->setIdea(index, idea);
}
