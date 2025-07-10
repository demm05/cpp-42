#pragma once

#include <string>
#include <iostream>

class Bureaucrat {
private:
    std::string const _Name;
    int         _Grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade) throw(GradeTooHighException, GradeTooLowException);
    Bureaucrat(Bureaucrat const &rhs);
    ~Bureaucrat() throw();

    Bureaucrat const &operator=(Bureaucrat const &rhs);

    std::string const &getName(void) const;
    int getGrade(void) const;

    void increaseGrade(unsigned int value = 1) throw(GradeTooHighException);
    void decreaseGrade(unsigned int value = 1) throw(GradeTooLowException);

    class GradeTooHighException : public std::exception {
    public:
        char const *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        char const *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b);
