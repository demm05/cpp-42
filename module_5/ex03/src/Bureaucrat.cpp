#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : mName("Bureaucrat"), mGrade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    throw(GradeTooHighException, GradeTooLowException)
    : mName(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    mGrade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
    : mName(rhs.mName), mGrade(rhs.mGrade) {}

Bureaucrat::~Bureaucrat() throw() {}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        mGrade = rhs.mGrade;
    }
    return *this;
}

std::string const &Bureaucrat::getName(void) const { return mName; }

int Bureaucrat::getGrade(void) const { return mGrade; }

void Bureaucrat::increaseGrade(unsigned int value) throw(
    GradeTooHighException) {
    if (value >= 150)
        throw GradeTooHighException();
    else if (mGrade - value < 1)
        throw GradeTooHighException();
    mGrade -= value;
}

void Bureaucrat::decreaseGrade(unsigned int value) throw(GradeTooLowException) {
    if (value >= 150)
        throw GradeTooLowException();
    else if (mGrade + value > 150)
        throw GradeTooLowException();
    mGrade += value;
}

void Bureaucrat::signForm(AForm &f) const throw() {
    try {
        f.beSigned(*this);
        std::cout << mName << " signed " << f.getName() << std::endl;
    } catch (GradeTooLowException const &e) {
        std::cout << mName << " couldn't sign " << f.getName() << " because: "
                  << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm &f) const throw() {
    try {
        f.execute(*this);
        std::cout << mName << " executed " << f.getName() << std::endl;
    } catch (std::exception const &e) {
        std::cout << mName << " couldn't execute " << f.getName() << " because: "
                  << e.what() << std::endl;
    }
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Grade is too low!";
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade is too high!";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}
