#include "Point.hpp"

bool Point::s_bsp(Point const &a, Point const &b, Point const &c,
                  Point const &p) {
    if (!s_checkIfTriangleIsValid(a, b, c)) {
        std::cerr << "Invalid triangle" << std::endl;
        return (0);
    }

    Fixed d1(s_getCrossProduct(p, a, b));
    Fixed d2(s_getCrossProduct(p, b, c));
    Fixed d3(s_getCrossProduct(p, c, a));

    return !((d1 < 0 || d2 < 0 || d3 < 0) && (d1 > 0 || d2 > 0 || d3 > 0));
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    return Point::s_bsp(a, b, c, p);
}
