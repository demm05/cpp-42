#include "../inc/PmergeMe.hpp"
#include "../inc/UserInput.hpp"
#include "../inc/utils.hpp"
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

size_t F(int n) {
    size_t sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

template <typename Container> clock_t measureSorting(Container &c) {
    std::cout << "Before: ";
    printContainer(c, 5);

    clock_t begin = clock();
    size_t comparisons = PmergeMe<Container>::sort(c);
    clock_t end = clock();

    std::cout << "After: ";
    printContainer(c, 5);

    std::cout << "Comparisons done: " << comparisons << std::endl;
    if (comparisons > F(c.size()))
        throw std::runtime_error("comparisons exceeded the allowed max");

    return end - begin;
}

template <typename Container> void doForContainer(int argc, char const **argv) {
    Container input = processInput<Container>(argc, argv);
    printTypeName(input);
    clock_t time_spent = measureSorting(input);
    if (!PmergeMe<Container>::isSorted(input)) {
        throw std::runtime_error("the container wasn't sorted");
    }
    std::cout << "Time to process: ";
    printFormattedTime(time_spent);
}

int main(int argc, char const **argv) {
    if (argc < 2) {
        std::cerr << "Please provided arguments to sort" << std::endl;
        return 0;
    }
    try {
        doForContainer<std::vector<int> >(argc, argv);
        std::cout << std::endl;
        doForContainer<std::list<int> >(argc, argv);
    } catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
