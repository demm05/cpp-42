#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int const   num_of_levels = sizeof(levels) / sizeof(levels[0]);
    void (Harl::*fptr[])() = {&Harl::debug, &Harl::info, &Harl::warning,
                              &Harl::error};

    int i = 0;
    for (; i < num_of_levels; i++) {
        if (levels[i] == level) {
            (this->*fptr[i])();
            break;
        }
    };
    switch (i) {
        case num_of_levels:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
        default: {
            while (++i < num_of_levels) {
                std::cout << std::endl;
                (this->*fptr[i])();
            }
        }
    };
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-"
                 "ketchup burger.I really do !"
              << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been "
           "coming for years, whereas you started working here just last "
           "month."
        << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
