#pragma once

#include "whatever.hpp"
#include "ArrayException.hpp"

typedef unsigned int ui;

template <class T> class Array {
public:
    Array();
    Array(ui len);
    Array(Array const &);
    ~Array();

    Array<T> const &operator=(Array<T> const &);

    T &operator[](unsigned int) throw(ArrayException);
    T const &operator[](unsigned int) const throw(ArrayException);

    ui size(void) const;

private:
    ui capacity_;
    T *data_;

    void swap(Array<T> &);
};

template <class T>
Array<T>::Array(void) : capacity_(0), data_(NULL) {}

template <class T>
Array<T>::Array(ui len) : capacity_(len), data_(new T[capacity_]()) {}

template <class T> Array<T>::~Array(void) { delete[] data_; }

template <class T>
Array<T>::Array(Array<T> const &rhs)
    : capacity_(rhs.capacity_), data_(new T[capacity_]) {
    for (ui i = 0; i < capacity_; i++) {
        data_[i] = rhs.data_[i];
    }
}

template <class T> Array<T> const &Array<T>::operator=(Array<T> const &rhs) {
    if (this != &rhs) {
        Array<T> temp(rhs);
        swap(temp);
    }
    return *this;
}

template <class T> T &Array<T>::operator[](ui index) throw(ArrayException) {
    if (index >= capacity_)
        throw OutOfRange();
    return data_[index];
}

template <class T>
T const &Array<T>::operator[](ui index) const throw(ArrayException) {
    if (index >= capacity_)
        throw OutOfRange();
    return data_[index];
}

template <class T> ui Array<T>::size(void) const { return capacity_; }

template <class T> void Array<T>::swap(Array<T> &o) {
    swap(capacity_, o.capacity_);
    swap(data_, o.data_);
}
