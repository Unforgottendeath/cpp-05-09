#include "Array.hpp"

// Constructors
template <typename T>
Array<T>::Array() : data(nullptr), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n) {
    if (n > 0) {
        data = new T[n]();
    } else {
        data = nullptr;
    }
}

template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_) {
    data = new T[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        data[i] = other.data[i];
    }
}

// Operator overload

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] data;
        size_ = other.size_;
        data = new T[size_];
        for (unsigned int i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}


// Member Functions
template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

// Deconstructor
template <typename T>
Array<T>::~Array() {
    delete[] data;
}