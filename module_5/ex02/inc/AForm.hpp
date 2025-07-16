#pragma once

#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
private:
    std::string const mName;
    int const mGradeToSign;
    int const mGradeToExecute;
    bool mIsSigned;

public:
    AForm(std::string const &name, int grade_to_execute,
          int grade_to_sign) throw(GradeTooHighException, GradeTooLowException);
    AForm(AForm const &rhs);
    virtual ~AForm() throw();

    AForm const &operator=(AForm const &rhs);

    std::string const &getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool isSigned(void) const;

    void beSigned(Bureaucrat const &b) throw(GradeTooLowException,
                                             FormException);
    virtual void execute(Bureaucrat const &b) const
        throw(GradeTooLowException, FormException) = 0;

    class GradeTooHighException : public std::exception {
    public:
        char const *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        char const *what(void) const throw();
    };

    class FormException : public std::exception {
    private:
        std::string mMessage;

    public:
        FormException(std::string const &message);
        virtual ~FormException() throw();
        char const *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, AForm const &b);
