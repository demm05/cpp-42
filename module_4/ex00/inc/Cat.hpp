#pragma once

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat(void);
    Cat(Cat const &rhs);
    ~Cat(void);

    Cat const &operator=(Cat const &rhs);

    void makeSound(void) const;
};
