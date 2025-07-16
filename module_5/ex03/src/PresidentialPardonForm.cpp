#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) throw(
    GradeTooHighException, GradeTooLowException)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &rhs)
    : AForm(rhs) {}

PresidentialPardonForm::~PresidentialPardonForm() throw() {}

PresidentialPardonForm const &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

AForm *PresidentialPardonForm::create(std::string const &target) {
    return new PresidentialPardonForm(target);
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const
    throw(GradeTooLowException, FormException) {
    if (!isSigned())
        throw FormException("PresidentialPardonForm [" + getName() +
                            "] is not signed");
    else if (b.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}
