#pragma once
#include <bits/stdc++.h>

template <typename T> typename T::iterator easyfind(T &c, int val) {
    typename T::iterator res = std::find(c.begin(), c.end(), val);
    if (res == c.end()) {
        throw -1;
    }
    return res;
}
