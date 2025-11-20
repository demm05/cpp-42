#pragma once

#define PRINT_LIMIT_NUMBERS 5

#include <iostream>
#include <sstream>

template <typename Container>
void processArgument(char const *arg, Container &res) {
    std::istringstream ss(arg);

    typename Container::value_type temp;
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

template <typename Container>
Container processInput(int argc, char const **argv) {
    Container res;
    for (int i = 1; i < argc; i++) {
        processArgument(argv[i], res);
        if (res.empty())
            continue;
    }
    return res;
}

template <typename Container> void printContainer(Container const &c) {
    if (c.empty())
        return;
    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator end = c.end();

    while (it != end) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

template <typename Container>
void printContainer(Container const &c, size_t sideSizeLimit) {
    if (c.empty())
        return;
    typename Container::const_iterator it = c.begin();
    typename Container::const_iterator end = c.end();

    if (c.size() < sideSizeLimit * 2) {
        printContainer(c);
    }

    size_t i = 0;
    while (i < sideSizeLimit && it != end) {
        std::cout << *it << " ";
        ++it;
        i++;
    }
    std::cout << "... ";
    i = 0;
    it = end;
    std::advance(it, -PRINT_LIMIT_NUMBERS);
    while (i < sideSizeLimit && it != end) {
        std::cout << *it << " ";
        ++it;
        i++;
    }
    std::cout << std::endl;
}
