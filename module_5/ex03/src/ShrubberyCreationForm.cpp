#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) throw(
    GradeTooHighException, GradeTooLowException)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
    : AForm(rhs) {}

ShrubberyCreationForm::~ShrubberyCreationForm() throw() {}

ShrubberyCreationForm const &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

AForm *ShrubberyCreationForm::create(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

void write_ascii_tree(std::ofstream &o) {
    o << "               ,@@@@@@@," << std::endl
      << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
      << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
      << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
      << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
      << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
      << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
      << "       |o|        | |         | |" << std::endl
      << "       |.|        | |         | |" << std::endl
      << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
    throw(GradeTooLowException, FormException) {
    if (!isSigned())
        throw FormException("ShrubberyCreationForm [" + getName() +
                            "] is not signed");
    else if (b.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::ofstream out;
    std::string filename = getName() + "_shrubbery";

    out.open(filename.c_str());
    if (!out.is_open())
        throw FormException("ShrubberyCreationForm [" + getName() +
                            "] couldn't write trees to the " + filename);
    write_ascii_tree(out);
    out.close();
}
