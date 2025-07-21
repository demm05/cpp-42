#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
    int r = rand() % 3;
    switch (r) {
    case 0:
        std::cout << "A class is created" << std::endl;
        return new A();
    case 1:
        std::cout << "B class is created" << std::endl;
        return new B();
    default:
        std::cout << "C class is created" << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A class pointer" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B class pointer" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C class pointer" << std::endl;
    else
        std::cout << "Unknown class pointer" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A class reference" << std::endl;
    } catch (...) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B class reference" << std::endl;
        } catch (...) {
            try {
                (void)dynamic_cast<C &>(p);
                std::cout << "C class reference" << std::endl;
            } catch (...) {
                std::cout << "Unknown class reference" << std::endl;
            }
        }
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        Base *p = generate();
        identify(p);
        identify(*p);
        delete p;
        std::cout << "-----------" << std::endl;
    }
    return 0;
}
