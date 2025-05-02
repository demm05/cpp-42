#include <cstdlib>
#include <cctype>
#include <iostream>
#include "PhoneBook.class.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void) : _index(-1), _full(0) {
    std::cout << "PhoneBook's constructor is called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "PhoneBook's destructor is called" << std::endl;
}

void PhoneBook::add_contact(void) {
    Contact *p;

    if (this->_index == NUM_OF_CONTACTS - 1) {
        p = &this->_contacts[0];
        this->_index = 0;
        this->_full = 1;
    } else
        p = &this->_contacts[++this->_index];
    p->set_contact();
}

void PhoneBook::search_contact(void) const {
    string input;
    int    index;

    if (this->_index == -1) {
        cout << "Please add at least 1 contact to use search" << endl;
        return;
    }
    while (1) {
        read_input("an index of contact to search", input);
        index = atoi(input.c_str());
        if (!std::isdigit(input.at(0)))
            cout << "Only digits";
        else if (index > this->_index && !this->_full)
            cout << "There is only " << this->_index + 1
                 << " contacts in the phonebook";
        else if (index > NUM_OF_CONTACTS - 1)
            cout << "There is only" << NUM_OF_CONTACTS
                 << "contacts in the phonebook";
        else if (index >= 0)
            break;
        else
            cout << "Invalid index";
        input.clear();
        cout << endl;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    this->_contacts[index].print(index);
    std::cout << "|-------------------------------------------|" << std::endl;
}
