#pragma once

#include <iostream>
#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &);
    ScalarConverter const &operator=(ScalarConverter const &);
    ~ScalarConverter();

    static void printChar(double);
    static void printInt(double);
    static void printFloat(double);
    static void printDouble(double);

    static bool tryParseChar(std::string const &s, double *d);

public:
    static void convert(std::string const &);
};
