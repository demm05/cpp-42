#include <string>

class Contact {
public:
    Contact(void);
    ~Contact(void);
    void set_contact(void);
    void print(int const index) const;

private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkers_secret;
};
