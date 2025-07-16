#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(std::string const &name) throw(GradeTooHighException,
                                                         GradeTooLowException);
    PresidentialPardonForm(PresidentialPardonForm const &rhs);
    ~PresidentialPardonForm() throw();

    PresidentialPardonForm const &operator=(PresidentialPardonForm const &rhs);

    static AForm *create(std::string const &target);

    void execute(Bureaucrat const &b) const
        throw(GradeTooLowException, FormException);
};
