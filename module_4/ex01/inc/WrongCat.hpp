#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat(void);
    WrongCat(WrongCat const &rhs);
    ~WrongCat(void);

    WrongCat const &operator=(WrongCat const &rhs);

    void makeSound(void) const;
};
