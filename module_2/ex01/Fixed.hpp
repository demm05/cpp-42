#pragma once

#include <iostream>

class Fixed {
public:
    Fixed(void);
    Fixed(Fixed const &old);
    Fixed(int const raw);
    Fixed(float const raw);
    ~Fixed(void);
    Fixed &operator=(Fixed const &rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;

private:
    int m_Value;
    static const int m_FractionBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
