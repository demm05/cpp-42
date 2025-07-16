#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &name, int grade_to_execute, int grade_to_sign)
    throw(GradeTooHighException, GradeTooLowException)
    : mName(name), mGradeToSign(grade_to_sign),
      mGradeToExecute(grade_to_execute), mIsSigned(0) {
    if (grade_to_execute < 1 || grade_to_sign < 1)
        throw GradeTooHighException();
    else if (grade_to_execute > 150 || grade_to_sign > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &rhs)
    : mName(rhs.mName), mGradeToSign(rhs.mGradeToSign),
      mGradeToExecute(rhs.mGradeToExecute), mIsSigned(rhs.mIsSigned) {}

AForm::~AForm() throw() {}

AForm const &AForm::operator=(AForm const &rhs) {
    if (this != &rhs)
        mIsSigned = rhs.mIsSigned;
    return *this;
}

std::string const &AForm::getName(void) const { return mName; }
int AForm::getGradeToSign(void) const { return mGradeToSign; }
int AForm::getGradeToExecute(void) const { return mGradeToExecute; }
bool AForm::isSigned(void) const { return mIsSigned; }

void AForm::beSigned(Bureaucrat const &b) throw(GradeTooLowException, FormException) {
    if (mIsSigned)
        throw FormException("Form [" + mName + "] is already signed");
    if (b.getGrade() > mGradeToSign)
        throw GradeTooLowException();
    mIsSigned = 1;
}

void AForm::execute(Bureaucrat const &b) const throw(GradeTooLowException, FormException) {
    if (!mIsSigned)
        throw FormException("Form [" + mName + "] is not signed");
    if (b.getGrade() > mGradeToExecute)
        throw GradeTooLowException();
}

char const *AForm::GradeTooLowException::what(void) const throw() {
    return "Grade is too low!";
}

char const *AForm::GradeTooHighException::what(void) const throw() {
    return "Grade is too high!";
}

AForm::FormException::FormException(std::string const &message): mMessage(message) {}
AForm::FormException::~FormException(void) throw() {}
char const *AForm::FormException::what(void) const throw() { return mMessage.c_str(); }

std::ostream &operator<<(std::ostream &o, AForm const &f) {
    o << "AForm " << f.getName()
        << ": [Status: " << (f.isSigned() ? "" : "Not ") << "Signed"
        << "], [Grade to Sign: " << f.getGradeToSign()
        << "], [Grade to Execute: " << f.getGradeToExecute() << "]";
    return o;
}
