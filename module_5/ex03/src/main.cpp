#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

void    set_unique_seed(void)
{
    int dummy_for_seeding;
    unsigned int seed = static_cast<unsigned int>(time(0));
    seed ^= reinterpret_cast<unsigned long>(&dummy_for_seeding);
    srand(seed);
}

int main(int argc, char **argv) {
    set_unique_seed();

    Intern someRandomIntern;
    AForm* rrf;

    if (argc == 2)
        rrf = someRandomIntern.makeForm(argv[1], "Bender");
    else
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    return 0;
}
