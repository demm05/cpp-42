#include <iostream>
#include <vector>
#include <list>
#include "../inc/PmergeMe.hpp"
#include "../inc/UserInput.hpp"
#include "../inc/utils.hpp"

template <typename Container>
bool isSorted(Container const &c) {
    return std::is_sorted(c.begin(), c.end());
}

template <typename Container>
clock_t measureSorting(Container &c) {
    std::cout << "Before: ";
    printContainer(c, 5);

    clock_t begin = clock();
    size_t  comparisons = PmergeMe<Container>::sort(c);
    clock_t end = clock();

    std::cout << "After: ";
    printContainer(c, 5);
    std::cout << "Comparisons done: " << comparisons << std::endl;

    return end - begin;
}

template <typename Container>
void doForContainer(int argc, char const **argv) {
    Container input = processInput<Container>(argc, argv);
    printTypeName(input);
    clock_t time_spent = measureSorting(input);
    if (!isSorted(input)) {
        std::cout << "Error the numbers are not sorted" << std::endl;
    }
    std::cout << "Time to process: ";
    printFormattedTime(time_spent);
}

int main(int argc, char const **argv) {
    try {
        doForContainer<std::vector<int> >(argc, argv);
        std::cout << std::endl;
        doForContainer<std::list<int> >(argc, argv);
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
}
