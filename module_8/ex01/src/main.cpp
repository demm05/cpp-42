#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void test_with_rand(ui len) {
    Span sp = Span(len / 2);
    sp.generateNumbers(len, time(0));
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void test_subject() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(11);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main() {
    test_with_rand(10000);
    test_subject();
    Span(10).shortestSpan();
    return 0;
}
