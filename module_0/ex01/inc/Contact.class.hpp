#include <string>

using namespace std;

class Contact {
public:
    Contact(void);
    ~Contact(void);
    void set_contact(void);
    void print(int const index) const;

private:
    string first_name;
    string last_name;
    string nick_name;
    string phone_number;
    string darkers_secret;
};
