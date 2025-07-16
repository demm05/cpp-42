#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(std::string const &name) throw(GradeTooHighException,
                                                         GradeTooLowException);
    ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
    ~ShrubberyCreationForm() throw();

    ShrubberyCreationForm const &operator=(ShrubberyCreationForm const &rhs);

    static AForm *create(std::string const &target);

    void execute(Bureaucrat const &b) const
        throw(GradeTooLowException, FormException);
};
