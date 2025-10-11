#include "primitive.hpp"

bool isAllDigit(std::string const &s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!::isdigit(*it))
            return false;
    }
    return true;
}
