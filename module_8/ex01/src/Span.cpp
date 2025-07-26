#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(ui len) : capacity_(len) {}
Span::~Span() {}
Span::Span(Span const &rhs) : capacity_(rhs.capacity_), data_(rhs.data_) {}
Span const &Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        capacity_ = rhs.capacity_;
        data_ = rhs.data_;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (data_.size() >= capacity_)
        throw SpanException("Not enough capacity for a new element");
    data_.push_back(num);
}

void Span::generateNumbers(ui range, time_t seed) {
    srand(seed);
    for (ui i = 0; i < range; i++) {
        try {
            addNumber(rand());
        } catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
}

ui Span::shortestSpan(void) {
    if (data_.size() < 2) {
        throw SpanException("Not enough elements to find a span");
    }
    std::sort(data_.begin(), data_.end());
    int shortest = data_[1] - data_[0];
    for (ui i = 2; i < data_.size(); i++) {
        int tshort = data_[i] - data_[i - 1];
        if (tshort < shortest)
            shortest = tshort;
    }
    return (shortest);
}

ui Span::longestSpan(void) const {
    if (data_.size() < 2) {
        throw SpanException("Not enough elements to find a span");
    }
    int min = *std::min_element(data_.begin(), data_.end());
    int max = *std::max_element(data_.begin(), data_.end());
    return max - min;
}

void Span::grow(ui new_capacity) { capacity_ = new_capacity; }

Span::SpanException::SpanException(std::string const &message)
    : message_(message) {}
Span::SpanException::~SpanException(void) throw() {}
char const *Span::SpanException::what(void) const throw() {
    return message_.c_str();
}
