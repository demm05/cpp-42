#pragma once

#include <stack>

template <class T> class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {};
    MutantStack(MutantStack<T> const &rhs) : std::stack<T>(rhs) {};
    ~MutantStack() {};
    MutantStack<T> const &operator=(MutantStack<T> const &rhs) {
        if (this != &rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator
        reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
};
