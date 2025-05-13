#pragma once

#include "Fixed.hpp"

class Point {
public:
    Point(void);
    ~Point();
    Point(float const x, float const y);
    Point(Point const &rhs);

    Point const &operator=(Point const &rhs) const;

    Fixed const &getX(void) const;
    Fixed const &getY(void) const;

    Fixed static s_getCrossProduct(Point const &p, Point const &p1,
                                   Point const &p2);

    bool static s_checkIfTriangleIsValid(Point const &a, Point const &b,
                                         Point const &c);

    bool static s_bsp(Point const &a, Point const &b, Point const &c,
                      Point const &point);

private:
    Fixed const m_X;
    Fixed const m_Y;
};

std::ostream &operator<<(std::ostream &o, Point const &rhs);
