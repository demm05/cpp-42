#include "Contact.class.hpp"

#define NUM_OF_CONTACTS 8

class PhoneBook {
public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add_contact(void);
    void search_contact(void) const;

private:
    Contact _contacts[NUM_OF_CONTACTS];
    int     _index;
    bool    _full;
};
