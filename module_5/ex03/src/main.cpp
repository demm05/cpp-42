#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void print_header(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n" << std::endl;
}

int main(void) {
    Intern      someRandomIntern;
    Bureaucrat  boss("The Boss", 1);
    AForm* form;

    print_header("Test 1: Intern creates Shrubbery Creation Form");
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    print_header("Test 2: Intern creates Robotomy Request Form");
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    print_header("Test 3: Intern creates Presidential Pardon Form");
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    print_header("Test 4: Intern fails to create a non-existent form");
    form = someRandomIntern.makeForm("request for a holiday", "Me");
    if (form) {
        // This block should not be reached
        std::cerr << "Test failed: Form should have been NULL." << std::endl;
        delete form;
    }

    return 0;
}
