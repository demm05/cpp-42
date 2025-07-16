#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void print_header(const std::string &title) {
    std::cout << "\n--- " << title << " ---\n" << std::endl;
}

int main(void) {

    print_header("Test 1: Creating Valid Forms");
    try {
        Form f1("28B", 75, 100);
        std::cout << "Successfully created Form f1: " << f1 << std::endl;

        Form f2("A-13", 1, 1);
        std::cout << "Successfully created Form f2: " << f2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    print_header("Test 2: Attempting to Create Invalid Forms");
    try {
        Form invalid_high("Invalid Form", 0,
                          100); // Grade to sign is too high (0 < 1)
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        Form invalid_low("Invalid Form", 100,
                         151); // Grade to sign is too low (> 150)
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        Form invalid_exec("Invalid Form", 151,
                          100); // Grade to execute is too low (> 150)
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    print_header("Test 3: Bureaucrat Successfully Signs a Form");
    try {
        Bureaucrat signer("Hermes", 30);
        Form tax_form("Tax Form 1040", 50, 40);

        std::cout << "Initial state:" << std::endl;
        std::cout << "  " << signer << std::endl;
        std::cout << "  " << tax_form << std::endl;

        std::cout << "\n"
                  << signer.getName() << " attempts to sign "
                  << tax_form.getName() << "..." << std::endl;
        tax_form.beSigned(signer); // This should succeed (30 <= 40)

        std::cout << "\nFinal state:" << std::endl;
        std::cout << "  " << tax_form << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    print_header("Test 4: Bureaucrat Fails to Sign a Form");
    try {
        Bureaucrat low_level("Intern Bob", 120);
        Form top_secret("Top Secret Document", 10, 5);

        std::cout << "Initial state:" << std::endl;
        std::cout << "  " << low_level << std::endl;
        std::cout << "  " << top_secret << std::endl;

        std::cout << "\n"
                  << low_level.getName() << " attempts to sign "
                  << top_secret.getName() << "..." << std::endl;
        top_secret.beSigned(low_level); // This should fail (120 > 5)

    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    print_header("Test 5: Using Bureaucrat::signForm()");
    try {
        Bureaucrat signer("Leela", 1);
        Form form_to_sign("Planet Express Delivery", 25, 25);

        std::cout << "Initial state:" << std::endl;
        std::cout << "  " << signer << std::endl;
        std::cout << "  " << form_to_sign << std::endl;


        std::cout << "\n"
                  << signer.getName() << " is asked to sign "
                  << form_to_sign.getName() << "..." << std::endl;
        signer.signForm(form_to_sign);

        std::cout << "\nFinal state:" << std::endl;
        std::cout << "  " << form_to_sign << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    print_header("Test 6: Bureaucrat tries to sign an already signed form");
    try {
        Bureaucrat signer("Hermes", 30);
        Form tax_form("Tax Form 1040", 50, 40);

        tax_form.beSigned(signer);
        std::cout << "Form is now signed: " << tax_form << std::endl;

        std::cout << "\nHermes attempts to sign the form again..." << std::endl;
        tax_form.beSigned(signer); // This should now throw an exception

    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}
