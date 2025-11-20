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

size_t getJacoNum(size_t seed) {
    return (std::pow(2, (seed + 1)) + std::pow(-1, seed)) / 3;
}

std::vector<size_t> makeInsertionsOrder(size_t pair_size, size_t size) {
    std::vector<size_t> res;

    size_t const pairs = size / pair_size;
    if (pairs == 0)
        return res;
    res.reserve(pairs);
    size_t seed = 2;
    size_t i = 0;
    while (i < pairs) {
        size_t jacoNum = getJacoNum(seed);
        size_t pJacoNum = getJacoNum(seed - 1);
        if (jacoNum > pairs)
            jacoNum = pairs + 1;
        if (jacoNum <= pJacoNum)
            break;
        for (; jacoNum > pJacoNum; jacoNum--) {
            res.push_back(jacoNum - 2);
            i++;
        }
        seed++;
    }
    return res;
}

int main(int argc, char const **argv) {
    // std::vector<size_t> insertPairOrder = makeInsertionsOrder(4, 12);
    // {
    //     std::cout << "Inserting order: ";
    //     for (std::vector<size_t>::const_iterator it =
    //     insertPairOrder.begin();
    //          it != insertPairOrder.end(); ++it) {
    //         std::cout << *it << " ";
    //     }
    //     std::cout << std::endl;
    // }
    try {
        doForContainer<std::vector<size_t> >(argc, argv);
        // std::cout << std::endl;
        // doForContainer<std::list<size_t> >(argc, argv);
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
}
