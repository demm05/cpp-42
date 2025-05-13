#pragma once

#include <iostream>

class Fixed {
public:
    Fixed(void);
    Fixed(Fixed const &old);
    Fixed(int const raw);
    Fixed(float const raw);
    ~Fixed(void);

    void setRawBits(int const raw);
    int getRawBits(void) const;
    int toInt(void) const;
    float toFloat(void) const;

    static Fixed &min(Fixed &first, Fixed &second);
    static const Fixed &min(Fixed const &first, Fixed const &second);

    static Fixed &max(Fixed &first, Fixed &second);
    static const Fixed &max(Fixed const &first, Fixed const &second);

    bool operator<(Fixed const &rhs) const;
    bool operator>(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;
    Fixed &operator=(Fixed const &rhs);

    Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;

    Fixed &operator++();         // pre
    Fixed operator++(int dummy); // post
    Fixed &operator--();         // pre
    Fixed operator--(int dummy); // post

private:
    int m_Value;
    static const int m_FractionBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
