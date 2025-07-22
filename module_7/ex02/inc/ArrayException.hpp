#pragma once

#include <exception>
#include <string>

class ArrayException : public std::exception {
private:
    std::string const message_;

public:
    ArrayException(std::string &message);
    ArrayException(char const *message);
    virtual ~ArrayException() throw();
    char const *what(void) const throw();
};

class OutOfRange : public ArrayException {
public:
    OutOfRange();
};
