#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "compile_helper.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(Intern const &rhs) { (void)rhs; }

Intern::~Intern(void) {}

Intern const &Intern::operator=(Intern const &rhs) {
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(std::string const &form_name,
                        std::string const &target_name) {
    static const std::string form_types[] = {
        "shrubbery creation", "robotomy request", "presidential pardon"};

    static AForm *(*form_make[])(std::string const &) = {
        &ShrubberyCreationForm::create,
        &RobotomyRequestForm::create,
        &PresidentialPardonForm::create,
    };

    static const int form_size = sizeof(form_types) / sizeof(form_types[0]);

    COMPILER_ASSERT((sizeof(form_make) / sizeof(form_make[0])) == (form_size));

    for (int i = 0; i < form_size; i++) {
        if (form_types[i] == form_name) {
            std::cout << "Intern creates " << form_name << std::endl;
            return (form_make[i])(target_name);
        }
    };
    std::cerr << "Error: Form '" << form_name << "' not found" << std::endl;
    return (NULL);
}
