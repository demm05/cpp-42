#include "iter.hpp"
#include <iostream>

#define GET_SIZE(x) sizeof((x)) / sizeof((x)[0])

void print(int const &a) { std::cout << a << " "; }
void increment(int &a) { a++; }

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    iter(a, GET_SIZE(a), increment);
    iter(a, GET_SIZE(a), print);
    std::cout << std::endl;
    return 0;
}
