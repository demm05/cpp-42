#include "../inc/PmergeMe.hpp"
#include "../inc/UserInput.hpp"
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <time.h>

template <typename Container> clock_t measureSorting(PmergeMe<Container> &pm) {
    clock_t begin = clock();
    pm.sort();
    clock_t end = clock();
    return end - begin;
}

template <typename Container> void doForContainer(int argc, char const **argv) {
    Container input = processInput<Container>(argc, argv);
    std::cout << "Before: ";
    printContainer(input, 5);
    PmergeMe<Container> pm(input);
    clock_t time_spent = measureSorting(pm);
    std::cout << "After: ";
    printContainer(input, 5);
}

int main(int argc, char const **argv) {
    try {
        doForContainer<std::vector<size_t> >(argc, argv);
        std::cout << std::endl;
        doForContainer<std::list<size_t> >(argc, argv);
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
}
