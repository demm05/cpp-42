#include "Point.hpp"
#include <iomanip>

Point::Point(void) : m_X(0), m_Y(0) {}

Point::Point(float const x, float const y) : m_X(x), m_Y(y) {}

Point::Point(Point const &rhs) : m_X(rhs.getX()), m_Y(rhs.getY()) {}

Point::~Point(void) {}

Point const &Point::operator=(Point const &rhs) const { return rhs; }

Fixed const &Point::getX(void) const { return this->m_X; }

Fixed const &Point::getY(void) const { return this->m_Y; }

bool Point::s_checkIfTriangleIsValid(const Point &a, const Point &b,
                                     const Point &c) {
    Fixed area = a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY());
    return (area != 0);
}

Fixed Point::s_getCrossProduct(Point const &p, Point const &a, Point const &b) {
    Fixed temp = (p.getX() - b.getX()) * (a.getY() - b.getY()) -
                 (a.getX() - b.getX()) * (p.getY() - b.getY());
#ifdef DEBUG
    std::cout << "The cross product of point is: "
              << ((temp < 0) ? "left" : "right") << std::endl;
#endif
    return (temp);
}

std::ostream &operator<<(std::ostream &o, Point const &rhs) {
    std::cout << "x: " << std::setfill(' ') << std::setw(3) << rhs.getX()
              << "\ty: " << std::setw(3) << rhs.getY();
    return o;
}
