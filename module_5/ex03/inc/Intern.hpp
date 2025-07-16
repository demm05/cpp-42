#pragma once

#include "AForm.hpp"

class Intern {
public:
    Intern() ;
    Intern(Intern const &rhs);
    ~Intern();

    Intern const &operator=(Intern const &rhs);

	AForm *makeForm(std::string const &form_name, std::string const &target_name);
};
