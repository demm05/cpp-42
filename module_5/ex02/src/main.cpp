#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void print_header(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n" << std::endl;
}

int main(void) {
    Bureaucrat high_grade_bur("Zaphod", 1);
    Bureaucrat mid_grade_bur("Arthur", 40);
    Bureaucrat low_grade_bur("Ford", 140);

    ShrubberyCreationForm   shrub_form("garden");
    RobotomyRequestForm     robo_form("Bender");
    PresidentialPardonForm  pardon_form("Marvin");

    print_header("Test 1: Execute unsigned forms (all should fail)");
    high_grade_bur.executeForm(shrub_form);
    high_grade_bur.executeForm(robo_form);
    high_grade_bur.executeForm(pardon_form);

    print_header("Test 2: Signing all forms");
    high_grade_bur.signForm(shrub_form);
    high_grade_bur.signForm(robo_form);
    high_grade_bur.signForm(pardon_form);
    std::cout << shrub_form << std::endl;
    std::cout << robo_form << std::endl;
    std::cout << pardon_form << std::endl;

    print_header("Test 3: Execute with inadequate grades (should fail)");
    low_grade_bur.executeForm(shrub_form);  // Fails, needs 137, has 140
    low_grade_bur.executeForm(robo_form);   // Fails, needs 45, has 140
    mid_grade_bur.executeForm(pardon_form); // Fails, needs 5, has 40

    print_header("Test 4: Successful Executions");
    mid_grade_bur.executeForm(shrub_form);
    mid_grade_bur.executeForm(robo_form);
    high_grade_bur.executeForm(pardon_form);

    return 0;
}
