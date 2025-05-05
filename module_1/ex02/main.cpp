#include <string>
#include <iostream>

int main(void) {
    std::string  string = "HI THIS IS BRAIN";
    std::string *stringPtr = &string;
    std::string &stringRef = string;

    std::cout << "Address of string:\t" << &string << std::endl;
    std::cout << "Address of stringPtr:\t" << &stringPtr << std::endl;
    std::cout << "Address of stringRef:\t" << &stringRef << std::endl;

    std::cout << "Value of string:\t" << string << std::endl;
    std::cout << "Value of stringPtr:\t" << *stringPtr << std::endl;
    std::cout << "Value of stringRef:\t" << stringRef << std::endl;
}
