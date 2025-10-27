#include "../inc/PmergeMe.hpp"
#include "../inc/UserInput.hpp"
#include <cmath>
#include <cstring>
#include <iostream>

#define DEBUG 1

int depth = 0;

size_t getJacoNum(int n) {
    return (std::pow(2, (n + 1)) + std::pow(-1, n)) / 3;
}

template <typename Iterator, typename T>
Iterator binaryInsert(Iterator begin, Iterator end, T item) {
    while (begin <= end) {
        Iterator mid = begin + (end - begin) / 2;
        if (*mid < item)
            begin = mid + 1;
        else if (*mid > item)
            end = mid - 1;
        else
            return mid;
    }
    return begin;
}

template <typename T> void merge_insert_sort(std::vector<T> &items) {
    depth++;
#if DEBUG
    {
        std::cout << "depth: " << depth << "; input itmes:\t[ ";
        if (!items.empty())
            std::cout << items.front();
        for (size_t i = 1; i < items.size(); i++) {
            std::cout << ", " << items[i];
        }
        std::cout << " ]" << std::endl;
    }
#endif
    if (items.size() <= 1) {
        depth--;
        return;
    }

    bool hasStraggler;
    T straggler;
    if (items.size() % 2) {
        hasStraggler = true;
        straggler = items.back();
        items.pop_back();
        std::cout << "Saving straggler: " << straggler << std::endl;
    }

    std::vector<T> pairs;
    std::vector<T> pend;
    pairs.reserve(items.size() / 2);
    pend.reserve(items.size() / 2);
    for (size_t i = 0; i + 1 < items.size(); i += 2) {
        if (items[i] < items[i + 1]) {
            pairs.push_back(items[i + 1]);
            pend.push_back(items[i]);
        } else {
            pairs.push_back(items[i]);
            pend.push_back(items[i + 1]);
        }
    }
#if DEBUG
    {
        std::cout << "depth: " << depth << "; formed pairs: [ " << pairs[0];
        for (size_t i = 1; i < pairs.size(); i++) {
            std::cout << ", " << pairs[i];
        }
        std::cout << " ]; and pend:\t[";
        if (!pend.empty())
            std::cout << " " << pend.front();
        for (size_t i = 1; i < pend.size(); i++) {
            std::cout << ", " << pend[i];
        }
        std::cout << " ]" << std::endl;
    }
#endif

    merge_insert_sort(pairs);

    pairs.insert(pairs.begin(), pend.front());
    pend.erase(pend.begin());

    if (hasStraggler)
        pend.push_back(straggler);

#if DEBUG
    {
        std::cout << "depth: " << depth << "; pairs after recurrsion:\t[ "
                  << pairs[0];
        for (size_t i = 1; i < pairs.size(); i++) {
            std::cout << ", " << pairs[i];
        }
        std::cout << " ]" << std::endl;
    }
#endif

    if (pend.empty()) {
        std::cerr << "PEND IS EMPTY" << std::endl;
        depth--;
        return;
    }
    std::cout << "depth: " << depth << "; pend:\t[ " << pend[0];
    for (size_t i = 1; i < pend.size(); i++) {
        std::cout << ", " << pend[i];
    }
    std::cout << " ]" << std::endl;

    // items.clear();
    // items.push_back(pend.front());
    // items.insert(items.begin(), pairs.begin(), pairs.end());

    size_t insertion = 1;
    size_t jacoIndex = 1;
    size_t jacoNumber = getJacoNum(jacoIndex);
    size_t insertionsToNextJaco = 0;

    while (pend.size() > 1) {

        // Update jaco index
        if (insertionsToNextJaco <= insertion) {
            jacoIndex++;
            jacoNumber = getJacoNum(jacoIndex);
            insertionsToNextJaco =
                jacoNumber - getJacoNum(jacoIndex - 1) + insertion;
        }

        // size_t start = 0;
        // size_t end = pend.size() - ;
        // std::cout << "Boundary: " << std::endl;
        auto start = pairs.cbegin();

        // Here find the corresponding Ax in pairs
        auto end = pairs.cend();

        size_t index = jacoNumber - insertion - 1;
        T elToInsert = pend[index];
        std::cout << "Inserting: " << elToInsert << std::endl;
        pairs.insert(binaryInsert(start, end, elToInsert), elToInsert);
        pend.erase(pend.begin() + index);
        insertion++;
    }
    if (!pend.empty()) {
        pairs.insert(binaryInsert(pairs.begin(), pairs.end(), pend.back()),
                     pend.back());
    }
    items = pairs;

    depth--;
}

int main(int argc, char const **argv) {
    auto res = processInput<int>(argc, argv);
    std::cout << res.size() << std::endl;
    merge_insert_sort(res);
    for (size_t i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}
