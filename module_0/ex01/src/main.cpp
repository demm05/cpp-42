#include <cctype>
#include <iostream>
#include "PhoneBook.class.hpp"

void show_instructions(void) {
    std::cout << "Please enter either: ADD; SEARCH; EXIT" << ": ";
}

int main(void) {
    PhoneBook   book;
    std::string command;

    show_instructions();
    while (getline(std::cin, command)) {
        if (command.compare("ADD") == 0)
            book.add_contact();
        else if (command.compare("SEARCH") == 0)
            book.search_contact();
        else if (command.compare("EXIT") == 0) {
            std::cout << "Bye" << std::endl;
            break;
        }
        command.clear();
        show_instructions();
    }
    if (std::cin.eof() == true)
        std::cout << std::endl << "You've pressed ^D, exiting now" << std::endl;
    return (0);
}
