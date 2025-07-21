#include "ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &) {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter const &ScalarConverter::operator=(ScalarConverter const &rhs) {
    (void)rhs;
    return *this;
}

void ScalarConverter::convert(std::string const &s) {
    const char *cstr = s.c_str();
    char *pend = NULL;
    double res = 0;

    if (!tryParseChar(s, &res)) {
        res = std::strtod(cstr, &pend);
        if ((*pend && (*pend != 'f' || *(pend + 1))) || errno == ERANGE) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    printChar(res);
    printInt(res);
    printFloat(res);
    printDouble(res);
}

void ScalarConverter::printChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;
}

void ScalarConverter::printFloat(double d) {
    std::cout << "float: ";
    if (std::isnan(d) || std::isinf(d))
        std::cout << d << "f";
    else if (d < std::numeric_limits<float>::min() ||
             d > std::numeric_limits<float>::max())
        std::cout << "impossible";
    else {
        float f = static_cast<float>(d);
        if (f == floor(f))
            std::cout << std::fixed << std::setprecision(1) << f;
        else
            std::cout << std::setprecision(std::numeric_limits<float>::digits10)
                      << f;
        std::cout << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d) || std::isinf(d))
        std::cout << d;
    else {
        if (d == floor(d))
            std::cout << std::fixed << std::setprecision(1) << d;
        else
            std::cout << std::setprecision(
                             std::numeric_limits<double>::digits10)
                      << d;
    }
    std::cout << std::endl;
}

bool ScalarConverter::tryParseChar(std::string const &s, double *d) {
    if (!d)
        return 0;
    if (s.length() == 1 && !isdigit(s[0]))
        *d = static_cast<double>(s[0]);
    else if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        *d = static_cast<double>(s[1]);
    else
        return 0;
    return 1;
}
