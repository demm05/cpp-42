#include <cctype>
#include <iostream>
#include "PhoneBook.class.hpp"

using namespace std;

void show_instructions(void) {
    cout << "Please enter either: ADD; SEARCH; EXIT" << ": ";
}

int main(void) {
    PhoneBook book;
    string    command;

    show_instructions();
    while (getline(cin, command)) {
        if (command.compare("ADD") == 0)
            book.add_contact();
        else if (command.compare("SEARCH") == 0)
            book.search_contact();
        else if (command.compare("EXIT") == 0) {
            cout << "Bye" << endl;
            break;
        }
        command.clear();
        show_instructions();
    }
    if (cin.eof() == true)
        cout << endl << "You've pressed ^D, exiting now" << endl;
    return (0);
}
