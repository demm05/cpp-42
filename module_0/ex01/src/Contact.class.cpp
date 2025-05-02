#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Contact.class.hpp"
#include "utils.hpp"

using namespace std;

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void Contact::set_contact(void) {
    read_input("first name", this->first_name);
    read_input("last name", this->last_name);
    read_input("nickname", this->nick_name);
    read_input("phone number", this->phone_number);
    read_input("darkest secret", this->darkers_secret);
}

void print_truncated(int const &index) {
    cout << "|";
    cout << setw(10) << index;
}

void print_truncated(string const &src) {
    cout << "|";
    if (src.length() > 10)
        cout << src.substr(0, 9) << '.';
    else
        cout << setw(10) << src;
}

void Contact::print(int const index) const {
    print_truncated(index);
    print_truncated(this->first_name);
    print_truncated(this->last_name);
    print_truncated(this->nick_name);
    cout << '|' << endl;
}
