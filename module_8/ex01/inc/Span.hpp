#pragma once

#include <ctime>
#include <exception>
#include <string>
#include <vector>

typedef unsigned int ui;

class Span {
private:
    ui capacity_;
    std::vector<int> data_;

public:
    Span(ui);
    Span(Span const &);
    ~Span();

    Span const &operator=(Span const &);

    void addNumber(int num);
    void generateNumbers(ui range, time_t seed);
    ui shortestSpan(void);
    ui longestSpan(void) const;

    void grow(ui new_capacity);

    class SpanException : public std::exception {
    private:
        std::string message_;

    public:
        SpanException(std::string const &message);
        virtual ~SpanException() throw();
        char const *what(void) const throw();
    };
};
