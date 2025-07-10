#include "Bureaucrat.hpp"

int main(void) {
    std::cout << "--- Test Case 1: Valid Forms ---" << std::endl;
    try {
        Bureaucrat b1("Zaphod", 42);
        std::cout << b1 << std::endl;

        b1.increaseGrade(2);  // Grade becomes 40
        std::cout << "After promotion: " << b1 << std::endl;

        b1.decreaseGrade(10);  // Grade becomes 50
        std::cout << "After demotion: " << b1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Construction Exceptions ---" << std::endl;
    try {
        Bureaucrat high("High", 0);  // Too high
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat low("Low", 151);  // Too low
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Grade Modification Exceptions ---"
              << std::endl;
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.increaseGrade();  // Should throw
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decreaseGrade();  // Should throw
    } catch (std::exception &e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Copy and Assignment ---" << std::endl;
    Bureaucrat original("Original", 100);
    Bureaucrat copy(original);  // Test copy constructor
    Bureaucrat assigned("Assigned", 50);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Assigned (before): " << assigned << std::endl;

    assigned = original;  // Test assignment operator

    std::cout << "Assigned (after): " << assigned << std::endl;

    return 0;
}
