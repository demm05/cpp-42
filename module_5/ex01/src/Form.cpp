#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &name, int grade_to_execute, int grade_to_sign)
    throw(GradeTooHighException, GradeTooLowException)
    : mName(name), mGradeToSign(grade_to_sign),
      mGradeToExecute(grade_to_execute), mIsSigned(0) {
    if (grade_to_execute < 1 || grade_to_sign < 1)
        throw GradeTooHighException();
    else if (grade_to_execute > 150 || grade_to_sign > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &rhs)
    : mName(rhs.mName), mGradeToSign(rhs.mGradeToSign),
      mGradeToExecute(rhs.mGradeToExecute), mIsSigned(rhs.mIsSigned) {}

Form::~Form() throw() {}

Form const &Form::operator=(Form const &rhs) {
    if (this != &rhs)
        mIsSigned = rhs.mIsSigned;
    return *this;
}

std::string const &Form::getName(void) const { return mName; }
int Form::getGradeToSign(void) const { return mGradeToSign; }
int Form::getGradeToExecute(void) const { return mGradeToExecute; }
bool Form::isSigned(void) const { return mIsSigned; }

void Form::beSigned(Bureaucrat const &b) throw(GradeTooLowException, FormException) {
    if (mIsSigned)
        throw FormException("Form [" + mName + "] is already signed");
    if (b.getGrade() > mGradeToSign)
        throw GradeTooLowException();
    mIsSigned = 1;
}

char const *Form::GradeTooLowException::what(void) const throw() {
    return "Grade is too low!";
}

char const *Form::GradeTooHighException::what(void) const throw() {
    return "Grade is too high!";
}

Form::FormException::FormException(std::string const &message): mMessage(message) {}
Form::FormException::~FormException(void) throw() {}
char const *Form::FormException::what(void) const throw() { return mMessage.c_str(); }

std::ostream &operator<<(std::ostream &o, Form const &f) {
    o << "Form " << f.getName()
        << ": [Status: " << (f.isSigned() ? "" : "Not ") << "Signed"
        << "], [Grade to Sign: " << f.getGradeToSign()
        << "], [Grade to Execute: " << f.getGradeToExecute() << "]";
    return o;
}
