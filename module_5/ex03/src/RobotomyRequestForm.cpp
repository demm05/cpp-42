#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) throw(
    GradeTooHighException, GradeTooLowException)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
    : AForm(rhs) {}

RobotomyRequestForm::~RobotomyRequestForm() throw() {}

RobotomyRequestForm const &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

bool random50(void) {
    return rand() % 2 == 0;
}

AForm *RobotomyRequestForm::create(std::string const &target) {
    return new RobotomyRequestForm(target);
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
    throw(GradeTooLowException, FormException) {
    if (!isSigned())
        throw FormException("RobotomyRequestForm [" + getName() +
                            "] is not signed");
    else if (b.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    if (random50())
        std::cout << getName() << " has been robotomized" << std::endl;
    else
        std::cout << getName() << " robotomy failed" << std::endl;
}
