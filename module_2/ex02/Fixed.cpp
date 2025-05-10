#include "Fixed.hpp"
#include <cmath>

int const Fixed::m_FractionBits = 8;

//=================================CONSTRUCTORS=================================

Fixed::Fixed(void) : m_Value(0) {}

Fixed::Fixed(Fixed const &old) { *this = old; }

Fixed::Fixed(int const num) { setRawBits(num << m_FractionBits); }

Fixed::Fixed(float const num) {
    setRawBits(roundf(num * (float)(1 << m_FractionBits)));
}

Fixed::~Fixed(void) {}

//=================================CONSTRUCTORS=================================

int Fixed::getRawBits(void) const { return (m_Value); };

void Fixed::setRawBits(const int raw) { m_Value = raw; }

int Fixed::toInt(void) const { return m_Value >> m_FractionBits; }

float Fixed::toFloat(void) const {
    return (float)m_Value / (float)(1 << m_FractionBits);
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
    return (first < second) ? first : second;
}

Fixed const &Fixed::min(Fixed const &first, Fixed const &second) {
    return (first < second) ? first : second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
    return (first > second) ? first : second;
}

Fixed const &Fixed::max(Fixed const &first, Fixed const &second) {
    return (first > second) ? first : second;
}

//==================================OPERATORS==================================

bool Fixed::operator<(Fixed const &rhs) const {
    return m_Value < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return m_Value >= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
    return m_Value == rhs.getRawBits();
}

bool Fixed::operator>(Fixed const &rhs) const { return !(*this < rhs); }

bool Fixed::operator<=(Fixed const &rhs) const { return !(*this >= rhs); }

bool Fixed::operator!=(Fixed const &rhs) const { return !(*this == rhs); }

Fixed &Fixed::operator=(Fixed const &rhs) {
    m_Value = rhs.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    Fixed ret;

    ret.setRawBits(m_Value + rhs.getRawBits());
    return (ret);
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    Fixed ret;

    ret.setRawBits(m_Value - rhs.getRawBits());
    return (ret);
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const {
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++() {
    m_Value += 1;
    return (*this);
}

Fixed &Fixed::operator--() {
    m_Value -= 1;
    return (*this);
}

Fixed Fixed::operator++(int dummy) {
    Fixed temp(*this);
    (void)dummy;
    ++*this;
    return (temp);
}

Fixed Fixed::operator--(int dummy) {
    Fixed temp(*this);
    (void)dummy;
    --*this;
    return (temp);
}

//==================================OPERATORS==================================

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
    o << rhs.toFloat();
    return o;
}
