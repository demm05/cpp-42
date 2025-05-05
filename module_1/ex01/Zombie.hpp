#include <string>

class Zombie {
public:
    Zombie(std::string);
    ~Zombie(void);

    void    announce(void) const;
    void    set_name(std::string name);
    Zombie* zombieHorde(int N, std::string name) const;

private:
    Zombie();
    std::string _name;
};
