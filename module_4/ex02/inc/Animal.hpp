#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;
    Animal(void);
    Animal(std::string const name);

public:
    Animal(Animal const &rhs);
    virtual ~Animal(void);

    Animal const &operator=(Animal const &rhs);

    virtual void makeSound(void) const = 0;

    std::string const &getType(void) const;
};
