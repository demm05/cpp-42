#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const &rhs);
    WrongAnimal(std::string const name);
    ~WrongAnimal(void);

    WrongAnimal const &operator=(WrongAnimal const &rhs);

    void makeSound(void) const;
    std::string const &getType(void) const;
};
