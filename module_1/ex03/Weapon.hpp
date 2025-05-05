#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
    Weapon(std::string);
    ~Weapon(void);

    std::string const &getType(void) const;
    void               setType(std::string);

private:
    std::string _type;
};

#endif
