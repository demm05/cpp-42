#pragma once

#include <iostream>
#include <typeinfo>

#ifdef __GNUC__
#include <cxxabi.h>
#include <cstdlib>
#endif

template <typename T>
void printTypeName(const T &) {
    const char *rawName = typeid(T).name();

#ifdef __GNUC__
    int status;
    // abi::__cxa_demangle is the standard way to unmangle names in GCC/Clang
    char *demangled = abi::__cxa_demangle(rawName, 0, 0, &status);

    if (status == 0) {
        std::cout << demangled << std::endl;
        std::free(demangled);
        return;
    }
#endif
    std::cout << rawName << std::endl;
}

void printFormattedTime(clock_t ticks);
