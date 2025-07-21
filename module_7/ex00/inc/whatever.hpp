#pragma once

template <typename T> void swap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T> T &min(T &a, T &b) { return (a > b) ? b : a; }

template <typename T> T &max(T &a, T &b) { return (a > b) ? a : b; }
