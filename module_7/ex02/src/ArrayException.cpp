#include "ArrayException.hpp"

ArrayException::ArrayException(std::string &message)
    : message_("ArrayException: " + message) {}

ArrayException::ArrayException(char const *message)
    : message_(std::string("ArrayException: ") + message) {}

ArrayException::~ArrayException() throw() {}

const char *ArrayException::what(void) const throw() {
    return message_.c_str();
}

OutOfRange::OutOfRange() : ArrayException("out of range") {};
