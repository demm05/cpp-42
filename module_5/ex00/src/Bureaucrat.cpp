#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("Bureaucrat"), _Grade(150) {
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
	throw(GradeTooHighException, GradeTooLowException)
    : _Name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _Grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
    : _Name(rhs._Name), _Grade(rhs._Grade) {
}

Bureaucrat::~Bureaucrat() throw() {
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		_Grade = rhs._Grade;
	}
	return *this;
}

std::string const &Bureaucrat::getName(void) const {
	return _Name;
}

int Bureaucrat::getGrade(void) const {
	return _Grade;
}

void Bureaucrat::increaseGrade(unsigned int value) throw(GradeTooHighException) {
	if (value >= 150)
		throw GradeTooHighException();
	else if (_Grade - value < 1)
		throw GradeTooHighException();
	_Grade -= value;
}

void Bureaucrat::decreaseGrade(unsigned int value) throw(GradeTooLowException) {
	if (value >= 150)
		throw GradeTooLowException();
	else if (_Grade + value > 150)
		throw GradeTooLowException();
	_Grade += value;
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
