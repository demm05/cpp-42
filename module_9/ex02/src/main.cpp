#include "../inc/PmergeMe.hpp"
#include "../inc/UserInput.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <time.h>

template <typename Container> bool isSorted(Container const &c) {
    return std::is_sorted(c.begin(), c.end());
}

template <typename Container> clock_t measureSorting(PmergeMe<Container> &pm) {
    clock_t begin = clock();
    size_t comparisons = pm.sort();
    std::cout << "comparisons done: " << comparisons << std::endl;
    clock_t end = clock();
    return end - begin;
}

template <typename Container> void doForContainer(int argc, char const **argv) {
    Container input = processInput<Container>(argc, argv);
    std::cout << "Before: ";
    printContainer(input, 5);
    PmergeMe<Container> pm(input);
    clock_t time_spent = measureSorting(pm);
    if (!isSorted(input)) {
        std::cout << "Error the numbers are not sorted" << std::endl;
    }
    std::cout << "After: ";
    printContainer(input, 5);
    std::cout << "Time to process: " << (double)time_spent / CLOCKS_PER_SEC
              << std::endl;
}

int main(int argc, char const **argv) {
    try {
        // doForContainer<std::vector<size_t> >(argc, argv);
        // std::cout << std::endl;
        doForContainer<std::list<size_t> >(argc, argv);
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
}
