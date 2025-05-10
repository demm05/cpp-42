#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : m_Value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &old) {
    std::cout << "Copy constructor called" << std::endl;
    *this = old;
}

Fixed::Fixed(int const num) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(num << m_FractionBits);
}

Fixed::Fixed(float const num) {
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(num * (float)(1 << m_FractionBits)));
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    m_Value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const { return (m_Value); };

void Fixed::setRawBits(const int raw) { m_Value = raw; }

int Fixed::toInt(void) const { return m_Value >> m_FractionBits; }

float Fixed::toFloat(void) const {
    return (float)m_Value / (float)(1 << m_FractionBits);
}

int const Fixed::m_FractionBits = 8;

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return o;
}
