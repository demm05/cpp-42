#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *_brain;

public:
    Dog(void);
    Dog(Dog const &rhs);
    ~Dog(void);

    Dog const &operator=(Dog const &rhs);

    void makeSound(void) const;
    void setIdea(size_t index, std::string idea) const;
    void printIdeas(void) const;
};
