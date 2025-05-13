#include "Point.hpp"
#include <iomanip>

bool bsp(Point const a, Point const b, Point const c, Point const p);

void test(Point const a, Point const b, Point const c, Point const p) {
    std::cout << std::setfill('-') << std::setw(54) << "" << std::endl;
    std::cout << "The point(" << p << ") is inside the triangle" << std::endl
              << "\ta(" << a << ")" << std::endl
              << "\tb(" << b << ")" << std::endl
              << "\tc(" << c << ")" << std::endl;
    if (bsp(a, b, c, p))
        std::cout << "\033[32mTRUE\033[0m" << std::endl;
    else
        std::cout << "\033[31mFALSE\033[0m" << std::endl;
}

int main(void) {
    test(Point(), Point(10, 30), Point(20, 0), Point(1, 1));
    test(Point(), Point(10, 30), Point(20, 0), Point(10, 5));
    test(Point(), Point(10, 30), Point(20, 0), Point(5, 10));
    test(Point(), Point(10, 30), Point(20, 0), Point(15, 10));
    test(Point(), Point(10, 30), Point(20, 0), Point(10, 29));
    test(Point(), Point(10, 30), Point(20, 0), Point(111, 1));
    test(Point(), Point(10, 30), Point(20, 0), Point(0, 0));
    test(Point(), Point(10, 30), Point(20, 0), Point(10, 30));
    test(Point(), Point(10, 30), Point(20, 0), Point(5, 0));
    test(Point(), Point(10, 30), Point(20, 0), Point(10, -5));
    test(Point(), Point(10, 30), Point(20, 0), Point(-1, 10));
    test(Point(), Point(5, 0), Point(10, 0), Point(3, 0));
    return 0;
}
