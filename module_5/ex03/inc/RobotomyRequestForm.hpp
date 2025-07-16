#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(std::string const &name) throw(GradeTooHighException,
                                                         GradeTooLowException);
    RobotomyRequestForm(RobotomyRequestForm const &rhs);
    ~RobotomyRequestForm() throw();

    RobotomyRequestForm const &operator=(RobotomyRequestForm const &rhs);

    static AForm *create(std::string const &target);

    void execute(Bureaucrat const &b) const
        throw(GradeTooLowException, FormException);
};
