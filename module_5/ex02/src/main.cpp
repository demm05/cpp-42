#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void    set_unique_seed(void)
{
    int dummy_for_seeding;
    unsigned int seed = static_cast<unsigned int>(time(0));
    seed ^= reinterpret_cast<unsigned long>(&dummy_for_seeding);
    srand(seed);
}

int main(void) {
    set_unique_seed();

    RobotomyRequestForm sh("home");
    Bureaucrat b("Dima", 1);

    b.signForm(sh);
    b.executeForm(sh);
    return 0;
}
