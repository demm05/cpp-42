#pragma once

#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
private:
    Form const &operator=(Form const &rhs);
    std::string const mName;
    int const mGradeToSign;
    int const mGradeToExecute;
    bool mIsSigned;

public:
    Form(std::string const &name, int grade_to_execute,
         int grade_to_sign) throw(GradeTooHighException, GradeTooLowException);
    Form(Form const &rhs);
    ~Form() throw();

    std::string const &getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool isSigned(void) const;

    void beSigned(Bureaucrat const &b) throw(GradeTooLowException);

    class GradeTooHighException : public std::exception {
    public:
        char const *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        char const *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Form const &b);
