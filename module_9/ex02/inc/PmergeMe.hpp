#pragma once

#define ALLOW_NEGATIVE 1
#define DEBUG 0

#include <ostream>

template <typename T>
class RecursivePair {
public:
    T first;
    T second;

    RecursivePair(T const &f, T const &s) : first(f), second(s) {}

    bool operator<(RecursivePair const &rhs) const {
        return second < rhs.second;
    }
    friend std::ostream &operator<<(std::ostream &o, const RecursivePair &mod) {
        o << "[ " << mod.first << ", " << mod.second << "]";
        return o;
    }
};
