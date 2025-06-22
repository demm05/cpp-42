#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Animal {
protected:
    std::string _type;

public:
    Animal(void);
    Animal(Animal const &rhs);
    Animal(std::string const name);
    virtual ~Animal(void);

    Animal const &operator=(Animal const &rhs);

    virtual void makeSound(void) const;

    std::string const &getType(void) const;
};
