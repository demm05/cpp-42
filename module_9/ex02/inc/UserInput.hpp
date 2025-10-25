#pragma once

#include <vector>
#include <sstream>
#include "PmergeMe.hpp"

template <typename T>
void processArgument(char const *arg, std::vector<T> &res) {
    std::istringstream ss(arg);

    T temp;
    while (!ss.eof() && (ss >> temp)) {
#if !ALLOW_NEGATIVE
        if (temp < 0)
            throw std::runtime_error("Error negative number");
#endif
        res.push_back(temp);
    }
    if (!ss.eof()) {
        throw std::runtime_error("Invalid argument: " + std::string(arg));
    }
}

template <typename T>
std::vector<T> processInput(int argc, char const **argv) {
    std::vector<int> res;
    res.reserve(argc - 1);
    for (int i = 1; i < argc; i++) {
        processArgument(argv[i], res);
        if (res.empty())
            continue;
    }
#if DEBUG
    std::cout << res.front();
    for (size_t j = 1; j < res.size(); j++) {
        std::cout << ", " << res[i];
    }
    std::cout << std::endl;
#endif
    return res;
}
