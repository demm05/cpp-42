#include <string>

class Zombie {
public:
    Zombie(std::string);
    ~Zombie(void);

    void    announce(void) const;
    Zombie* newZombie(std::string name) const;
    void    randomChump(std::string name) const;

private:
    std::string _name;
};
