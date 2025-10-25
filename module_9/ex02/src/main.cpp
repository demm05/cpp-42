#include "../inc/UserInput.hpp"
#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <utility>

// template <typename T>
// std::vector<std::pair<T, T> >
// merge_insert_sort(std::vector<std::pair<T, T> > &input) {
// }

// clang-format off
/*

1) vector<pair<int, int>>
2) vector<pair<pair<int, int>, pair<int, int> > >
3) vector<pair<pair<pair<int, int>, pair<int, int>>, pair<pair<int, int>,pair<int, int>> > >
 * */
// clang-format on

template <typename T>
std::vector<RecursivePair<T> > makePairs(std::vector<T> &input) {
    std::vector<RecursivePair<T> > res;
    res.reserve(input.size() / 2);
    for (size_t i = 0; i < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            res.push_back(RecursivePair(input[i], input[i + 1]));
        } else {
            res.push_back(RecursivePair(input[i + 1], input[i]));
        }
    }
    return res;
}

template <typename T>
void merge_insert_sort(std::vector<RecursivePair<T> > &items) {
    if (items.size() <= 1)
        return;
    std::vector<RecursivePair<RecursivePair<T> > > pairs;
    pairs.reserve(items.size() / 2);
    for (size_t i = 0; i + 1 < items.size(); i += 2) {
        if (items[i] < items[i + 1]) {
            pairs.push_back(RecursivePair(items[i], items[i + 1]));
        } else {
            pairs.push_back(RecursivePair(items[i + 1], items[i]));
        }
    }
    merge_insert_sort(pairs);
    for (size_t i = 1; i < pairs.size(); i++) {
        std::cout << pairs[i];
    }
    std::cout << std::endl;
}

int main(int argc, char const **argv) {
    auto res = processInput<int>(argc, argv);
    bool has_straggler;
    int  straggler;
    if (res.size() % 2) {
        straggler = res.back();
        res.pop_back();
        has_straggler = true;
    }
    auto pairs = makePairs(res);
    // if (pairs.size() > 0)
    //     std::cout << "[" << pairs[0].first << ", " << pairs[0].second << "]";
    // for (size_t i = 1; i < pairs.size(); i++) {
    //     std::cout << " | [" << pairs[i].first << ", " << pairs[i].second <<
    //     "]";
    // }
    // std::cout << std::endl;
    merge_insert_sort(pairs);
}
