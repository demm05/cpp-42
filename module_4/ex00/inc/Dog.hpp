#pragma once

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(void);
    Dog(Dog const &rhs);
    ~Dog(void);

    Dog const &operator=(Dog const &rhs);

    void makeSound(void) const;
};
