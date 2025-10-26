#include "../inc/UserInput.hpp"
#include "../inc/PmergeMe.hpp"
#include <iostream>

int depth = 0;

template <typename T>
void merge_insert_sort(std::vector<T> &items) {
    bool has_straggler = 0;
    int  straggler;

    if (items.size() <= 1)
        return;
    depth++;
    if (items.size() % 2) {
        straggler = items.back();
        items.pop_back();
        has_straggler = true;
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
    merge_insert_sort(pairs);
    std::cout << "depth: " << depth << "; main: [ " << pairs[0];
    for (size_t i = 1; i < pairs.size(); i++) {
        std::cout << ", " << pairs[i];
    }
    std::cout << " ]\tpend: [ " << pend[0];
    for (size_t i = 1; i < pend.size(); i++) {
        std::cout << ", " << pend[i];
    }
    std::cout << " ]" << std::endl;
    depth--;
}

int main(int argc, char const **argv) {
    auto res = processInput<int>(argc, argv);
    merge_insert_sort(res);
}
