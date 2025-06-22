#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *_brain;

public:
    Cat(void);
    Cat(Cat const &rhs);
    ~Cat(void);

    Cat const &operator=(Cat const &rhs);

    void makeSound(void) const;
    void setIdea(size_t index, std::string idea) const;
    void printIdeas(void) const;
};
