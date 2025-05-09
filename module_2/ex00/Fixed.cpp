#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : m_Value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &old) {
    std::cout << "Copy constructor called" << std::endl;
    *this = old;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

void Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->m_Value = rhs.getRawBits();
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->m_Value);
};

void Fixed::setRawBits(const int raw) { this->m_Value = raw; }

int const Fixed::m_FractionBits = 8;
