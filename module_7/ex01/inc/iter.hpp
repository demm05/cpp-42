#pragma once

template <typename T> void iter(T *addr, unsigned len, void (*f)(T &)) {
    for (unsigned i = 0; i < len; i++)
        f(addr[i]);
}

template <typename T> void iter(T *addr, unsigned len, void (*f)(T const &)) {
    for (unsigned i = 0; i < len; i++)
        f(addr[i]);
}
